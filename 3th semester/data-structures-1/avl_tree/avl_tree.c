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
    preOrder(&(*node)->left);
    preOrder(&(*node)->right);
}

void inOrder(AVLNodePtr *node) {
    if((*node) == NULL)
        return;

    inOrder(&(*node)->left);
    printf("%d ", (*node)->x);
    inOrder(&(*node)->right);
}

void postOrder(AVLNodePtr *node) {
    if((*node) == NULL)
        return;

    postOrder(&(*node)->left);
    postOrder(&(*node)->right);
    printf("%d ", (*node)->x);
}

bool search(AVLNodePtr *node, int x) {
    if((*node) == NULL)
        return false;
    
    if((*node)->x == x)
        return true;
    
    if(x > (*node)->x)
        return search(&(*node)->right, x);
    else
        return search(&(*node)->right, x);
}

void destroy(AVLNodePtr *node) {
    if((*node) != NULL) {
        destroy(&(*node)->left);
        destroy(&(*node)->right);
        free((*node));
        (*node) = NULL;
    }
}

int AVLHeight(AVLNodePtr node) {    // Maior caminho nó para folha
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int updateAVLHeight(AVLNodePtr left, AVLNodePtr right) {
    int lh = AVLHeight(left);
    int rh = AVLHeight(right);

    if(lh > rh)
        return (lh + 1);
    else
        return (rh + 1);
}

void rightSimpleRotation(AVLNodePtr *p) {
    AVLNodePtr u = (*p)->left;

    (*p)->left = u->right;
    u->right = (*p);
    (*p)->height = 0;

    (*p)->height = updateAVLHeight((*p)->left, (*p)->right);
    u->height = updateAVLHeight(u->left, u->right);

    (*p) = u;
}

void leftSimpleRotation(AVLNodePtr *p) {
    AVLNodePtr u = (*p)->right;

    (*p)->right = u->left;
    u->left = (*p);
    (*p)->height = 0;

    (*p)->height = updateAVLHeight((*p)->left, (*p)->right);
    u->height = updateAVLHeight(u->left, u->right);

    (*p) = u;
}

void rightDoubleRotation(AVLNodePtr *p) {
    AVLNodePtr u = (*p)->left;
    AVLNodePtr v = u->right;

    (*p)->left = v->right;
    u->right = v->left;
    v->right = (*p);
    v->left = u;

    (*p)->height = updateAVLHeight((*p)->left, (*p)->right);
    u->height = updateAVLHeight(u->left, u->right);
    v->height = updateAVLHeight(v->left, v->right);

    (*p) = v;
}

void leftDoubleRotation(AVLNodePtr *p) {
    AVLNodePtr u = (*p)->right;
    AVLNodePtr v = u->left;

    (*p)->right = v->left;
    u->left = v->right;
    v->left = (*p);
    v->right = u;

    (*p)->height = updateAVLHeight((*p)->left, (*p)->right);
    u->height = updateAVLHeight(u->left, u->right);
    v->height = updateAVLHeight(v->left, v->right);

    (*p) = v;
}

void applyRotations(AVLNodePtr *node) {
    int rh = AVLHeight((*node)->right);
    int lh = AVLHeight((*node)->left);
    int bf = rh - lh;

    if(bf >= 2) {   // Rotaciona pra esquerda -> mais elementos na direita
        AVLNodePtr temp = (*node)->right;
        int temprh = AVLHeight(temp->right);
        int templh = AVLHeight(temp->left);

        if(temprh >= templh)  // Rotacao simples
            leftSimpleRotation(&(*node));
        else  // rotação dupla
            leftDoubleRotation(&(*node));

    } else if (bf <= 2) {        // Rotaciona pra direita ->  mais elementos na esquerda
        AVLNodePtr temp = (*node)->left;
        int temprh = AVLHeight(temp->right);
        int templh = AVLHeight(temp->left);

        if(templh >= temprh)  // Rotacao simples
            rightSimpleRotation(&(*node));
        else  // rotação dupla
            rightDoubleRotation(&(*node));
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
    
    int rh = AVLHeight((*node)->right);
    int lh = AVLHeight((*node)->left);

    if((rh - lh) == 2 || (rh - lh) == -2)
        applyRotations(&(*node));

    (*node)->height = updateAVLHeight((*node)->left, (*node)->right);

    return true;
}

AVLNodePtr getMaxAux(AVLNodePtr *node) {
    AVLNodePtr ret;

    if((*node)->right == NULL) {
        ret = (*node);
        (*node) = (*node)->left;
        return ret;
    }

    return getMaxAux(&(*node)->right);
}

AVLNodePtr getMinAux(AVLNodePtr *node) {
    AVLNodePtr ret;

    if((*node)->left == NULL) {
        ret = (*node);
        (*node) = (*node)->right;
        return ret;
    }

    return getMinAux(&(*node)->left);
}

int AVLDepth(AVLNodePtr *node) {    // Nó para raiz
    if ((*node) == NULL)
        return 0;

    else {
        int rd = AVLDepth(&(*node)->right);
        int ld = AVLDepth(&(*node)->left);
    
        if (ld > rd)
            return(ld + 1);
        else
            return(rd + 1);
    }
}

bool removeNode(AVLNodePtr *node, int x) {
    if((*node) == NULL) {       // Nao encontrou
        printf("Erro ao remover -> chave nao encontrada\n");
        return false;
    }

    if((*node)->x == x) {   // Encontrou o elemento a remover
        AVLNodePtr aux = (*node);

        if((*node)->right == NULL && (*node)->left == NULL)     // Folha
            (*node) = NULL;
        
        else if((*node)->right != NULL && (*node)->left == NULL)    // Apenas subarvore direita
            (*node) = (*node)->right;

        else if((*node)->right == NULL && (*node)->left != NULL)    // Apenas subarvore esquerda
            (*node) = (*node)->left;
        
        else {      // 2 subarvores
            aux = getMaxAux(&(*node)->left);     // Pega o maior elemento da subarvore esquerda
            //aux = getMinAux(&(*node)->right);   // Pega o menor elemento da subarvore direita
            (*node)->x = aux->x;
        }

        free(aux);
        return true;
    }
    
    bool removed;
    if(x > (*node)->x)      // Busca recursiva do elemento a remover
        removed = removeNode(&(*node)->right, x);
    else
        removed = removeNode(&(*node)->left, x);
    
    if(removed == false)
        return false;
    
    int rd = AVLDepth(&(*node)->right);
    int ld = AVLDepth(&(*node)->left);

    if((ld - rd) == 2 || (ld - rd) == -2)   // Se desbalanceou a arvore faz rebalanceamento
        applyRotations(&(*node));

    (*node)->height = updateAVLHeight((*node)->left, (*node)->right);

    return true;
}


int main() {
    AVLNodePtr AVLRoot;

    init(&AVLRoot);

    if(isEmpty(&AVLRoot))
        printf("Arvore vazia\n");

    insert(&AVLRoot, 77);
    insert(&AVLRoot, 12);
    insert(&AVLRoot, 10);
    insert(&AVLRoot, 5);
    insert(&AVLRoot, 7);
    insert(&AVLRoot, 80);
    insert(&AVLRoot, 78);
    insert(&AVLRoot, 90);
    insert(&AVLRoot, 100);
    insert(&AVLRoot, 2);
    insert(&AVLRoot, 1);

    printf("PreOrder = { ");
    preOrder(&AVLRoot);
    printf("}\n");

    printf("PostOrder = { ");
    postOrder(&AVLRoot);
    printf("}\n");

    printf("InOrder = { ");
    inOrder(&AVLRoot);
    printf("}\n");

    removeNode(&AVLRoot, 100);
    removeNode(&AVLRoot, 80);
    removeNode(&AVLRoot, 2);
    removeNode(&AVLRoot, 7);
    removeNode(&AVLRoot, 78);
    removeNode(&AVLRoot, 12);

    printf("PreOrder = { ");
    preOrder(&AVLRoot);
    printf("}\n");

    destroy(&AVLRoot);

    if(isEmpty(&AVLRoot))
        printf("Arvore vazia\n");

    return 0;
}