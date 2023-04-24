#Name->atul
# a->97->61
# t->116->74
# u->117->75
# l->108->6c

# data segment 0x100100
#lui $s0,0x1000
#ori $s0,$s0,0
addi $s0,$0,256
# for 'a'

addi $t0,$t0,0x61
sw $t0,0($s0)
add $t0,$0,$0

# for 't'
addi $t0,$t0,0x74
sw $t0,1($s0)
add $t0,$0,$0

# for 'u'
addi $t0,$t0,0x75
sw $t0,2($s0)
add $t0,$0,$0

# for 'l'
addi $t0,$t0,0x6c
sw $t0,3($s0)
add $t0,$0,$0

#for storing sum of ascii values of letters of name
addi $s1,$s1,0
# for storing number of letters
addi $t0,$t0,4 
addi $t3,$0,0

addi $s0,$0,256

for: beq $t3,$t0,done
lw $t4,0($s0)
add $s1,$s1,$t4
addi $s0,$s0,1
addi $t3,$t3,1
beq $0,$0,for
done:

li $v0,10
syscall


