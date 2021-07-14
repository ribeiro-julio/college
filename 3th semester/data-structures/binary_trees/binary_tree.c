#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct TreeNode *TreeNodePtr;

typedef struct TreeNode {
    int x;
    TreeNodePtr right;
    TreeNodePtr left;
} TreeNode;



void init(TreeNodePtr *tree) {
    (*tree) = NULL;
}

bool isEmpty(TreeNodePtr *tree) {
    return (*tree) == NULL;
}

bool insert(TreeNodePtr *tree, int x) {     // Função recursiva
    if((*tree) == NULL) {       // Condição de parada   -> Encontrou um ligar para ser adicionado
        (*tree) = malloc(sizeof(TreeNode));
        (*tree)->x = x;
        (*tree)->right = (*tree)->left = NULL;
        return true;
    }

    if((*tree)->x == x) {       // Elemento ja existe na arvore
        printf("Erro ao inserir -> chave ja existente\n");
        return false;
    }

    if(x > (*tree)->x)      // Se o elemento for maior, vai para o filho da direita
        return insert(&(*tree)->right, x);
    else        // Se o elemento for menor, vai pro filho da direita
        return insert(&(*tree)->left, x);
}

void preOrder(TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;
    printf("%d ", (*tree)->x);
    preOrder(&(*tree)->left);
    preOrder(&(*tree)->right);
}

void postOrder(TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;
    postOrder(&(*tree)->left);
    postOrder(&(*tree)->right);
    printf("%d ", (*tree)->x);
}

void inOrder(TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;
    inOrder(&(*tree)->left);
    printf("%d ", (*tree)->x);
    inOrder(&(*tree)->right);
}



int main() {
    TreeNodePtr treeRoot;

    init(&treeRoot);

    if(isEmpty(&treeRoot))
        printf("Arvore vazia\n");

    insert(&treeRoot, 5);
    insert(&treeRoot, 4);
    insert(&treeRoot, 3);
    insert(&treeRoot, 2);
    insert(&treeRoot, 7);
    insert(&treeRoot, 6);
    insert(&treeRoot, 8);
    insert(&treeRoot, 9);

    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    printf("Post Order = { ");
    postOrder(&treeRoot);
    printf("}\n");

    printf("In Order = { ");
    inOrder(&treeRoot);
    printf("}\n");

    if(!isEmpty(&treeRoot))
        printf("Arvore nao vazia\n");

    return 0;
}