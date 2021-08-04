#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct AVLNode *AVLNodePtr;

typedef struct AVLNode {
    int x;
    AVLNodePtr right;
    AVLNodePtr left;
    int height;
} AVLNode;


void init(AVLNodePtr *node) {
    (*node) = NULL;
}

bool isEmpty(AVLNodePtr *node) {
    return (*node) == NULL;
}

void preOrder(AVLNodePtr *node) {
    if((*node) == NULL)
        return;

    printf("%d ", (*node)->x);
    preOrder((*node)->left);
    preOrder((*node)->right);
}

void inOrder(AVLNodePtr *node) {
    if((*node) == NULL)
        return;

    inOrder((*node)->left);
    printf("%d ", (*node)->x);
    inOrder((*node)->right);
}

void postOrder(AVLNodePtr *node) {
    if((*node) == NULL)
        return;

    postOrder((*node)->left);
    postOrder((*node)->right);
    printf("%d ", (*node)->x);
}

bool search(AVLNodePtr *node, int x) {
    if((*node) == NULL)
        return false;
    
    if((*node)->x == x)
        return true;
    
    if(x > (*node)->x)
        return search((*node)->right, x);
    else
        return search((*node)->right, x);
}

void destroy(AVLNodePtr *node) {
    if((*node) != NULL) {
        destroy(&(*node)->left);
        destroy(&(*node)->right);
        free((*node));
        (*node) = NULL;
    }
}

bool insert(AVLNodePtr *node, int x) {
    if((*node) == NULL) {
        (*node) = (AVLNodePtr)malloc(sizeof(AVLNode));
        (*node)->right = (*node)->left = NULL;
        (*node)->x = x;
        (*node)->height = 1;
        return true;
    }

    if((*node)->x == x) {
        printf("Erro ao inserir -> chave ja existente\n");
        return false;
    }

    bool inserted;
    if(x > (*node)->x)
        inserted = insert(&(*node)->right, x);
    else
        inserted = insert(&(*node)->left, x);
    
    if(inserted == false)
        return false;
    
    int leftHeight, rightHeight;
    leftHeight = AVLHeight((*node)->left);
    rightHeight = AVLHeight((*node)->right);

    if((rightHeight - leftHeight) == 2 || (rightHeight - leftHeight) == -2)
        applyRotations(node);

    (*node)->height = updateAVLHeight((*node)->left, (*node)->right);
}

int AVLHeight(AVLNodePtr node) {
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int updateAVLHeight(AVLNodePtr left, AVLNodePtr right) {
    int lt = AVLHeight(left);
    int rt = AVLHeight(right);

    if(lt > rt)
        return (lt + 1);
    else
        return (rt + 1);
}

void applyRotations(AVLNodePtr *node) {
    int lt = AVLHeight((*node)->left);
    int rt = AVLHeight((*node)->right);
    int bf = rt - lt;

    if(bf == 2) {   // Rotaciona pra esquerda
        AVLNodePtr temp = (*node)->right;
        int temprh = AVLHeight(temp->right);
        int templh = AVLHeight(temp->left);

        if(templh > temprh)    // Rotacao simples
            leftDoubleRotation(&(*node));
        else  // rotação dupla
            leftSimpleRotation(&(*node));
    } else {        // Rotaciona pra direita
        AVLNodePtr temp = (*node)->left;
        int temprh = AVLHeight(temp->right);
        int templh = AVLHeight(temp->left);

        if(temprh > templh)    // Rotacao simples
            rightDoubleRotation(&(*node));
        else    // rotação dupla
            rightSimpleRotation(&(*node));
    }
}


int main() {
    AVLNodePtr AVLRoot;

    init(&AVLRoot);

    if(isEmpty(&AVLRoot))
        printf("Arvore vazia\n");

    destroy(&AVLRoot);

    return 0;
}