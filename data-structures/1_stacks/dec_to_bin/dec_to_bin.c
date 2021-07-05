#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



/*
 *  Inicio funções para a pilha estática
 */

#define STATIC_SIZE 32

typedef struct {
    int array[STATIC_SIZE];
    int top;
} StaticStack;

void staticInit(StaticStack *stack) {
    stack->top = 0;
}

bool isEmptyStatic(StaticStack *stack) {
    return stack->top == 0;
}

bool isFullStatic(StaticStack *stack) {
    return stack->top == STATIC_SIZE;
}

int staticPop(StaticStack *stack) {
    int ret = -99;

    if(!isEmptyStatic(stack)) {
        ret = stack->array[stack->top - 1];
        stack->top--;
    } else
        printf("Nao e possivel excluir -> pilha vazia\n");

    return ret;
}

int staticSize(StaticStack *stack) {
    return stack->top;
}

void staticWriteToFile(StaticStack *stack, FILE *file) {
    int size = staticSize(stack);
    for(int i = 0; i < size; i++) {
        fprintf(file, "%d", staticPop(stack));
    }
    fprintf(file, "\n");
}

void staticPush(StaticStack *stack, int x) {
    if(!isFullStatic(stack)) {
        stack->array[stack->top] = x;
        stack->top++;
    } else
        printf("Nao e possivel inserir -> pilha cheia\n");
}

/*
 *  Fim funções para a pilha estática
 */



/*
 *  Inicio funções para a pilha dinâmica
 */

typedef struct StackNode *StackNodePtr;

typedef struct StackNode {
    int x;
    StackNodePtr next;
} StackNode;

typedef struct {
    StackNodePtr top;
    int size;
} DynamicStack;

void destroy(DynamicStack *stack) {
    printf("Destruindo a pilha\n");
    StackNodePtr aux;
    while(stack->top != NULL) {
        aux = stack->top;
        stack->top = stack->top->next;
        free(aux);
    }
    stack->size = 0;
}

void dynamicInit(DynamicStack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmptyDynamic(DynamicStack *stack) {
    return stack->size == 0;
}

int dynamicPop(DynamicStack *stack) {
    int ret = -99;

    if(!isEmptyDynamic(stack)) {
        StackNodePtr aux = stack->top;
        ret = aux->x;
        stack->top = stack->top->next;
        free(aux);
        stack->size--;
    } else
        printf("Nao e possivel excluir -> pilha esta vazia\n");

    return ret;
}

void dynamicPush(DynamicStack *stack, int x) { // Talvez precisa ser modificado
    StackNodePtr aux;
    aux = (StackNodePtr)malloc(sizeof(StackNode));
    aux->x = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

int dynamicSize(DynamicStack *stack) {
    return stack->size;
}

void dynamicWriteToFile(DynamicStack *stack, FILE *file) {
    int size = dynamicSize(stack);
    for(int i = 0; i < size; i++) {
        fprintf(file, "%d", dynamicPop(stack));
    }
    fprintf(file, "\n");
}

/*
 *  Fim funções para a pilha dinâmica
 */



/*
 *  Começo funções auxiliares
 */

int countLines(FILE *file) {
    int lines = 0;
    char current, previous;

    current = fgetc(file);
    while (current != EOF) {
        if (current == '\n' && previous != '\n')
            lines++;
        previous = current;
        current = fgetc(file);
    }

    if (previous != '\n')
        lines++;

    rewind(file);

    return lines;
}

bool isInt(char *string) {
    for(int i = 0; i < 11; i++) {
        if(string[i] == '\0')
            break;
        if(string[i] < 48 || string[i] > 57)
            return false;
    }

    return true;
}

bool fillDecimalStaticStack(int lines, FILE *file, StaticStack *input_integers) {
    // qnt de digitos de 2^32 + \0
    char line[11] = "";

    for(int i = 0; i < lines; i++) {
        fgets(line, 10, file);
        line[strcspn(line, "\r")] = '\0';
        line[strcspn(line, "\n")] = '\0';
        
        if(i == 0)
            continue;

        if(!isInt(line))
            return false;
        else
            staticPush(input_integers, atoi(line));
    }

    return true;
}

bool fillDecimalDynamicStack(int lines, FILE *file, DynamicStack *input_integers) {
    // qnt de digitos de 2^32 + \0
    char line[11] = "";

    for(int i = 0; i < lines; i++) {
        fgets(line, 10, file);
        line[strcspn(line, "\r")] = '\0';
        line[strcspn(line, "\n")] = '\0';
        
        if(i == 0)
            continue;

        if(!isInt(line))
            return false;
        else
            dynamicPush(input_integers, atoi(line));
    }

    return true;
}

void dynamicDecToBin(int dec, DynamicStack *bin, FILE *file) {
    if(dec == 0)
        dynamicPush(bin, 0);

    while(dec != 0) {
        if(dec % 2 == 1)
            dynamicPush(bin, 1);
        else
            dynamicPush(bin, 0);
        
        dec /= 2;
    }

    dynamicWriteToFile(bin, file);
}

void staticDecToBin(int dec, StaticStack *bin, FILE *file) {
    if(dec == 0)
    staticPush(bin, 0);

    while(dec != 0) {
        if(dec % 2 == 1)
            staticPush(bin, 1);
        else
            staticPush(bin, 0);
        
        dec /= 2;
    }

    staticWriteToFile(bin, file);
}

/*
 *  Fim funções auxiliares
 */



int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Nao foram fornecidos todos os parametros [nome_do_programa entrada.txt saida.txt]\n");
        //exit(1);
    }

    FILE *input = fopen("./input/valido.txt", "r");  //  arrumar
    //FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("./output/valido.txt", "w");   // arrumar
    //FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int lines = countLines(input);

    if(lines == 0 || lines == 1) {
        printf("Arquivo invalido! [arquivo vazio e/ou sem numeros]\n");
        fclose(input);
        fprintf(output, "Arquivo invalido!");
        fclose(output);
        exit(2);
    }

    char identifier = fgetc(input);
    rewind(input);
    if(identifier != 'e' && identifier != 'd') {
        printf("Arquivo invalido! [identificador]\n");
        fclose(input);
        fprintf(output, "Arquivo invalido!");
        fclose(output);
        exit(2);
    }

    if(identifier == 'e') {
        StaticStack input_integers;
        staticInit(&input_integers);

        if(!fillDecimalStaticStack(lines, input, &input_integers)) {
            printf("Arquivo invalido! [numeros invalidos]\n");
            fclose(input);
            fprintf(output, "Arquivo invalido!");
            fclose(output);
            exit(2);
        }

        StaticStack output_binary;
        staticInit(&output_binary);
        while(staticSize(&input_integers) != 0)
            staticDecToBin(staticPop(&input_integers), &output_binary, output);
    } else if(identifier == 'd') {
        DynamicStack input_integers;
        dynamicInit(&input_integers);

        if(!fillDecimalDynamicStack(lines, input, &input_integers)) {
            printf("Arquivo invalido! [numeros invalidos]\n");
            fclose(input);
            fprintf(output, "Arquivo invalido!");
            fclose(output);
            destroy(&input_integers);
            exit(2);
        }

        DynamicStack output_binary;
        while(dynamicSize(&input_integers) != 0) {
            dynamicInit(&output_binary);
            dynamicDecToBin(dynamicPop(&input_integers), &output_binary, output);
            destroy(&output_binary);
        }
    }

    return 0;
}