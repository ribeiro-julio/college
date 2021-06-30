# int a = 2;
# int b = 10;
# int x = 0;
# if (a >= 0 && b <= 50)
#     x = 1;
# printf("%i", x);

.data

.text
main:
    addi $t0, $zero, 2          # a = 2
    addi $t1, $zero, 10         # b = 10
    add $t2, $zero, $zero       # x = 0
    
    addi $t3, $zero, 1          # registrador auxiliar

    slt $s0, $t0, $zero         # if(a < 0) $s0 = 1
    bne $s0, $zero, OUTPUT      # if($s0 != 0) vai para o print

    slti $s0, $t1, 50           # if(b < 50) $s0 = 1
    beq $s0, $t3, IF            # if($s0 == 1) entra no if

    addi $t3, $zero, 50         # atualiza o registrador auxiliar
    beq $t1, $t3, IF            # if(b == 50) entra no if

    j OUTPUT                    # se não entrar no if, pula para o print

    IF:
        addi $t2, $zero, 1      # atualiza x se entrar no if (x = 1) 
    
    OUTPUT:
        addi $v0, $zero, 1      # printf("%i", x)
        add $a0, $zero, $t2     # 
        syscall                 #
    
    addi $v0, $zero, 10         # Sai do programa
    syscall                     #