# MIPS assembly code
         add $s0, $0, $0  
         add $s1, $0, $0  
         addi $t0, $0, 10  
loop:slt $t1, $s0, $t0  
         beq $t1, $0, done  
         add $s1, $s1, $s0  
         addi $s0, $s0, 1  
        j loop
done:
