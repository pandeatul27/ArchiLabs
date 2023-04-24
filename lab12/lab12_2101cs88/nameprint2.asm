#Name->atul pande
# a->97->61
# t->116->74
# u->117->75
# l->108->6c
# p->112->70
# n->110->6e
# d->100->64
# e->101->65

addiu $s0,$0,0

# for 'a'
addiu $t0,$0,0x61
sw $t0,0($s0)

# for 't'
addiu $t0,$0,0x74
sw $t0,4($s0)

# for 'u'
addiu $t0,$0,0x75
sw $t0,8($s0)

# for 'l'
addiu $t0,$0,0x6c
sw $t0,12($s0)

# for 'p'
addiu $t0,$0,0x70
sw $t0,16($s0)

# for 'a'
addiu $t0,$0,0x61
sw $t0,20($s0)

# for 'n'
addiu $t0,$0,0x6e
sw $t0,24($s0)

# for 'd'
addiu $t0,$0,0x64
sw $t0,28($s0)

# for 'e'
addiu $t0,$0,0x65
sw $t0,32($s0)


