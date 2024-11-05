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

// RotaryEncoder::RotaryEncoder(){}

bool ignoring_clk;
long int position;
unsigned long bounce_delay = 75;
unsigned long debounce_delay_start = 0;

void RotaryEncoder::init()
{
  gpio_set_dir(CLK, GPIO_IN);
  gpio_set_dir(DAT, GPIO_IN);
  gpio_set_dir(BUTTON, GPIO_IN);

  // gpio_set_irq_enabled(CLK,);
  gpio_set_pulls(CLK, true, false);
  gpio_set_pulls(DAT, true, false);
  // gpio_set_pulls(BUTTON,true,false);

  position = 0;
  ignoring_clk = false;
  bounce_delay = 75;
  debounce_delay_start = 0;
}

void RotaryEncoder::run()
{
  // wait for knob debounce and listen to CLK if debounce complete
  if (ignoring_clk and (msSinceBoot() > debounce_delay_start + bounce_delay))
  {
    ignoring_clk = false;
  }

  // display position if button pushed
  if (gpio_get(BUTTON) != true)
  {
    printf("%d \n", position);
  }
}

void RotaryEncoder::RotateStateChanged() // When CLK  FALLING READ DAT
{
  if (!ignoring_clk)
  {
    if (gpio_get(DAT)) // When DAT = HIGH IS FORWARD rotate
    {
      position++;
      // printf("U \n");
    }
    else // When DAT = LOW IS Backwards Rotate
    {
      position--;
      // printf("D \n");
    }
    ignoring_clk = true;
    debounce_delay_start = msSinceBoot();
  }
}
