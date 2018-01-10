/*
INPUTS:
N1 switch, upper level
N2 switch, lower level
LM35DZ, temperature sensor 
T_1 switch
T_2 switch

OUTPUTS:
V_1, valve
P_1, pumps
P_2, pumps
*/

// Inputs
#define N1 PORTCbits.RC0
#define N2 PORTCbits.RC1
#define Temp PORTBbits.RB0
#define T1 PORTCbits.RC2
#define T2 PORTCbits.RC3

// Outputs
#define V1 PORTCbits.RC4
#define P1 PORTCbits.RC5
#define P2 PORTCbits.RC6

char getTemp() {
  ADCON0bits.ADGO = 1;
  while (ADCON0bits.ADGO);
  return ADRESH;
}

void init_ports() {
  TRISC  = 0xF;
  TRISB  = 1;
  ANSELB = 1;
}

void init_ad_conversion() {
  ADCON1bits.ADFM = 0;
  ADCON1bits.ADCS0 = 1;
  ADCON1bits.ADCS1 = 1;
  ADCON1bits.ADCS2 = 1;
  ADCON0bits.CHS0 = 0;
  ADCON0bits.CHS1 = 0;
  ADCON0bits.CHS2 = 0;
  ADCON0bits.CHS3 = 0;
  ADCON0bits.ADON = 1;
}

void init_interrupt() {
  
}

void interrupt handler() {

}

void main() {
  init_ports();
  init_ad_conversion();
  init_interrupt();
  return;
}

