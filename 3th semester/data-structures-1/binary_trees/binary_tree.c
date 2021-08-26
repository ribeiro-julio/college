#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct TreeNode *TreeNodePtr;

typedef struct TreeNode {
    int x;
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

TreeNodePtr getMaxAux(TreeNodePtr *tree) {
    TreeNodePtr ret;

    if((*tree)->right == NULL) {
        ret = (*tree);
        (*tree) = (*tree)->left;
        return ret;
    }

    return getMaxAux(&(*tree)->right);
}

void init(TreeNodePtr *tree) {
    (*tree) = NULL;
}

void inOrder(TreeNodePtr *tree) {
    if((*tree) == NULL)
        return;
    inOrder(&(*tree)->left);
    printf("%d ", (*tree)->x);
    inOrder(&(*tree)->right);
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
        printf("Insertion error -> Key already exists\n");
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

bool removeNode(TreeNodePtr *tree, int x) {
    if((*tree) == NULL) {
        printf("Removal error -> Key not found\n");
        return false;
    }
    
    if((*tree)->x == x) {
        TreeNodePtr aux = (*tree);

        if((*tree)->right != NULL && (*tree)->left == NULL)
            (*tree) = (*tree)->right;

        else if((*tree)->right == NULL && (*tree)->left == NULL)
            (*tree) = NULL;

        else if((*tree)->right == NULL && (*tree)->left != NULL)
            (*tree) = (*tree)->left;

        else {
            aux = getMaxAux(&(*tree)->left);
            (*tree)->x = aux->x;
        }

        free(aux);
        return true;
    }


    if(x > (*tree)->x)
        return removeNode(&(*tree)->right, x);
    else
        return removeNode(&(*tree)->left, x);
}


bool search(TreeNodePtr *tree, int x) {
    if((*tree) == NULL) {
        printf("Search warning -> Key not found\n");
        return false;
    }

    if((*tree)->x == x)
        return true;

    if(x > (*tree)->x) 
        return search(&(*tree)->right, x);
    else
        return search(&(*tree)->left, x);
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
    
    if(search(&treeRoot, 5))
        printf("Achou\n");
    else
        printf("Nao achou\n");

    if(search(&treeRoot, 10))
        printf("Achou\n");
    else
        printf("Nao achou\n");

    if(search(&treeRoot, 14))
        printf("Achou\n");
    else
        printf("Nao achou\n");

    if(search(&treeRoot, 0))
        printf("Achou\n");
    else
        printf("Nao achou\n");

    if(search(&treeRoot, 3))
        printf("Achou\n");
    else
        printf("Nao achou\n");
    
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    removeNode(&treeRoot, 6);
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    removeNode(&treeRoot, 5);
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    removeNode(&treeRoot, 3);
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    removeNode(&treeRoot, 8);
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    removeNode(&treeRoot, 4);
    printf("Pre Order = { ");
    preOrder(&treeRoot);
    printf("}\n");

    destroy(&treeRoot);

    if(isEmpty(&treeRoot))
        printf("Arvore vazia\n");

    return 0;
}