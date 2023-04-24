.data
   str1: .asciiz "Number is positive"
   str2: .asciiz "Number is negative" 

.text
addi $s0,$0,7 

bgt $s0,$0, label
li $v0,4
la $a0,str2
syscall

j done

label:
li $v0,4
la $a0,str1
syscall

done:
