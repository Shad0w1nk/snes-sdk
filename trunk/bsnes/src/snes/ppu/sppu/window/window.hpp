class Window {
public:
  sPPU &self;

  struct {
    unsigned x;
  } t;

  struct {
    bool bg1_one_enable;
    bool bg1_one_invert;
    bool bg1_two_enable;
    bool bg1_two_invert;

    bool bg2_one_enable;
    bool bg2_one_invert;
    bool bg2_two_enable;
    bool bg2_two_invert;

    bool bg3_one_enable;
    bool bg3_one_invert;
    bool bg3_two_enable;
    bool bg3_two_invert;

    bool bg4_one_enable;
    bool bg4_one_invert;
    bool bg4_two_enable;
    bool bg4_two_invert;

    bool oam_one_enable;
    bool oam_one_invert;
    bool oam_two_enable;
    bool oam_two_invert;

    bool col_one_enable;
    bool col_one_invert;
    bool col_two_enable;
    bool col_two_invert;

    uint8 one_left;
    uint8 one_right;
    uint8 two_left;
    uint8 two_right;

    uint8 bg1_mask;
    uint8 bg2_mask;
    uint8 bg3_mask;
    uint8 bg4_mask;
    uint8 oam_mask;
    uint8 col_mask;

    bool bg1_main_enable;
    bool bg1_sub_enable;
    bool bg2_main_enable;
    bool bg2_sub_enable;
    bool bg3_main_enable;
    bool bg3_sub_enable;
    bool bg4_main_enable;
    bool bg4_sub_enable;
    bool oam_main_enable;
    bool oam_sub_enable;

    uint8 col_main_mask;
    uint8 col_sub_mask;
  } regs;

  struct {
    struct {
      bool color_enable;
    } main, sub;
  } output;

  void scanline();
  void run();
  void reset();

  void serialize(serializer&);
  Window(sPPU &self);

private:
  void test(
    bool &main, bool &sub,
    bool one_enable, bool one_invert,
    bool two_enable, bool two_invert,
    uint8 mask, bool main_enable, bool sub_enable
  );
};
