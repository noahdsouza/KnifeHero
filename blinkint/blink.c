/*
** Copyright (c) 2018, Bradley A. Minch
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
#include "elecanisms.h"

// void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
//     IFS0bits.T1IF = 0;      // lower Timer1 interrupt flag
//
//     LED2 = !LED2;           // toggle LED2
// }

int16_t main(void) {
    init_elecanisms();

    // T1CON = 0x0030;         // set Timer1 period to 0.5s
    // PR1 = 0x7A11;
    //
    // TMR1 = 0;               // set Timer1 count to 0
    // IFS0bits.T1IF = 0;      // lower Timer1 interrupt flag
    // IEC0bits.T1IE = 1;      // enable Timer1 interrupt
    // T1CONbits.TON = 1;      // turn on Timer1
    //
    // LED2 = ON;

    // while (1) {
    //     LED1 = (D0 == 1) ? OFF : ON;   // turn LED1 on if SW2 is pressed
    //     LED3 = (SW3 == 0) ? ON : OFF;   // turn LED3 on if SW3 is pressed
    // }
    // LED1 = 0;
    // LED2 = 0;
    // LED3 = 0;
    ANSB = 0;
    D0_DIR = OUT;
    D0 = 1;
    D1_DIR = OUT;
    D1 = 1;
    D2_DIR = OUT;
    D2 = 1;
    D3_DIR = OUT;
    D3 = 1;
    D4_DIR = OUT;
    D4 = 1;
    D5_DIR = OUT;
    D5 = 1;

    while (1) {
      if (A0==1) {
        D0 = 0;
      } else {
        D0 = 1;
      }
      if (A1==1) {
        D1 = 0;
      } else {
        D1 = 1;
      }
      if (A2==1) {
        D2 = 0;
      } else {
        D2 = 1;
      }
      if (A3==1) {
        D3 = 0;
      } else {
        D3 = 1;
      }
      if (A4==1) {
        D4 = 0;
      } else {
        D4 = 1;
      }
      if (D11==1) {
        D5 = 0;
      } else {
        D5 = 1;
      }
      // if (A0==0 && A1==0 && A2==0 && A3==0 && A4==0) {
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 1;
      //   D4 = 1;
      // }
      // if (A0==1 && A1==0 && A2==0 && A3==0 && A4==0) {
      //   D0 = 0;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 1;
      //   D4 = 1;
      // }
      // if (A0==0 && A1==1 && A2==0 && A3==0 && A4==0) {
      //   D0 = 1;
      //   D1 = 0;
      //   D2 = 1;
      //   D3 = 1;
      //   D4 = 1;
      // }
      // if (A0==0 && A1==0 && A2==1 && A3==0 && A4==0) {
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 0;
      //   D3 = 1;
      //   D4 = 1;
      // }
      // if (A0==0 && A1==0 && A2==0 && A3==1 && A4==0) {
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 0;
      //   D4 = 1;
      // }
      // if (A0==0 && A1==0 && A2==0 && A3==0 && A4==1) {
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 1;
      //   D4 = 0;
      // }
      // if (SW2==0 && SW3==0) {
      //   D0 = 1;
      //   D1 = 0;
      //   D2 = 0;
      //   D3 = 0;
      //   D4 = 1;
      // } else if (SW2==0 && SW3==1){
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 0;
      //   D3 = 0;
      //   D4 = 0;
      // } else if (SW2==1 && SW3==0){
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 0;
      //   D4 = 0;
      // } else if (SW2==1 && SW3==1){
      //   D0 = 1;
      //   D1 = 1;
      //   D2 = 1;
      //   D3 = 1;
      //   D4 = 0;
      // }
    }

}











// sad
