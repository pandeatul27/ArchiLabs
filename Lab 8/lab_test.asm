addi $t0,$0,3
addi $t1,$0,2
addi $t2,$0,0
addi $t3,$0,0
for: 
beq $t1,$t2,done
add $t3,$t3,$t0
sub $t1,$t1,1
j for

done: