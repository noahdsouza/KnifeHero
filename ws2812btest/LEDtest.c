/*
** Copyright (c) 2020, Vincent Ingrid C. Punie
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
**     1. Redistributions of source code must retain the above copyright
**        notice, this list of conditions and the following disclaimer.
**     2. Redistributions in binary form must reproduce the above copyright
**        notice, this list of conditions and the following disclaimer in the
**        documentation and/or other materials provided with the distribution.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
*/

//Cylcone LED Arcade Game

#include "ws2812b.h"
#include "elecanisms.h"


#define NUM_LEDS      50

//Define the array of leds
uint8_t red[NUM_LEDS], green[NUM_LEDS], blue[NUM_LEDS];     //Three different arrays for every color

// HELPERS??
void write_leds(void) {
  uint16_t i;
  disable_interrupts();
  for(i = 0; i < NUM_LEDS; i++) {
    ws2812b_write(red[i], green[i], blue[i]);
  }
  enable_interrupts();
}

void clear_leds(void) {
  uint16_t i;
  disable_interrupts();
  for(i = 0; i < NUM_LEDS; i++) {
    ws2812b_write(red[0], green[0], blue[0]);
  }
  enable_interrupts();
}

////MAIN FUNCTION////
int16_t main(void)  {
  init_elecanisms();
  // D0_OD = 1;        //Open drain data pin

  T1CON = 0x0030;         // set Timer1 period to 0.5s
  PR1 = 0x7A11;
  TMR1 = 0;               // set Timer1 count to 0
  IFS0bits.T1IF = 0;      // lower Timer1 interrupt flag
  T1CONbits.TON = 1;      // turn on Timer1

  D0 = 1;
  init_ws2812b();

  D10_DIR = OUT;
  D10 = 1;

  LED2 = ON;

  uint16_t i;

  // for(i = 0; i < NUM_LEDS; i++) {
  //   red[i] = 80;
  //   green[i] = 0;
  //   blue[i] = 0;
  // }
  uint16_t n;
  n=0;
  while(1) {
    // clear_leds();
    if (IFS0bits.T1IF == 1) {
      IFS0bits.T1IF = 0;
      if (n==0) {
        for(i = 0; i < NUM_LEDS; i++) {
          red[i] = 80;
          green[i] = 0;
          blue[i] = 0;
        }
        n = 1;
        write_leds();
      } else {
        for(i = 0; i < NUM_LEDS; i++) {
          red[i] = 0;
          green[i] = 0;
          blue[i] = 80;
        }
        n = 0;
        i=0;
        write_leds();
      }
    }
  }
}

// if (SW2 == 0) {
//   red[1] = 80;
//   green[1] = 0;
//   blue[1] = 0;
//   red[2] = 0;
//   green[2] = 80;
//   blue[2] = 0;
//   red[3] = 0;
//   green[3] = 0;
//   blue[3] = 80;
//   write_leds();
//   LED3 = ON;
// }













// sad
