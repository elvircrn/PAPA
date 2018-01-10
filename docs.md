## PORTS

### Sample Usage
```
PORTBbits.RB0
```
### TRIS
I/O

### ANSEL
0/1 corresponds to digital/analog


## EEPROM

### EEPGD 
Determines if the access will be a program or data memory access. When clear, any subsequent operations will operate on the EEPROM memory. When set, any subsequent operations will operate on the program memory. On Reset, EEPROM is selected by default.

### CFGS: Flash Program/Data EEPROM or Configuration Select bit
1 = Accesses Configuration, User ID and Device ID Registers
0 = Accesses Flash Program or data EEPROM Memory

### WREN: Program/Erase Enable bit
1 = Allows program/erase cycles
0 = Inhibits programming/erasing of program Flash and data EEPROM

### WR: Write Control bit
1 = Initiates a program Flash or data EEPROM program/erase operation.  The operation is self-timed and the bit is cleared by hardware once operation is complete.  The WR bit can only be set (not cleared) in software.
0 = Program/erase operation to the Flash or data EEPROM is complete and inactive.

### RD: Read Control bit
1 = Initiates an program Flash or data EEPROM read. Read takes one cycle. RD is cleared in
hardware. The RD bit can only be set (not cleared) in software.
0 = Does not initiate a program Flash or data EEPROM data read.  

### EEIF
Interrupt flag bit EEIF of the PIR2 register is set when
write is complete. It must be cleared in the software.

## Example
Writing 4 bytes to locations starting at 0x17

```
char vrijednost[] = {0xBB, 0xC3, 0x0A, 0xFF};
char k, addr = 0x17;
EEPGD = 0;
CFGS = 0;
GIE = 0;
EECON1bits.WREN = 1;
for (k = 0; k < 4; k++) {
  EEADRL = addr++;
  EEDATL = vrijednost[k];
  EECON2 = 0x55; // Mandatory sequence for write op
  EECON2 = 0xAA;
  EECON1bits.WR = 1;
  while(!EEIF);
  EEIF = 0;
}
```

## Analog conversion

## Flags

## Setup

### ADCON1bits.ADFM
0 left align
1 right align

### ADCON1bits.ADCS[0,2]
Internal RC oscilator. Set all three to 1.

### ADCON0bits.ADON
1 turn on ad conversion

### ADCON0bits.CHS[0..4]
Channel select.

## Conversion

1. ADCON0bits.ADGO = 1
2. Wait for ADGO to clear
3. Result is stored in ADRESH and ADRESL


## Interrupts

## Setup

## TMR0

How set TMR0 to 1s

### TMR0CS - Source of timer
Set to 0

### PSA
1 - disable prescaler
0 - enable prescaler

### INTCONbits.GIE

### OPTION_REGbits.PS[0..2]


