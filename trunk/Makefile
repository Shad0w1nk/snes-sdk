BSNES=1
PREFIX = /usr/local/snes-sdk
_OS = $(shell uname -s)

SUBDIRS = wla_dx wla_dx/wlalink wla_dx/wlab tcc-65816 libs
ifeq ($(BSNES),1)
SUBDIRS += bsnes/src
endif

all: $(SUBDIRS)

.PHONY: dummy $(SUBDIRS)
libs wla_dx wla_dx/wlalink wla_dx/wlab: dummy
	cd $@ && $(MAKE) PREFIX=$(PREFIX)
bsnes/src: dummy
	mkdir -p bsnes/src/obj
	cd $@ && $(MAKE) ui=ui_sdl

tcc-65816: tcc-65816/config.h
	@cd $@ && $(MAKE) 816-tcc

tcc-65816/config.h: Makefile
	cd tcc-65816 && ./configure --prefix=$(PREFIX) --enable-cross

libs: wla_dx

clean:
	(for i in $(SUBDIRS) ; do $(MAKE) -C $$i clean || true ; done)

distclean: clean
	cd snesc && $(MAKE) clean

install:
	mkdir -p $(DESTDIR)$(PREFIX)
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -p libs/*.obj $(DESTDIR)$(PREFIX)/lib/
	cp -p libs/hdr.asm $(DESTDIR)$(PREFIX)/include/
	cp -p tcc-65816/include/* $(DESTDIR)$(PREFIX)/include/
	cp -p tcc-65816/816-tcc $(DESTDIR)$(PREFIX)/bin/
	install -m 755 tcc-65816/816-opt.py $(DESTDIR)$(PREFIX)/bin/816-opt
	cp -p wla_dx/wla-65816 $(DESTDIR)$(PREFIX)/bin/
	cp -p wla_dx/wlalink/wlalink $(DESTDIR)$(PREFIX)/bin/
	cp -p wla_dx/wlab/wlab $(DESTDIR)$(PREFIX)/bin/
ifeq ($(BSNES),1)
	cp -p bsnes/bsnes $(DESTDIR)$(PREFIX)/bin/
endif
