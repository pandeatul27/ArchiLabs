# adding twice of numbers
lw $t3, 0($s0)
addi $t1,$0,10 
addi $t2,$0,20
add $t1,$t1,$t1
add $t2,$t2,$t2
add $t3,$t1,$t2
sw $t3, 0($s0)
