/* Program that converts a binary number to decimal */
.text
.global _start
_start:
MOV R2,#0
LDR R4, =N
ADD R5, R4, #4 // R5 points to the decimal digits storage location
LDR R4, [R4] // R4 holds N
MOV R0, R4 // parameter for DIVIDE goes in R0
BL DIVIDE1000
STRB R2, [R5, #3]
MOV R2, #0

BL DIVIDE100
STRB R2, [R5, #2]
MOV R2, #0

BL DIVIDE10
STRB R2, [R5, #1]
STRB R0, [R5]

END: B END
DIVIDE1000:
CONT1: CMP R0, #1000
BLT DIV_END
SUB R0, #1000
ADD R2, #1
B CONT1

DIVIDE100:
CONT2: CMP R0, #100
BLT DIV_END
SUB R0, #100
ADD R2, #1
B CONT2

DIVIDE10:
CONT3: CMP R0, #10
BLT DIV_END
SUB R0, #10
ADD R2, #1
B CONT3

DIV_END: MOV R1, R2 // return quotient in R1 (remainder is in R0)
BX LR
N: .word 7643 // the decimal number to be converted
Digits: .space 100 // storage space for the decimal digits
.end