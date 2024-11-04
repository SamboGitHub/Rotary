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
#include "hardware/interp.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "pico/cyw43_arch.h"
#include "hardware/uart.h"

#include "include/global.h"
#include "include/rotary_encoder.h"

// RotaryEncoder::RotaryEncoder(){}

void RotaryEncoder::run()
{
  if  (gpio_get(BUTTON) != true)
    {

    //  printf("%lu Button\n", millis());
    printf("%d \n", rotary_encoder_pos);

   }
}
