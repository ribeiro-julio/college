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

void inOrder(TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;
    inOrder(&(*tree)->left);
    printf("%s ", (*tree)->word);
    inOrder(&(*tree)->right);
}

bool insert(TreeNodePtr *tree, char word[]) {
    if((*tree) == NULL) {
        (*tree) = malloc(sizeof(TreeNode));
        strcpy((*tree)->word, word);
        (*tree)->right = (*tree)->left = NULL;
        return true;
    }

    if(strcmp((*tree)->word, word) == 0) {
        printf("Erro ao inserir -> chave ja existente\n");
        return false;
    }

    if(strcmp(word, (*tree)->word) > 0)
        return insert(&(*tree)->right, word);
    else
        return insert(&(*tree)->left, word);
}

/*
 *  Fim funções binary tree
 */


/*
 *  Inicio funções auxiliares
 */

bool fillTree(FILE *file, TreeNodePtr *tree) {
    char firstLine[500] = "";
    char line[500] = "";
    char *word;
    int page;
    int pages[20];
    int j = 0;

    fscanf(file, "<termos:%s", firstLine);
    word = strtok(firstLine, ",>");
    while(word != NULL) {
        char c = fgetc(file);
        while(c != EOF) {
            if(c == '<') {
                fscanf(file, "page:%d", &page);
            }
            c = fgetc(file);
            if(c == '>') {
                fgets(file, 500, line);
                if(strstr(line, word) != NULL) {
                    pages[j] = page;
                    j++;
                }
            }
        }
        insert(tree, word);
        word = strtok(NULL, ",>");
    }
    
    return true;
}

/*
 *  Fim funções auxiliares
 */


int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade invalida de parametros -> [nome_do_programa entrada.txt saida.txt]\n");
        //exit(1);
    }

    //FILE *input = fopen(argv[1], "r");
    FILE *input = fopen("./input/entrada2.txt", "r");
    //FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    //if(output == NULL) {
        //printf("Erro ao abrir o arquivo de saida\n");
        //exit(2);
    //}

    TreeNodePtr treeRoot;
    init(&treeRoot);
    if(fillTree(input, &treeRoot)) {
        printf("In Order = { ");
        inOrder(&treeRoot);
        printf("}\n");
    }

    destroy(&treeRoot);
    fclose(input);
    //fclose(output);

    return 0;
}