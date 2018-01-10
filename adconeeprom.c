


char getValue() {
  ADCON0bits.ADGO=1;
  while (ADCON0bits.ADGO);
  return ADRESH;
}

void init_eeprom() {
  CFGS = 0;
  EEPGD = 0;
  EECON1bits.WREN=1; 
}

char cnt = 0, addr = 0;
void interrupt handler() {
  if (TMR0IF && TMR0IE) {
    if (cnt++ == 38) { 
      char value = getValue(); 
      GIE = 0;
      EECOND1bits.WREN = 1;
      EEADRL = addr;
      EEDATL = value;
      EECON2 = 0x55;
      EECON2 = 0xAA;
      EECON1bits.WR = 1;
      while(!EEIF);
      EEIF = 0; 
      addr = (addr + 1) % 256;
      cnt = 0; 
      GIE = 1;
    }
  } 
}

void initialize_analog() {
  TRISA=0xFF; // Nije neophodno, posto je to defaultna vrijednost
  ANSELA=0x01;
  PORTA=0;
  LATA=0;
  // Lijevo poravnanje
  ADCON1bits.ADFM=0;
  // Interni RC oscilator za ADC
  ADCON1bits.ADCS2=1;
  ADCON1bits.ADCS1=1;
  ADCON1bits.ADCS0=1;
  // Vss za Vref-, Vdd za Vref+
  ADCON1bits.ADNREF=0;
  ADCON1bits.ADPREF1=0;
  ADCON1bits.ADPREF0=0;

  // Ukljucivanje ADC
  ADCON0bits.ADON=1;

  // Izbor AN0
  ADCON0bits.CHS4=0;
  ADCON0bits.CHS3=0;
  ADCON0bits.CHS2=0;
  ADCON0bits.CHS1=0;
  ADCON0bits.CHS0=0;
}

void initialize() {
  TRISB = 1;
  ANSELB = 1;
  OPTION_REG = 7;
  TMR0IF = 0;
  TMR0IE = 1;
  GIE = 1;
}


void main(void) {
  initialize();
  init_eeprom();
  initialize_analog();
}
