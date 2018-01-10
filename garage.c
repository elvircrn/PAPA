#define T  PORTBbits.RB0
#define P1 PORTBbits.RB1
#define P2 PORTBbits.RB2

enum State { S0, S1, S2, S3, S4, S5 } state;
enum Trans { ZERO, ONE, P1, P2 } trans; 


void initialize() {
  INTF = 0;	// Reset the external interrupt flag
  INTE = 1;	// Enable external interrupts from RB0 
  GIE = 1;
}

void interrupt handler() {
  trans = Trans.ZERO;
  // RB0 pressed
  if (INTE && INTF) {
    
  }

  // TMR0 interrupt
  if (TMR0IE && TMR0IF) {
    TMR0IF = 0;
    if (P1) {
    }
    else if (P2) {
    }
  }
}


void main() {
  current_state = States.S0;



}


