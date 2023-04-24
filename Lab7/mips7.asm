addi $s0,$0,0
addi $s1,$0,3
addi $s2,$0,6

main:
jal simple
add $s0,$s1,$s2

 li $v0 ,1
move $a0,$s0
syscall

li $v0,10
syscall

simple:
jr $ra
