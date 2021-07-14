# int sum(int a, int b, int c, int d) {
#     return a + b + sub(c, d);
# }

# int sub(int a, int b) {
#     return a-b;
# }

# void main() {
#     int a = 5, b = 10, c = 30, d = 20;   
#     printf("%d", sum(a, b, c, d));  
# }

.data

.text
main:
    addi $a0, $zero, 5                  # passa os valores para os argumentos
    addi $a1, $zero, 10                 #
    addi $a2, $zero, 30                 #
    addi $a3, $zero, 20                 #

    jal F_SUM

    j OUTPUT

    F_SUB:
        addi $sp, $sp, -4               # espaco para a subtracao
        sw  $s0, 0($sp)                 # aloca a subtracao

        sub $s0, $a2, $a3               # faz a subtracao

        add $v0, $s0, $zero             # coloca a subtracao em $v0

        addi $sp, $sp, 4                # remove da stack

        jr $ra                          # retorna para F_SUM

    F_SUM:
        addi $sp, $sp, -8               # espaco para a soma e a $ra da main
        sw $ra, 4($sp)                  # aloca o retorno para a main

        add $s0, $a0, $a1               # faz a soma de a + b

        sw $s0, 0($sp)                  # aloca soma de a + b

        jal F_SUB                       # faz a subtracao de c - d

        lw $s0, 0($sp)                  # restaura o valor da soma de a + b
        lw $ra, 4($sp)                  # restaura ra
        add $v1, $v0, $s0               # coloca a + b + (c - d) no retorno $v1

        addi $sp, $sp, 8                # remove da stack

        jr $ra                          # volta para a main

    OUTPUT:
        add $t0, $zero, $v1

        addi $v0, $zero, 1              # Printa resultado
        add $a0, $zero, $t0             #
        syscall                         #

    addi $v0, $zero, 10                 # Sai do programa
    syscall                             #