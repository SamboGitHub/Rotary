#ifndef GLOBAL_H_MARK
#define GLOBAL_H_MARK 1



// extern  unsigned char rig_address;
// extern  unsigned char my_address;

extern int rotary_encoder_pos;
extern int LED;

extern unsigned int CLK;     // PIN
extern unsigned int  DAT;     // PIN
extern unsigned int BUTTON;  // PIN
extern unsigned int interruptA;

extern void RotateStateChanged();

extern bool not_ignoring_clk;

unsigned long msSinceBoot();

extern unsigned long debounce_delay_start;

// unsigned int bcd_decimal(unsigned char hex[1]);
// unsigned int BCDtoDEC(unsigned char const* nybbles, int length);

#endif