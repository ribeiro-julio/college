.data
    array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.text
main:
    la $a0, array               # load address -> carrega o endereço do vetor
    li $a1, 10                  # load immediate -> recebe o tamanho do vetor (10)

    j OUTPUT

    move $t0, $a0              # p = endereco do array

    sll $t1, $a1, 2
    add $t2, $a0, $t1           # calcula o utlimo endereço do array

    WHILE:
        sw $zero, 0($t0)            # array na posicao do ponteiro recebe 0

        addi $t0, $t0, 4            # ponteiro desloca 4 bytes (p = p + 1)

        slt $t3, $t0, $t2           # ve se o elemento é menor que o utlimo do array
        bne $t3, $zero, WHILE

        OUTPUT:
            add $t2, $a0, $zero         # $t2 recebe a referencia de array
            addi $t4, $zero, 1          # $t4 = indice

            add $t5, $t2, $zero         # $t5 variavel auxiliar para receber a referencia de array
            add $t6, $zero, $zero       # $t6 variavel auxiliar para receber o indice atualizado
        
        PRINT:
            slti $s1, $t4, 10
            beq $s1, $zero, EXIT

            lw $a0, 0($t5)
            li $v0, 1
            syscall

            addi $t4, $t4, 1
            sll $t6, $t4, 2
            add $t5, $t2, $t6

            j PRINT

        EXIT:
            li $v0, 10
            syscall