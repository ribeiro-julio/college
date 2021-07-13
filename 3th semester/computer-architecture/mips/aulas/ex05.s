# | 100 | -> 0
# | 200 | -> 4
# | 300 | -> 8
# | 400 | -> 12
# | 500 | -> 16

.data
    newline: .asciiz "\n"
    array:
        .align 2
        .space 16

.text
main:
    add $t0, $zero, $zero
    addi $t1, $zero, 100
    sw $t1, array($t0)

    addi $t0, $zero, 4
    addi $t1, $zero, 200
    sw $t1, array($t0)

    addi $t0, $zero, 8
    addi $t1, $zero, 300
    sw $t1, array($t0)

    addi $t0, $zero, 12
    addi $t1, $zero, 400
    sw $t1, array($t0)

    addi $t0, $zero, 16
    addi $t1, $zero, 500
    sw $t1, array($t0)


    addi $t0, $zero, 8          # a
    lw $t1, array($t0)          #
    addi $t1, $t1, 50           #
    sw $t1, array($t0)          #


    addi $t0, $zero, 4          # b
    lw $t1, array($t0)          #
    addi $t0, $zero, 12         #
    lw $t2, array($t0)          #
    sw $t1, array($t0)          #
    addi $t0, $zero, 4          #
    sw $t2, array($t0)          #


    add $t0, $zero, $zero
    lw $t1, array($t0)
    add $t0, $zero, 4
    lw $t2, array($t0)
    add $t0, $zero, 8
    lw $t3, array($t0)
    add $t0, $zero, 12
    lw $t4, array($t0)
    add $t0, $zero, 16
    lw $t5, array($t0)

    addi $v0, $zero, 1
    add $a0, $zero, $t1
    syscall

    addi $v0, $zero, 4
    la $a0, newline
    syscall
    
    addi $v0, $zero, 1
    add $a0, $zero, $t2
    syscall

    addi $v0, $zero, 4
    la $a0, newline
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t3
    syscall

    addi $v0, $zero, 4
    la $a0, newline
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t4
    syscall

    addi $v0, $zero, 4
    la $a0, newline
    syscall

    addi $v0, $zero, 1
    add $a0, $zero, $t5
    syscall

    addi $v0, $zero, 10         # Sai do programa
    syscall                     #