.data
    array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.text
main:
    la $a0, array               # load address -> carrega o endereço do vetor
    li $a1, 10                  # load immediate -> recebe o tamanho do vetor (10)

    #j OUTPUT

    move $t0, $zero             # i = 0

    slt $t3, $t0, $a1           # if (i < size), $t3 = 1
    bne $t3, $zero, WHILE       # if ($t3 == 0) vai para o while

    WHILE:
        sll $t1, $t0, 2         # shift left 2 -> desloca dois bits para a esquerda (multiplica por 4) ($t1 = i*4)
        add $t2, $t1, $a0       # desloca a 

        sw $zero, 0($t2)        # vetor[i] = 0

        addi $t0, $t0, 1        # i++

        slt $t3, $t0, $a1           # if (i < size), $t3 = 1
        bne $t3, $zero, WHILE       # if ($t3 == 0) vai para o while

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