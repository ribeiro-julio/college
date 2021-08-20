#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/*
 *  Inicio funções binary tree
 */

typedef struct TreeNode *TreeNodePtr;

typedef struct TreeNode {
    char word[100];
    int pages[10];
    TreeNodePtr right;
    TreeNodePtr left;
} TreeNode;

void destroy(TreeNodePtr *tree) {
    if((*tree) != NULL) {
        destroy(&(*tree)->left);
        destroy(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

void init(TreeNodePtr *tree) {
    (*tree) = NULL;
}

bool insert(TreeNodePtr *tree, char word[], int pages[]) {
    if((*tree) == NULL) {
        (*tree) = malloc(sizeof(TreeNode));
        strcpy((*tree)->word, word);
        for(int i = 0; i < 10; i++) {
            (*tree)->pages[i] = pages[i];
        }
        (*tree)->right = (*tree)->left = NULL;
        return true;
    }

    if(strcmp((*tree)->word, word) == 0) {
        printf("Erro ao inserir -> chave ja existente\n");
        return false;
    }

    if(strcmp(word, (*tree)->word) > 0)
        return insert(&(*tree)->right, word, pages);
    else
        return insert(&(*tree)->left, word, pages);
}

/*
 *  Fim funções binary tree
 */


/*
 *  Inicio funções auxiliares
 */

bool fillTree(FILE *file, TreeNodePtr *tree) {
    char first_line[200] = "";
    char buffer[300] = "";
    char *word;
    int page;
    int pages[10];
    int index;

    if(fscanf(file, "<termos:%s", first_line) == 0)      // Salva as palavras do indice em fistLine (primeira linha)
        return false;                       // Se não leu nenhuma palavra o formato do arquivo é inválido
    
    fgetc(file);                                // Pula o \n
    word = strtok(first_line, ",>");            // Separa as palavras e salva em *word

    while(word != NULL) {                      // Enquanto existirem linhas no arquivo
        page = 0;                       // Pagina atual
        index = -1;                      // Indice do vetor de paginas
        for(int i = 0; i < 10; i++)     // Zera os elementos do vetor de paginas
            pages[i] = 0;
        
        while(fgets(buffer, 299, file)) {       // Enquanto existirem linhas no arquivo
            buffer[strcspn(buffer, "\n")] = 0;
            if(strncmp(buffer, "<page:", 6) == 0) {     // Compara o 6 primeiros caracteres do buffer pra ver se pegou a indicação de pagina
                page++;                 // Se for igual, aumenta a pagina
            } else {
                if(strstr(buffer, word)) {      // Ve se a palavra esta contida na linha lida, se sim entra
                    if(page != pages[index])    // Verifica se o indice do vetor de paginas já tem a pagina em que encontrou a palavra
                        index++;                // Se não, aumenta um indice (evita paginas duplicadas no vetor)
                    pages[index] = page;        // Preenche a página no vetor
                }
            }
        }

        if(page == 0)           // Se o numero de paginas continua zerado, o formato do arquivo é inválido (não mostra qual página)
            return false;

        index = 0;      // Quando termina de ler o arquivo 
        rewind(file);   // Retorna para o inicio do arquivo
        fgets(buffer, 299, file);       // Pula a primeira linha do arquivo

        insert(tree, word, pages);      // Insere na arvore

        word = strtok(NULL, ",>");      // Vai pra proxima palavra do indice
    }
    
    return true;
}

void writeOutput(FILE *file, TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;

    writeOutput(file, &(*tree)->left);

    fprintf(file, "%s", (*tree)->word);
    for(int i = 0; i < 10; i++) {
        if((*tree)->pages[i] == 0)
            break;
        else
            fprintf(file, ",%d", (*tree)->pages[i]);
    }
    fprintf(file, "\n");

    writeOutput(file, &(*tree)->right);
}

/*
 *  Fim funções auxiliares
 */


int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade invalida de parametros -> [nome_do_programa entrada.txt saida.txt]\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    FILE *output = fopen(argv[2], "w");
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    TreeNodePtr treeRoot;
    init(&treeRoot);
    if(fillTree(input, &treeRoot))
        writeOutput(output, &treeRoot);
    else
        fprintf(output, "Arquivo inválido!");
    
    destroy(&treeRoot);
    fclose(input);
    fclose(output);

    return 0;
}