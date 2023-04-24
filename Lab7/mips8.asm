addi $s0,$0,2
addi $s1,$0,3
addi $s2,$0,4
addi $s3,$0,5
addi $s4,$0,0

main:
jal diffofsum
add $s4,$v0,$0

 li $v0 ,1
move $a0,$s4
syscall

li $v0,10
syscall

diffofsum:
add $t1,$s0,$s1
add $t2,$s2,$s3
sub $t0,$t1,$t2
add $v0,$t0,$0
jr $ra