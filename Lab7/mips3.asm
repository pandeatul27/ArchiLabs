addi $s0,$0,1 #pow
addi $s1,$0,0 #x
addi $t0,$0,128

while: 
beq $s0,$t0,done
add $s1,$s1,1
sll $s0,$s0,1
j while

done:

li $v0 ,1
move $a0,$s1
syscall