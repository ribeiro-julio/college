main:
	addi $a0, $zero, 5
	jal FACT
	j OUTPUT

FACT:
	addi $sp, $sp, -8       # gera espaço na stack para salvar os registradores necessários
	sw $ra, 4($sp)          # Endereço de retorno da função
	sw $a0, 0($sp)          # Aloca espaço para n
	slti $t0, $a0, 1        # n < 1
	beq $t0, $zero, L1      # se  n >= 1 vai para L1
	addi $v0, $zero, 1      # return 1
	addi $sp, $sp, 8        # Retira 2 itens da stack
	jr $ra                  # Pula para o endereço de retorno

L1:
	addi $a0, $a0, -1
	jal FACT                # chama fact com (n - 1)
	lw $a0, 0($sp)          # restaura n
	lw $ra, 4($sp)          # restaura ra
	addi $sp, $sp, 8        # Retira 2 itens da stack
	mult $a0, $v0           # retorna n * fact(n - 1)
	mflo $v0
	jr $ra                  # retorna para quem chamou (main ou fact)

OUTPUT:
	add $t2, $zero, $v0
	addi $v0, $zero, 1
	add  $a0, $zero, $t2
	syscall
	addi $v0, $zero, 10
	syscall
