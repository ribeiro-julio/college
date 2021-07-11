# Falta arrumar

# | 500 | -> 16
# | 400 | -> 12
# | 300 | -> 8
# | 200 | -> 4
# | 100 | -> 0

.data

.text
main:
    addi $t0, $zero, 100
    sw $t0, 0($s0)
    addi $t0, $zero, 200
    sw $t0, 4($s0)
    addi $t0, $zero, 300
    sw $t0, 8($s0)
    addi $t0, $zero, 400
    sw $t0, 12($s0)
    addi $t0, $zero, 500
    sw $t0, 16($s0)

    lw $t0, 8($s0)          # a
    addi $t0, $t0, 50       #
    sw $t0, 8($s0)          #

    lw $t0, 4($s0)          # b
    lw $t1, 16($s0)         #
    sw $t0, 16($s0)         #
    sw $t1, 4($s0)          #

    lw $t0, 0($s0)
    lw $t1, 4($s0)
    lw $t2, 8($s0)
    lw $t3, 12($s0)
    lw $t4, 16($s0)

    addi $v0, $zero, 1
    add $a0, $zero, $t0
    syscall
    
    addi $v0, $zero, 1
    add $a0, $zero, $t1
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t2
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t3
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t4
    syscall

    addi $v0, $zero, 10         # Sai do programa
    syscall                     #