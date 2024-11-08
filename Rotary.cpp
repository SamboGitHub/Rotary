#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/interp.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "pico/cyw43_arch.h"
#include "hardware/uart.h"

#include "include/global.h"
#include "include/rotary_encoder.h"

RotaryEncoder knob1;


// wrapper for code fired by interrupt 
void knob1_callback(uint /*gpio*/, uint32_t /*event_mask*/)
{
    knob1.RotateStateChanged();
}

// provide the call to make when button is pressed
void knob1_button()  
{
 printf("%d \n", knob1.position);
}

int main()
{
    stdio_init_all();

    // set up knob1
    knob1.CLK = 4;
    knob1.DAT = 3;
    knob1.BUTTON = 2;
    knob1.init();
    // set up callback for knob1 when CLK falls
    gpio_set_irq_enabled_with_callback(knob1.CLK, GPIO_IRQ_EDGE_FALL, true, &knob1_callback);
    knob1.button_pointer = &knob1_button;
    
    // end set up knob 1

    sleep_ms(5000);
    printf("woke Up");

    while (true)
    {
        knob1.run();
    }
}
//   void (*funcPtr)(void);

//   // Assign the address of myFunction to the pointer
//   funcPtr = &RotateStateChanged;

//   // Call the function through the pointer
//   // (*funcPtr)();


