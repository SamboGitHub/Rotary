#ifndef ROTARY_ENCODER_H_MARK
#define ROTARY_ENCODER_H_MARK 1

class RotaryEncoder
{
public:
    // RotaryEncoder();
    void run();
    void RotateStateChanged(); // interrupt code that runs when rotary changes
    void init();
    void (*button_pointer)(void); // pointer to code to call when button is pushed
    unsigned int CLK;
    unsigned int DAT;
    unsigned int BUTTON;
    long int position;
    bool ignoring_clk; // debounce flag
    unsigned long bounce_delay;
    unsigned long debounce_delay_start;

private:
};

#endif