
addi $a0,$0,5
addi $a1,$0,7

gcd: beq $a0, $a1, done 
ble $a0, $a1, else 
sub $a0, $a0, $a1
b gcd 
else: sub $a1, $a1, $a0 
b gcd 
done: move $v0, $a0
jr $ra