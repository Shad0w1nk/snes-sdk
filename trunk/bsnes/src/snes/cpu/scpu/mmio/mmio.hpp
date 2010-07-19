void mmio_power();
void mmio_reset();
uint8 mmio_read(unsigned addr);
void mmio_write(unsigned addr, uint8 data);

uint8 pio();
bool joylatch();

uint8 mmio_r2180();
uint8 mmio_r4016();
uint8 mmio_r4017();
uint8 mmio_r4210();
uint8 mmio_r4211();
uint8 mmio_r4212();
uint8 mmio_r4213();
uint8 mmio_r4214();
uint8 mmio_r4215();
uint8 mmio_r4216();
uint8 mmio_r4217();
uint8 mmio_r4218();
uint8 mmio_r4219();
uint8 mmio_r421a();
uint8 mmio_r421b();
uint8 mmio_r421c();
uint8 mmio_r421d();
uint8 mmio_r421e();
uint8 mmio_r421f();
uint8 mmio_r43x0(uint8 i);
uint8 mmio_r43x1(uint8 i);
uint8 mmio_r43x2(uint8 i);
uint8 mmio_r43x3(uint8 i);
uint8 mmio_r43x4(uint8 i);
uint8 mmio_r43x5(uint8 i);
uint8 mmio_r43x6(uint8 i);
uint8 mmio_r43x7(uint8 i);
uint8 mmio_r43x8(uint8 i);
uint8 mmio_r43x9(uint8 i);
uint8 mmio_r43xa(uint8 i);
uint8 mmio_r43xb(uint8 i);

void mmio_w2180(uint8 data);
void mmio_w2181(uint8 data);
void mmio_w2182(uint8 data);
void mmio_w2183(uint8 data);
void mmio_w4016(uint8 data);
void mmio_w4200(uint8 data);
void mmio_w4201(uint8 data);
void mmio_w4202(uint8 data);
void mmio_w4203(uint8 data);
void mmio_w4204(uint8 data);
void mmio_w4205(uint8 data);
void mmio_w4206(uint8 data);
void mmio_w4207(uint8 data);
void mmio_w4208(uint8 data);
void mmio_w4209(uint8 data);
void mmio_w420a(uint8 data);
void mmio_w420b(uint8 data);
void mmio_w420c(uint8 data);
void mmio_w420d(uint8 data);
void mmio_w43x0(uint8 i, uint8 data);
void mmio_w43x1(uint8 i, uint8 data);
void mmio_w43x2(uint8 i, uint8 data);
void mmio_w43x3(uint8 i, uint8 data);
void mmio_w43x4(uint8 i, uint8 data);
void mmio_w43x5(uint8 i, uint8 data);
void mmio_w43x6(uint8 i, uint8 data);
void mmio_w43x7(uint8 i, uint8 data);
void mmio_w43x8(uint8 i, uint8 data);
void mmio_w43x9(uint8 i, uint8 data);
void mmio_w43xa(uint8 i, uint8 data);
void mmio_w43xb(uint8 i, uint8 data);
