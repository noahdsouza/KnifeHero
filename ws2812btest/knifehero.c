/*
something something Brad owns all of this
Love u Brad <3
*/


#include "ws2812b.h"
#include "elecanisms.h"

#define NUM_LEDS 50

typedef void (*STATE_HANDLER_T)(void);

void start(void);
void pad_hit(void);
void glove_hit(void);

STATE_HANDLER_T state, last_state;

// uint16_t counter;
//Three different arrays for every color
uint8_t red[NUM_LEDS], green[NUM_LEDS], blue[NUM_LEDS];

/******************************************************************************/

// LED Helper functions
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

/******************************************************************************/

// Finite State Machine
// beginnning mode
void start(void) {
  if (state != last_state) { // initialize if entering state
    last_state = state;
    for(i = 0; i < NUM_LEDS; i++) {
      red[i] = 80;
      green[i] = 0;
      blue[i] = 80;
    }
    write_leds();
    IFS0bits.T1IF = 0;
    TMR1 = 0;
    T1CONbits.TON = 1;
  }
  // state tasks
  if (SW2 == 0) {
    state = pad_hit;
  }
}

// game mode
void pad_hit(void) {
  if (state != last_state) { // initialize if entering state
    last_state = state;
    for(i = 0; i < NUM_LEDS; i++) {
      red[i] = 0;
      green[i] = 0;
      blue[i] = 120;
    }
    write_leds();
  }
  // state tasks
  if (SW2 == 0) {
    state = start;
  }
  if (A0==1) {
    D1 = 0;
    D10 = 1;
  } else {
    D1 = 1;
    D10 = 0;
  }
  if (A1==1) {
    D2 = 0;
    D10 = 1;
  } else {
    D2 = 1;
    D10 = 0;
  }
  if (A2==1) {
    D3 = 0;
    D10 = 1;
  } else {
    D3 = 1;
    D10 = 0;
  }
  if (A3==1) {
    D4 = 0;
    D10 = 1;
  } else {
    D4 = 1;
    D10 = 0;
  }
  if (A4==1) {
    D5 = 0;
    D10 = 1;
  } else {
    D5 = 1;
    D10 = 0;
  }
  if (D11==1) {
    D6 = 0;
    // D7 = 1;
    state = glove_hit;
  } else {
    D6 = 1;
  }
}

// game over mode
void glove_hit(void) {
  if (state != last_state) { // initialize if entering state
    last_state = state;
    for(i = 0; i < NUM_LEDS; i++) {
      red[i] = 120;
      green[i] = 0;
      blue[i] = 0;
    }
    write_leds();
  }
  // state tasks
  D7 = 1;
}

/******************************************************************************/

// Main function
int16_t main(void) {
    init_elecanisms();

    T1CON = 0x0030;         // set Timer1 period to 0.5s
    PR1 = 0x7A11;
    TMR1 = 0;               // set Timer1 count to 0
    IFS0bits.T1IF = 0;      // lower Timer1 interrupt flag
    T1CONbits.TON = 1;      // turn on Timer1

    D0 = 1;
    init_ws2812b();

    ANSB = 0;
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
    D6_DIR = OUT;
    D6 = 1;
    D7_DIR = OUT;
    D7 = 0;
    D10_DIR = OUT;
    D10 = 0;

    // T1CON = 0x0030;         // set Timer1 period to 0.5s
    // PR1 = 0x7A11;
    //
    // TMR1 = 0;               // set Timer1 count to 0
    // IFS0bits.T1IF = 0;      // lower Timer1 interrupt flag
    //
    // state = green;
    // last_state = (STATE_HANDLER_T)NULL;
    //
    // while (1) {
    //     state();
    // }
}







// sad
