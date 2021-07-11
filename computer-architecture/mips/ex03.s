# int i = 0;
# int j = 10;
# int k = 0;
# while (i < j) {
#     i++;
#     k += 10;
# }
# printf("%i", i);
# printf("%i", k);

.data

.text
main:
    add $t0, $zero, $zero       # i = 0
    addi $t1, $zero, 10         # j = 10
    add $t2, $zero, $zero       # k = 0

    WHILE:
        slt $s0, $t0, $t1
        beq $s0, $zero, OUTPUT
        addi $t0, $t0, 1
        addi $t3, $t3, 10
        j WHILE
    
    OUTPUT:
        addi $v0, $zero, 1
        add $a0, $zero, $t0
        syscall

        addi $v0, $zero, 1      # printf("%i", k)
        add $a0, $zero, $t3     #
        syscall

    addi $v0, $zero, 10         # Sai do programa
    syscall