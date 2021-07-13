# AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

# int sum(int n, int acc){
#     if(n > 0)
#         return sum(n - 1, acc + n);
#     else
#         return acc;
# }

.data

.text
main:
    addi $a0, $zero, 3             # n
    addi $a1, $zero, 10            # acc

    jal SUM                        # primeira chamada de SUM

    j OUTPUT                       # vai pra saida

    SUM:
        addi $sp, $sp -12
        sw $ra, 8($sp)
        sw $a0, 4($sp)             # n
        sw $a1, 0($sp)             # acc

        slt $t0, $a0, $zero        # se n < 0, $t0 = 1
        beq $t0, $zero, ELSE       # se $t0 == 0 vai pro else

        add $v0, $a1, $zero        # return acc

        addi $sp, $sp, 12          # Retira 3 itens da stack

        jr $ra

    ELSE:
        addi $a0, $a0, -1          # n-1
        add $a1, $a1, $a0          # acc+n
        jal SUM                    # chama SUM com n-1 e acc+n

        lw $a1, 0($sp)             # restaura acc
        lw $a0, 4($sp)             # restaura n
        lw $ra, 8($sp)             # restaura ra
        addi $sp, $sp, 12          # Retira 3 itens da stack

        #add $v0, $a1, $a0          # retorna n-1
        #add $v0, $a1, $zero        # retorna acc

        jr $ra

    OUTPUT:
        add $t1, $zero, $v0

        addi $v0, $zero, 1
        add  $a0, $zero, $t1
        syscall

    addi $v0, $zero, 10
    syscall