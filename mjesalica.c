int seconds = 0, cnt = 0;
void interrupt handler() {
  // Handle interrupt on RB0
  /*
  if (INTE && INTF) {
    INTF = 0;
  }
  */


  if (TMR0IE && TMR0IF) {
    TMR0IF = 0;
    if (cnt++ == 38) {
      cnt = 0;
      seconds++;
    }
  }
}

void initialization() {
  TRISB=0xE1; // 1110 0001 - T je ulaz, ostalo su izlazi
  ANSELB=0x00;
  LATB=0x00;
  PORTB=0x00;

  // Interrupt config
  INTCONbits.GIE = 1;
  PEIE = 1; 
  TMR0IF = 0; // Not necessary
  TMR0IE = 1;

  // Set this if you want interrupts on portB
  // INTEDG = 1
  
  // Konfigurisanje TIMER0 prekida
  TMR0CS = 0;
  PSA = 0;
  PS0 = 1;
  PS1 = 1;
  PS2 = 1;
}

void main() {
  initialization();
  char prev = 0;
  while (1) {
    if ((PORTD & 1) && !prev) {

      
      // ...
    }
    prev = (PORTD & 1);
  }
}

