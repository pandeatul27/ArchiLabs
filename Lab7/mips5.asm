addi $s0,$0,0 #sum
addi $s1,$0,0 #i
addi $t0,$0,10

for:
beq $s1,$t0,done
add $s0,$s0,$s1
add $s1,$s1,1
j for

done:

li $v0 ,1
move $a0,$s0
syscall