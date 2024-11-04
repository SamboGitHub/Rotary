// // #include <Arduino.h>
// #include <sam.h>
// #include <libprintf.h>
// #include <SPI.h>

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
// #include "hardware/interp.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "pico/cyw43_arch.h"
#include "hardware/uart.h"

#include "include/global.h"
#include "include/rotary_encoder.h"

//

RotaryEncoder knob1;

bool not_ignoring_clk = true;
unsigned long bounce_delay = 10;
unsigned long debounce_delay_start = 0;

enum rotary_encoder_state
{
    s_Idle,
    s_Read,
    s_ButtonPushed,
    s_Interrupt
};

rotary_encoder_state state;
int requested_turn_count;

unsigned int CLK = 4;    // PIN
unsigned int DAT = 3;    // PIN
unsigned int BUTTON = 2; // PIN
// unsigned int interruptA = 4;

// int LED = 13; //led
unsigned long msSinceBoot()
    {
        return to_ms_since_boot(get_absolute_time());
    };

int rotary_encoder_pos;
void RotateStateChanged() // When CLK  FALLING READ DAT
{
    //
    // rotary_encoder_pos = 0;
    // printf("in RotateStateChanged\n");
    //  printf("I \n");
    if (not_ignoring_clk)
    {

        if (gpio_get(DAT)) // When DAT = HIGH IS FORWARD
        {
            rotary_encoder_pos++;
            // printf("RotateStateChanged Up %d \n", rotary_encoder_pos);
            printf("U \n");
            // sleep_ms(20);
        }
        else // When DAT = LOW IS BackRote
        {
            rotary_encoder_pos--;
            // printf("RotateStateChanged Down %d \n", rotary_encoder_pos);
            printf("D \n");
            // sleep_ms(20);
        }
        not_ignoring_clk = true;
        debounce_delay_start = msSinceBoot();
    }
}

void setup()
{
}
typedef void (*gpio_irq_callback_t)(uint gpio, uint32_t event_mask);

void gpio_callback(uint /*gpio*/, uint32_t /*event_mask*/)
{
    // printf("GPIO RISE\n");
    RotateStateChanged();
}

int main()
{
    setup();
    sleep_ms(5000);
    printf("woke Up");

    state = s_Idle;
    requested_turn_count = 200;

    // rotary_encoder_pos = 0;

    gpio_set_dir(CLK, GPIO_IN);
    gpio_set_dir(DAT, GPIO_IN);
    gpio_set_dir(BUTTON, GPIO_IN);

    // gpio_set_irq_enabled(CLK,);
    gpio_set_pulls(CLK, true, false);
    gpio_set_pulls(DAT, true, false);

    // gpio_set_irq_enabled(CLK, GPIO_IRQ_EDGE_FALL, true);
    // gpio_set_irq_callback(RotateStateChanged);
    // if (enabled) irq_set_enabled(IO_IRQ_BANK0, true);
    // Declare a function pointer
    void (*funcPtr)(void);

    // Assign the address of myFunction to the pointer
    funcPtr = &RotateStateChanged;

    // Call the function through the pointer
    // (*funcPtr)();

    gpio_set_irq_enabled_with_callback(CLK, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    // gpio_set_pulls(BUTTON,true,false);

    sleep_ms(2000);
    printf("RotaryEncoder.Initialized\n");
    // printf("digitalPinToInterrupt(CLK) %d\n",digitalPinToInterrupt(CLK));
    // printf("interruptA %d\n",interruptA);

    stdio_init_all();
    state = s_Read;
    sleep_ms(5000);
    printf("waking up\n");

    while (true)
    {
        if (gpio_get(BUTTON) != true)
        {

            //  printf("%lu Button\n", millis());
            printf("%d \n", rotary_encoder_pos);
        }

        if (not_ignoring_clk and (msSinceBoot() > debounce_delay_start + bounce_delay))
        {
            not_ignoring_clk = false;
        }
    }
    // knob1.run();
}
