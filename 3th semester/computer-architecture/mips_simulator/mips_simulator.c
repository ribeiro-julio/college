/*
 * 
 * Emulador MIPS
 * 
 * Autores: 
 *     Julio Cesar Garcia Ribeiro - RA: 1994484
 *     Victor Hugo Rizzo Moura - RA: 2104652
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "operations.h"

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Parametros fornecidos sao invalidos -> [nome_do_programa arquivo_entrada.bin arquivo_saida_op.txt arquivo_saida_reg.txt]");
        exit(1);
    }

    FILE *input;
    input = fopen(argv[1], "r+b");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }

    FILE *output_op;
    output_op = fopen(argv[2], "w");
    if(output_op == NULL) {
        printf("Erro ao gerar o arquivo de saida\n");
        exit(2);
    }

    FILE *output_reg;
    output_reg = fopen(argv[3], "w");
    if(output_reg == NULL) {
        printf("Erro ao gerar o arquivo de saida\n");
        exit(2);
    }

    int get_ops = 0;
    fseek(input, 0, SEEK_END);
    get_ops = ftell(input) / sizeof(uint32_t);
    rewind(input);
    uint32_t instructions[get_ops];
    fread(instructions, sizeof(uint32_t), get_ops, input);

    int a = 0x12345678;
    unsigned char *c = (unsigned char*) (&a);
    bool little_endian = false;
    if (*c == 0x78) little_endian = true;
    else little_endian = false;

    if (little_endian) {
        uint32_t ic;
        for (int i = 0; i < get_ops; i++) {
            ic = instructions[i];
            instructions[i] = ((ic & 0xFF000000) >> 24 | (ic & 0x00FF0000) >> 8 | (ic & 0x0000FF00) << 8 |  (ic & 0x000000FF) << 24 );
        }
    }

    int stack[RAM_SIZE];
    for(int i = 0; i < RAM_SIZE; i++) {
        stack[i] = 0;
    }

    char string_data[RAM_SIZE];     // Vetor para salvar strings
    for(int i = 0; i < RAM_SIZE; i++) {
        string_data[i] = 0;
    }

    int registers[34];  // (indice = código do registrador; conteúdo salvo na posiçao)
    for(int i = 0; i < 34; i++) {
        registers[i] = 0;
    }
    registers[29] = RAM_SIZE;

    int pc = 0;
    int aux;
    int opt;
    char aux_char;

    printf ("\nSimulador MIPS\n");
    do {
        printf ("1 - Rodar o programa inteiro\n2 - Rodar passo a passo\nSua escolha: ");
        scanf ("%d", &opt);
        fflush(stdin);
        printf ("\n");
        if (opt != 1 && opt != 2) printf ("Opcao invalida, tente novamente\n");
    } while (opt != 1 && opt != 2);

    int pc_aux = -1;
    do {
        if (opt == 1) { }
        else {
            printf ("Precione Enter para compilar a proxima instrucao:");
            scanf ("%c", &aux_char);
            fflush(stdin);
            printf ("\n");
        }

        uint8_t opcode = (instructions[pc] & 4227858432) >> 26;

        if(opcode == 0) {   // r-type instruction
            uint8_t rs = (instructions[pc] & 65011712) >> 21;
            uint8_t rt = (instructions[pc] & 2031616) >> 16;
            uint8_t rd = (instructions[pc] & 63488) >> 11;
            uint8_t shamt = (instructions[pc] & 1984) >> 6;
            uint8_t funct = instructions[pc] & 63;
            switch(funct) {
                case 32:    // add
                add(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: add %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if (opt == 2) {
                    printf("$pc = %d\nOperacao: add %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 33:    // addu
                addu(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: addu %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if (opt == 2) {
                    printf("$pc = %d\nOperacao: addu %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 34:    // sub
                sub(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: sub %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if (opt == 2) {
                    printf("$pc = %d\nOperacao: sub %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 24:    // mult
                mult (rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: mult %d, %d\n", pc, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador LO: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", registers[32], registers[33], rs, registers[rs], rt, registers[rt]);
                if (opt == 2) {
                    printf("$pc = %d\nOperacao: mult %d, %d\n", pc, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador LO: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", registers[32], registers[33], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 26:    // div
                divv (rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: div %d, %d\n", pc, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador LO: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", registers[32], registers[33], rs, registers[rs], rt, registers[rt]);
                if (opt == 2) {
                    printf("$pc = %d\nOperacao: div %d, %d\n", pc, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador LO: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", registers[32], registers[33], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 36:    // and
                and(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: and %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if(opt == 2){
                    printf("$pc = %d\nOperacao: and %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 37:    // or
                or(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: or %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if(opt == 2) {
                    printf("$pc = %d\nOperacao: or %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 38:    // xor
                xor(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: xor %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if(opt == 2){
                    printf("$pc = %d\nOperacao: xor %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 39:    // nor
                nor(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: nor %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: nor %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 42:    // slt
                slt(rd, rs, rt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: slt %d, %d, %d\n", pc, rd, rs, rt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: slt %d, %d, %d\n", pc, rd, rs, rt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rs, registers[rs], rt, registers[rt]);
                }
                break;

                case 0:    // sll
                sll (rd, rt, shamt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: sll %d, %d, %d\n", pc, rd, rt, shamt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: sll %d, %d, %d\n", pc, rd, rt, shamt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                }
                break;

                case 2:    // srl
                srl (rd, rt, shamt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: srl %d, %d, %d\n", pc, rd, rt, shamt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: srl %d, %d, %d\n", pc, rd, rt, shamt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                }
                break;

                case 3:    // sra
                sra (rd, rt, shamt, registers);
                fprintf(output_op, "$pc = %d\nOperacao: sra %d, %d, %d\n", pc, rd, rt, shamt);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: sra %d, %d, %d\n", pc, rd, rt, shamt);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rd, registers[rd], rt, registers[rt]);
                }
                break;

                case 12:    // syscall -> falta colocar uma condiçao de v0 != de 1 ou v0 != 10 (só implementei pros dois casos, nao vai fazer nada caso v0 seja diferente desses valores)
                fprintf(output_op, "$pc = %d\nOperacao: syscall\n", pc);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador 2: %d\n  Registrador 4: %d\n\n", registers[2], registers[4]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: syscall\n", pc);
                    printf("Conteudo dos registradores:\n  Registrador 2: %d\n  Registrador 4: %d\n\n", registers[2], registers[4]);
                }
                pc_aux = pc;
                pc = syscall(pc, registers, string_data);
                break;

                case 8:    // jr
                fprintf(output_op, "$pc = %d\nOperacao: jr %d\n", pc, rs);
                if(opt==2) printf("$pc = %d\nOperacao: jr %d\n", pc, rs);
                aux = jr(rs, registers);
                if(aux < get_ops && aux >= 0) {
                    pc = aux;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 16:    // mfhi
                mfhi (rd, registers);
                fprintf(output_op, "$pc = %d\nOperacao: mfhi %d\n", pc, rd);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador %d: %d\n\n", registers[32], rd, registers[rd]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: mfhi %d\n", pc, rd);
                    printf("Conteudo dos registradores:\n  Registrador HI: %d\n  Registrador %d: %d\n\n", registers[32], rd, registers[rd]);
                }
                break;

                case 18:    // mflo
                mflo (rd, registers);
                fprintf(output_op, "$pc = %d\nOperacao: mflo %d\n", pc, rd);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador LO: %d\n  Registrador %d: %d\n\n", registers[33], rd, registers[rd]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: mflo %d\n", pc, rd);
                    printf("Conteudo dos registradores:\n  Registrador LO: %d\n  Registrador %d: %d\n\n", registers[33], rd, registers[rd]);
                }
                break;

                default:
                    fprintf(output_op, "Instruçao invalida\n\n");
                    if(opt==2) printf("Instruçao invalida\n\n");
                    break;
            }

        } else if(opcode == 2 || opcode == 3) {   // j-type instruction
            uint32_t target = instructions[pc] & 67108863;

            switch(opcode) {
                case 2:     // j
                fprintf(output_op, "$pc = %d\nOperacao: j 0x%08x\n", pc, target);
                if(opt==2) printf("$pc = %d\nOperacao: j 0x%08x\n", pc, target);
                aux = j(target);
                if(aux < get_ops && aux >= 0) {
                    pc = aux - 1;
                    fprintf(output_op, "Conteudo dos registradores:\n  Novo $pc: %d\n\n", pc + 1);
                    if(opt==2) printf("Conteudo dos registradores:\n  Novo $pc: %d\n\n", pc + 1);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 3:     // jal
                fprintf(output_op, "$pc = %d\nOperacao: jal 0x%08x\n", pc, target);
                if(opt==2) printf("$pc = %d\nOperacao: jal 0x%08x\n", pc, target);
                aux = jal(pc, target, registers);
                if(aux < get_ops && aux >= 0) {
                    pc = aux - 1;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador 31: %d\n  Novo $pc: %d\n\n", registers[31], pc + 1);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador 31: %d\n  Novo $pc: %d\n\n", registers[31], pc + 1);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                default:
                    fprintf(output_op, "Instruçao invalida\n\n");
                    if(opt==2) printf("Instruçao invalida\n\n");
                    break;
            }

        } else {    // i-type instruction
            uint8_t rs = (instructions[pc] & 65011712) >> 21;
            uint8_t rt = (instructions[pc] & 2031616) >> 16;
            int16_t immediate = instructions[pc] & 65535;

            switch(opcode) {
                case 4:     // beq
                fprintf(output_op, "$pc = %d\nOperacao: beq %d, %d, %d\n", pc, rs, rt, immediate);
                if(opt==2) printf("$pc = %d\nOperacao: beq %d, %d, %d\n", pc, rs, rt, immediate);
                aux = beq(pc, rs, rt, immediate, registers);
                if(aux < get_ops && aux >= 0) {
                    pc = aux;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], rt, registers[rt], pc);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], rt, registers[rt], pc);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 5:     // bne
                fprintf(output_op, "$pc = %d\nOperacao: bne %d, %d, %d\n", pc, rs, rt, immediate);
                if(opt==2) printf("$pc = %d\nOperacao: bne %d, %d, %d\n", pc, rs, rt, immediate);
                aux = bne(pc, rs, rt, immediate, registers);
                if(aux < get_ops || aux >= 0) {
                    pc = aux;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], rt, registers[rt], pc);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], rt, registers[rt], pc);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 6:     // blez
                fprintf(output_op, "$pc = %d\nOperacao: blez %d, %d\n", pc, rs, immediate);
                if(opt==2) printf("$pc = %d\nOperacao: blez %d, %d\n", pc, rs, immediate);
                aux = blez(pc, rs, immediate, registers);
                if(aux < get_ops || aux >= 0) {
                    pc = aux;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 7:     // bgtz
                fprintf(output_op, "$pc = %d\nOperacao: blez %d, %d\n", pc, rs, immediate);
                if(opt==2) printf("$pc = %d\nOperacao: blez %d, %d\n", pc, rs, immediate);
                aux = bgtz(pc, rs, immediate, registers);
                if(aux < get_ops || aux >= 0) {
                    pc = aux;
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Novo $pc: %d\n\n", rs, registers[rs], pc);
                }
                else {
                    fprintf(output_op, "Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    if(opt==2) printf("Nao foi possivel realizar o salto -> valor de $pc fora do escopo\n");
                    exit(3);
                }
                break;

                case 8:     // addi
                addi(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: addi %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: addi %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 9:     // addiu
                addiu(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: addiu %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: addiu %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 10:     // slti
                slti(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: slti %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: slti %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 11:     // sltiu
                sltiu(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: sltu %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: sltu %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 12:     // andi
                andi(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: andi %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: andi %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 13:     // ori
                ori(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: ori %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: ori %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 14:     // xori
                xori(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: xori %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: xori %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 15:     // lui
                lui(rt, rs, immediate, registers);
                fprintf(output_op, "$pc = %d\nOperacao: lui %d, %d, %d\n", pc, rt, rs, immediate);
                fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                if(opt==2){
                    printf("$pc = %d\nOperacao: lui %d, %d, %d\n", pc, rt, rs, immediate);
                    printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                }
                break;

                case 32:    // lb
                fprintf(output_op, "$pc = %d\nOperacao: lb %d, %d(%d)\n", pc, rt, immediate, rs);
                if(opt==2) printf("$pc = %d\nOperacao: lb %d, %d(%d)\n", pc, rt, immediate, rs);
                if(lb(rt, immediate, rs, registers, stack)) {
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                } else {
                    fprintf(output_op, "Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    if(opt==2) printf("Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    exit(3);
                }
                break;

                case 35:    // lw
                fprintf(output_op, "$pc = %d\nOperacao: lw %d, %d(%d)\n", pc, rt, immediate, rs);
                if(opt==2) printf("$pc = %d\nOperacao: lw %d, %d(%d)\n", pc, rt, immediate, rs);
                if(lw(rt, immediate, rs, registers, stack)) {
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                } else {
                    fprintf(output_op, "Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    if(opt==2) printf("Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    exit(3);
                }
                break;

                case 36:    // lbu
                fprintf(output_op, "$pc = %d\nOperacao: lbu %d, %d(%d)\n", pc, rt, immediate, rs);
                if(opt==2) printf("$pc = %d\nOperacao: lbu %d, %d(%d)\n", pc, rt, immediate, rs);
                if(lbu(rt, immediate, rs, registers, stack)) {
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                    if(opt==2) printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                } else {
                    fprintf(output_op, "Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    if(opt==2) printf("Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    exit(3);
                }
                break;

                case 40:    // sb
                fprintf(output_op, "$pc = %d\nOperacao: sb %d, %d(%d)\n", pc, rt, immediate, rs);
                if(opt==2) printf("$pc = %d\nOperacao: sb %d, %d(%d)\n", pc, rt, immediate, rs);
                if(sb(rt, immediate, rs, registers, stack)) {
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                    fprintf(output_op, "Conteudo da memoria:\n  RAM[%d]: %d\n\n", registers[rs] + immediate / 4, stack[immediate / 4 + registers[rs]]);
                    if(opt==2) {
                        printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n\n", rt, registers[rt], rs, registers[rs]);
                        printf("Conteudo da memoria:\n  RAM[%d]: %d\n\n", registers[rs] + immediate / 4, stack[immediate / 4 + registers[rs]]);
                    }
                } else {
                    fprintf(output_op, "Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    if(opt==2) printf("Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    exit(3);
                }
                break;

                case 43:    // sw
                fprintf(output_op, "$pc = %d\nOperacao: sw %d, %d(%d)\n", pc, rt, immediate, rs);
                if(opt==2) printf("$pc = %d\nOperacao: sw %d, %d(%d)\n", pc, rt, immediate, rs);
                if(sw(rt, immediate, rs, registers, stack)) {
                    fprintf(output_op, "Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n", rt, registers[rt], rs, registers[rs]);
                    fprintf(output_op, "Conteudo da memoria:\n  RAM[%d]: %d\n\n", registers[rs] + immediate / 4, stack[immediate / 4 + registers[rs]]);
                    if(opt==2) {
                        printf("Conteudo dos registradores:\n  Registrador %d: %d\n  Registrador %d: %d\n", rt, registers[rt], rs, registers[rs]);
                        printf("Conteudo da memoria:\n  RAM[%d]: %d\n\n",  registers[rs] + immediate / 4, stack[immediate / 4 + registers[rs]]);
                    }
                } else {
                    fprintf(output_op, "Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    if(opt==2) printf("Erro ao realizar a operacao -> Nao foi reservado espaço na memoria\n");
                    exit(3);
                }
                break;

                default:
                    fprintf(output_op, "Instruçao invalida\n\n");
                    if(opt==2) printf("Instruçao invalida\n\n");
                    break;
            }
        }
        pc++;
    } while (pc < get_ops);

    if (pc == RAM_SIZE + 1) pc = pc_aux;
    else pc--;
    printf("Finalizado!\nO arquivo com todas as instrucoes realizadas, bem como o arquivo com o estado final de cada registrador\nfoi gerado no diretorio do programa\n");

    fprintf (output_reg, "Nome\t\tNumero\t\tValor\n\n"
                         "$zero\t\t0\t\t%d\n"
                         "$at\t\t1\t\t%d\n"
                         "$v0\t\t2\t\t%d\n"
                         "$v1\t\t3\t\t%d\n"
                         "$a0\t\t4\t\t%d\n"
                         "$a1\t\t5\t\t%d\n"
                         "$a2\t\t6\t\t%d\n"
                         "$a3\t\t7\t\t%d\n"
                         "$t0\t\t8\t\t%d\n"
                         "$t1\t\t9\t\t%d\n"
                         "$t2\t\t10\t\t%d\n"
                         "$t3\t\t11\t\t%d\n"
                         "$t4\t\t12\t\t%d\n"
                         "$t5\t\t13\t\t%d\n"
                         "$t6\t\t14\t\t%d\n"
                         "$t7\t\t15\t\t%d\n"
                         "$s0\t\t16\t\t%d\n"
                         "$s1\t\t17\t\t%d\n"
                         "$s2\t\t18\t\t%d\n"
                         "$s3\t\t19\t\t%d\n"
                         "$s4\t\t20\t\t%d\n"
                         "$s5\t\t21\t\t%d\n"
                         "$s6\t\t22\t\t%d\n"
                         "$s7\t\t23\t\t%d\n"
                         "$t8\t\t24\t\t%d\n"
                         "$t9\t\t25\t\t%d\n"
                         "$k0\t\t26\t\t%d\n"
                         "$k1\t\t27\t\t%d\n"
                         "$gp\t\t28\t\t%d\n"
                         "$sp\t\t29\t\t%d\n"
                         "$fp\t\t30\t\t%d\n"
                         "$ra\t\t31\t\t%d\n"
                         "pc\t\t\t\t%d\n"
                         "hi\t\t\t\t%d\n"
                         "lo\t\t\t\t%d\n",
                         registers[0], registers[1], registers[2], registers[3],
                         registers[4], registers[5], registers[6], registers[7],
                         registers[8], registers[9], registers[10], registers[11],
                         registers[12], registers[13], registers[14], registers[15],
                         registers[16], registers[17], registers[18], registers[19],
                         registers[20], registers[21], registers[22], registers[23],
                         registers[24], registers[25], registers[26], registers[27],
                         registers[28], registers[29], registers[30], registers[31],
                         pc, registers[32], registers[33]);

    fclose(input);
    fclose(output_op);
    fclose(output_reg);
    return 0;
}
