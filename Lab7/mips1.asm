addi $s0,$0,5 #f
addi $s1,$0,10 #g
addi $s2,$0,7 #h
addi $s3,$0,10 #i
addi $s4,$0,20 #j

bne $s3,$s4, label
add $s0,$s1,$s2 #f=g+h

label:
sub $s0,$s0,$s3 #f=f-i

li $v0 ,1
move $a0,$s0
syscall
