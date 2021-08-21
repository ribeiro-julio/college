#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 *  Inicio funções avl
 */

typedef struct AVLNode *AVLNodePtr;

typedef struct AVLNode {
    int x;
    AVLNodePtr right;
    AVLNodePtr left;
    int height;
} AVLNode;

void destroy(AVLNodePtr *node) {
    if((*node) != NULL) {
        destroy(&(*node)->left);
        destroy(&(*node)->right);
        free((*node));
        (*node) = NULL;
    }
}

void init(AVLNodePtr *node) {
    (*node) = NULL;
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

int AVLHeight(AVLNodePtr node) {    // Maior caminho nó para folha
    if(node == NULL)
        return 0;
    else
        return node->height;
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

int updateAVLHeight(AVLNodePtr left, AVLNodePtr right) {
    int lh = AVLHeight(left);
    int rh = AVLHeight(right);

    if(lh > rh)
        return (lh + 1);
    else
        return (rh + 1);
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

void rightSimpleRotation(AVLNodePtr *p) {
    AVLNodePtr u = (*p)->left;

    (*p)->left = u->right;
    u->right = (*p);
    (*p)->height = 0;

    (*p)->height = updateAVLHeight((*p)->left, (*p)->right);
    u->height = updateAVLHeight(u->left, u->right);

    (*p) = u;
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

bool removeNodeLeft(AVLNodePtr *node, int x) {
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
            (*node)->x = aux->x;
        }

        free(aux);
        return true;
    }
    
    bool removed;
    if(x > (*node)->x)      // Busca recursiva do elemento a remover
        removed = removeNodeLeft(&(*node)->right, x);
    else
        removed = removeNodeLeft(&(*node)->left, x);
    
    if(removed == false)
        return false;
    
    int rd = AVLDepth(&(*node)->right);
    int ld = AVLDepth(&(*node)->left);

    if((ld - rd) == 2 || (ld - rd) == -2)   // Se desbalanceou a arvore faz rebalanceamento
        applyRotations(&(*node));

    (*node)->height = updateAVLHeight((*node)->left, (*node)->right);

    return true;
}

bool removeNodeRight(AVLNodePtr *node, int x) {
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
            aux = getMinAux(&(*node)->right);     // Pega o menor elemento da subarvore direita
            (*node)->x = aux->x;
        }

        free(aux);
        return true;
    }
    
    bool removed;
    if(x > (*node)->x)      // Busca recursiva do elemento a remover
        removed = removeNodeRight(&(*node)->right, x);
    else
        removed = removeNodeRight(&(*node)->left, x);
    
    if(removed == false)
        return false;
    
    int rd = AVLDepth(&(*node)->right);
    int ld = AVLDepth(&(*node)->left);

    if((ld - rd) == 2 || (ld - rd) == -2)   // Se desbalanceou a arvore faz rebalanceamento
        applyRotations(&(*node));

    (*node)->height = updateAVLHeight((*node)->left, (*node)->right);

    return true;
}

/*
 *  Fim funções avl
 */


/*
 *  Inicio funções auxiliares
 */

bool fillTree(FILE *file, AVLNodePtr *node) {
    int input[20];
    int inputs = 1;

    char c = fgetc(file);   // Contar a quantidade de numeros para colcoar na arvore
    while(c != '\n' && c != EOF) {
        if(c == ',')
            inputs++;
        c = fgetc(file);
    }
    rewind(file);

    if(inputs == 1)     // Não tem virgula separando os valores ou arquivo vazio -> inválido
        return false;

    for(int i = 0; i < inputs; i++) {       // Pega os valores de entrada
        fscanf(file, "%d,", &input[i]);
    }

    for(int i = 0; i < inputs; i++) {       // Insere os valores na arvore
        insert(&(*node), input[i]);
    }

    fgetc(file);    // Pula o \n
    fgetc(file);
}

void printLevel(AVLNodePtr *node, FILE *file, int level) {      // Printa um nível da arvore
    if((*node) == NULL)
        return;

    if(level == 1) {
        int bf = AVLHeight((*node)->right) - AVLHeight((*node)->left);
        fprintf(file, "%d (%d),", (*node)->x, bf);
    }
    else if(level > 1) {
        printLevel(&(*node)->left, file, level-1);
        printLevel(&(*node)->right, file, level-1);
    }
}

void printAllLevels(AVLNodePtr *node, FILE *file) {     // Printa os nível da arvore
    int height = AVLHeight(*node);
    for(int i = 1; i <= height; i++) {
        printLevel(&(*node), file, i);
        fprintf(file, "\n");
    }
}

bool writeOutput(FILE *input, FILE *output, AVLNodePtr *node) {
    int to_remove[20];
    int removes = 1;

    char c = fgetc(input);   // Contar a quantidade de numeros para colcoar na arvore
    while(c != '\n' && c != EOF) {
        if(c == ',')
            removes++;
        c = fgetc(input);
    }
    rewind(input);
    char buffer[201];
    fgets(buffer, 200, input);  // Pula a linha de entradas

    if(removes == 1)     // Não tem virgula separando os valores ou arquivo vazio -> inválido
        return false;

    for(int i = 0; i < removes; i++) {       // Pega os valores de remocao
        fscanf(input, "%d,", &to_remove[i]);
    }

    c = fgetc(input);
    while(c != 'e' && c != 'd' && c != EOF)
        c = fgetc(input);

    if(c == 'e') {
        fprintf(output, "[*]antes\n");
        printAllLevels(&(*node), output);

        for(int i = 0; i < removes; i++)      // Remove o valor da arvore e printa no arquivo
            removeNodeLeft(&(*node), to_remove[i]);
    } else if(c == 'd') {
        fprintf(output, "[*]antes\n");
        printAllLevels(&(*node), output);

        for(int i = 0; i < removes; i++)       // Remove o valor da arvore e printa no arquivo
            removeNodeRight(&(*node), to_remove[i]);
    } else      // Diferente de e ou d -> formato inválido
        return false;

    fprintf(output, "\n[*]depois\n");
    printAllLevels(&(*node), output);
    
    return true;
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

    AVLNodePtr AVLRoot;
    init(&AVLRoot);
    if(fillTree(input, &AVLRoot)) {
        if(!writeOutput(input, output, &AVLRoot))
            fprintf(output, "Arquivo inválido!");
    }
    else
        fprintf(output, "Arquivo inválido!");
    
    destroy(&AVLRoot);
    fclose(input);
    fclose(output);
}