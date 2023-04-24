addiu $t0,$0,0
addiu $t1,$0,100
addiu $t2,$0,1
addiu $t5,$0,4
addiu $t4,$0,0
addiu $s0,$0,0

for:
slt $t3,$t0,$t1
beq $t3,$t4,done
sw $t0,0($s0)
add $s0,$s0,$t5
add $t0,$t0,$t2
beq $0,$0,for

done: