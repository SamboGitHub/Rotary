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

// unsigned long msSinceBoot()
//     {
//         return to_ms_since_boot(get_absolute_time());
//     };


// void RotateStateChanged() //When CLK  FALLING READ DAT
// {
// // 
// // rotary_encoder_pos = 0;
// // printf("in RotateStateChanged\n");
// //  printf("I \n");

//  if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
//    {
//     rotary_encoder_pos++;
//     // printf("RotateStateChanged Up %d \n", rotary_encoder_pos);
//     // printf("U \n");
//     //delay(20);
//    }
//  else                   // When DAT = LOW IS BackRote
//    {
//     rotary_encoder_pos--;
//     // printf("RotateStateChanged Down %d \n", rotary_encoder_pos);
//     //  printf("D \n");
//     //delay(20);
//    }

// digitalWrite(LED,HIGH);
// delay (1000);
// digitalWrite(LED,LOW);
// }




// unsigned int BCDtoDEC(unsigned char const* nybbles, int length)
// {
//     unsigned int result(0);
//     while (length--) {
//         result = result * 100 + (*nybbles >> 4) * 10 + (*nybbles & 15);
//         ++nybbles;
//     }
//     return result;
// }
