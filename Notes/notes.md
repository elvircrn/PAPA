# Useful links

[pcbheaven]("http://www.pcbheaven.com/picpages/How_to_use_our_PIC_Tutorials/")
[PIC ASM tuto]("https://www.bradsprojects.com/pic-assembly-tutorial-1-introduction-to-assembly-programming/")

# Memory

## Registers

### F

Register file address (0x00 to 0x7F)

### W
Working register (accumulator)

### b
Bit address within an 8-bit file register

### k
Literal field, constant data or label

### x
Don't care location (= 0 or 1).
The assembler will generate code with x = 0.  It is the recommended form of use for compatibility with all Microchip software tools.

### d
Destination select; d = 0: store result in W,
d = 1: store result in file register f.
Default is d = 1.

### PC
Program Counter

### TO Time-out bit

### PD Power-down bit

# Instruction Set

## Instruction size: 14-bit words

## Orthogonal instruction set

Instruction set architecture where all instruction types can use all addressing modes. "Orthogonal" in the sense that the instruction type and the addressing mode vary independently. An orthogonal instruction set does not impose a limitation that requires a certain instruction to use a specific register.

## Types of instructions

* Byte-oriented operations
```
 13         7     6
| opcode | d (1) |     f(FILE #)(7) |
```

d = 0 for destination W
d = 1 for destination f
f = 7-bit file register address

* Bit-oriented operations

```
| opcode | b(BIT # | f(FILE #) |
```

b = 3-bit bit address
f = 7-bit file register address

* Literal and control operations

```
| opcode | k(literal) |
```

k = 8-bit immediate value

or

```
| opcode | k(literal) |
```

k = 11-bit immediate value

## bsf
bsf f, b

Function
1 -> f(b)

Example
bsf BSR, BSR0

## movlw
movlw kk | kk -> WREG

## incf
incf LATD,d  <-> (f) + 1
0 <= f <= 127
d:
  0 -> place in W
  1 -> place in f

## movwf
movwf f
(f) <- w

## movf
movf  f, d
0 <= f <= 127
(dest) <- (f)
status: Z
If d is 0, then w <- (f), otherwise (f) <- (f). Useful for testing content of address.

Move content of f to dest

# MPASM Asm

A label is used to represent a line or group of code, or a constant value. It is needed for branching instructions (Example 1-1.) Labels should start in column 1. They may be followed by a colon (:), space, tab or the end of line. Labels must not begin with number.  

# Error file (.err)
The MPASM assembler, by default, generates an error file. This file can be useful when debugging your code. The IDE will display the error information in the Output window.  The format of the messages in the error file is: 

```
    type[number] file line description
```

For example:

```
Error[113] C:\PROG.ASM 7 : Symbol not previously defined (start)
```

