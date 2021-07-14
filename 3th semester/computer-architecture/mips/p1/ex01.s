# int soma(int n) {
#     if (n > 0)
#         return n + soma(n - 1);
#     else
#         return 0;
# }

# void main() {
#       int n = 10;
#       printf("Programa para calcular a soma de 10+9+8+7...0, recursivamente\n\n");
#       printf("A soma é: %d \n\n", soma(n));
# }

.data
    text: .asciiz "Programa para calcular a soma de 10+9+8+7...0, recursivamente\n\n"

.text
main:
    addi $a0, $zero, 10                 # atribui 10 para n (parametro da funcao)

    jal SOMA                            # vai para a função recursiva

    j OUTPUT                            # vai para a saida

    SOMA:
        addi $sp, $sp, -8               # adiciona espaço para a stack
        sw $ra, 4($sp)                  # guarda ra
        sw $a0, 0($sp)                  # guarda n

        slt $t0, $a0, $zero             # if(n < 0), $t0 = 1
        beq $t0, $zero, ELSE            # if($t0 == 0) vai pro else

        add $v0, $zero, $zero           # return 0

        addi $sp, $sp, 8                # remove stack

        jr $ra                          # pula para $ra

    ELSE:
        addi $a0, $a0, -1               # n = n - 1
        jal SOMA                        # soma com n - 1

        lw $a0, 0($sp)                  # carrega n
        lw $ra, 4($sp)                  # carrega ra
        addi $sp, $sp, 8                # remove stack

        add $v0, $a0, $v0               # return n + soma(n - 1)

        jr $ra                          # pula para $ra


    OUTPUT:
        add $t0, $zero, $v0             # Coloca o retorno da função em $t0

        addi $v0, $zero, 4              # Printa texto
        la $a0, text                    #
        syscall                         #

        addi $v0, $zero, 1              # Printa resultado
        add $a0, $zero, $t0             #
        syscall                         #

    addi $v0, $zero, 10                 # Sai do programa
    syscall                             #