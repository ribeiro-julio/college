# int folha(int g, int h, int i, int j) {
#     int f;
#     f = (g + h) - (i + j);
#     return f;
# }

# int main() {
#     printf("%i", folha(1, 2, 3, 4));
# }

.data

.text
main:
    addi $a0, $zero, 1          # Passa os argumentos: g,
    addi $a1, $zero, 2          # h,
    addi $a2, $zero, 3          # i,
    addi $a3, $zero, 4          # j

    jal FUNC                    # Vai para função e salva a posição do registrador pc para voltar para a main

    j OUTPUT                    # Vai para a saida

    FUNC:
        addi $sp, $sp, -12      # Aumenta a stack em 12 bits para guardar as variáveis necessárias da função
        sw  $t1, 8($sp)         # Aloca as variáveis: para o resultado da primeira soma,
        sw  $t0, 4($sp)         # para o resultado da segunda soma,
        sw  $s0, 0($sp)         # f

        add $t0, $a0, $a1       # g + h
        add $t1, $a2, $a3       # i + j
        sub $s0, $t0, $t1       # (g + h) - (i + j)

        add $v0, $s0, $zero     # coloca o valor da soma no registrador de retorno
        
       #lw  $s0, 0($sp)         # ? -> pra que salvar esses valores?
       #lw  $t0, 4($sp)         # ?
       #lw  $t1, 8($sp)         # ?

        addi  $sp, $sp, 12      # Retira 3 itens da stack

        jr $ra                  # Pula para o regstrador de retorno (main)

    OUTPUT:
        add $t0, $zero, $v0     # passa o retorno da função para $t0 

        addi $v0,$zero, 1       # printa o valor do retorno
        add $a0, $zero, $t0     #
        syscall                 #

    addi $v0, $zero, 10
    syscall

# Registradores de argumento: a0, a1, a2, a3 -> Usados para passar argumentos para funções
# Registradores de retorno de função: v0, v1 ->  Usados para retornar valores para funções e armazenar códigos de syscall