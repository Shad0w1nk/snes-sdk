#ifdef SSMP_CPP

void sSMP::add_clocks(unsigned clocks) {
  scheduler.addclocks_smp(clocks);
  #if !defined(DSP_STATE_MACHINE)
  scheduler.sync_smpdsp();
  #else
  while(scheduler.clock.smpdsp < 0) dsp.enter();
  #endif

  //forcefully sync S-SMP to S-CPU in case chips are not communicating
  //sync if S-SMP is more than 24 samples ahead of S-CPU
  if(scheduler.clock.cpusmp > +(768 * 24 * (int64)24000000)) scheduler.sync_smpcpu();
}

void sSMP::cycle_edge() {
  t0.tick();
  t1.tick();
  t2.tick();

  //TEST register S-SMP speed control
  //24 clocks have already been added for this cycle at this point
  switch(status.clock_speed) {
    case 0: break;                       //100% speed
    case 1: add_clocks(24); break;       // 50% speed
    case 2: while(true) add_clocks(24);  //  0% speed -- locks S-SMP
    case 3: add_clocks(24 * 9); break;   // 10% speed
  }
}

template<unsigned frequency>
void sSMP::sSMPTimer<frequency>::tick() {
  //stage 0 increment
  stage0_ticks += smp.status.timer_step;
  if(stage0_ticks < frequency) return;
  stage0_ticks -= frequency;

  //stage 1 increment
  stage1_ticks ^= 1;
  sync_stage1();
}

template<unsigned frequency>
void sSMP::sSMPTimer<frequency>::sync_stage1() {
  bool new_line = stage1_ticks;
  if(smp.status.timers_enabled == false) new_line = false;
  if(smp.status.timers_disabled == true) new_line = false;

  bool old_line = current_line;
  current_line = new_line;
  if(old_line != 1 || new_line != 0) return;  //only pulse on 1->0 transition

  //stage 2 increment
  if(enabled == false) return;
  stage2_ticks++;
  if(stage2_ticks != target) return;

  //stage 3 increment
  stage2_ticks = 0;
  stage3_ticks++;
  stage3_ticks &= 15;
}

#endif
