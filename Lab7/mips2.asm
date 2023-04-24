addi $s0,$0,7 #f
addi $s1,$0,19 #g
addi $s2,$0,8 #h
addi $s3,$0,20 #i
addi $s4,$0,20 #j

bne $s3,$s4, label
add $s0,$s1,$s2 #f=g+h
j done

label:
sub $s0,$s0,$s3 #f=f-i

done:

li $v0 ,1
move $a0,$s0
syscall