.data

.text
main:

    addi $t0, $t0, 5
    addi $t0, $t0, 6
    addi $t0, $t0, 4


    SORT:
        addi $sp, $sp, 8
        sw $t0, 4($sp)                      # i
        sw $t1, 0($sp)                      # j

        addi $t0, $t0, $zero
        slt 


    SWAP:
        addi $sp, $sp, 4
        sw $t0, 0($sp)

    addi $v0, $zero, 10
    syscall