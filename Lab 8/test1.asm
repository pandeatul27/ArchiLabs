#adding two numbers
lw $a0, 0($t0)
addi $s0,$0,10
addi $s1,$0,6 


add $a0,$s0,$s1

sw  $a0, 0($t0)
