# int fat = 0;
# int n = 5;
# for(fat = 1; n > 1; n = n - 1)
#     fat = fat * n;
# printf("%d", fat);

.data

.text
main:
    add $t0, $zero, $zero       # fat = 0
    addi $t1, $zero, 5          # n = 5

    addi $t3, $zero, 1          # registrador auxiliar

    addi $t0, $zero, 1          # faz entrar no for com fat = 1

    FOR:
        slt $s0, $t1, 1         # if(n < 1) $s0 = 1
        bne $s0, $zero, OUTPUT  # if($s0 != 0) vai para a saida (sai do for)

        beq $t1, $t3, OUTPUT    # se chegar fat for igual a 1 vai para a saída

        add $t4, $zero, $t1     # Registradores auxiliares (n e fat)
        add $t5, $zero, $t0     #
    
    MULT:
        addi $t4, $t4, -1       # Subtrai um elemento de n
        beq $t4, $zero, SUB     # se n == 0 acabou a multiplicação
        add $t0, $t0, $t5       # soma a iteração da soma
        j MULT                  # repete

    SUB:
        addi $t1, $t1, -1       # subtrai um valor
        j FOR                   # volta para o for

    OUTPUT:
        addi $v0, $zero, 1      # printf("%i", x)
        add $a0, $zero, $t0     # 
        syscall                 #

    addi $v0, $zero, 10         # Sai do programa
    syscall                     #