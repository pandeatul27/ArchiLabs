li $v0,5
syscall

addi $t0,$0,1
addi $t1,$0,1

jal factorial
move $s0,$a0

li $a0,1
syscall

factorial:
sub $sp,$sp,4;
move $sp,$ra

m: beq $a0,$0,done:
add $v0,$v0,$a0
sub $a0,$a0,1
j m

done:
move $ra,$sp
jr $ra
