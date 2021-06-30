# int a = 3;
# int b = 4;
# int m = 10;
# m = a
# if(b < a)
#     m = b;
# printf("%i", m);

.data

.text
main:
    addi $t0, $zero, 3          # a = 3
    addi $t1, $zero, 4          # b = 4
    addi $t2, $zero, 10         # m = 10
    
    add $t2, $zero, $t0         # m = a

    slt $s1, $t1, $t0           # if(b < a) $s1 = 1
    beq $s1, $zero, OUTPUT      # if($s1 == 0) não muda a variável m

    add $t2, $zero, $t1

    OUTPUT:
        addi $v0, $zero, 1      # printf("%i", m)
        add $a0, $zero, $t2     # 
        syscall                 # 
    
    addi $v0, $zero, 10     # Sai do programa
    syscall                 # 