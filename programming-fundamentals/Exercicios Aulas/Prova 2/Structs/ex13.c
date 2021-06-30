#include <stdio.h>
#include <math.h>

typedef struct{
    int retorno;
    float x1, x2;
}Raizes;

Raizes resolveEquacao(float a, float b, float c){
    Raizes raiz;

    if(a == 0)
        raiz.retorno = 0;
    else{
        float delta = (b*b) - (4*a*c);
        if(delta < 0)
            raiz.retorno = -1;
        else{
            raiz.x1 = ((-1*b) + sqrt(delta)) / (2*a);
            raiz.x2 = ((-1*b) - sqrt(delta)) / (2*a);
            if(delta == 0)
                raiz.retorno = 1;
            else if(delta > 0)
                raiz.retorno = 2;
        }
    }
    return raiz;
}

int main(){
    float a, b, c;
    Raizes raiz;

    printf("Digite a, b e c da equacao: ");
    scanf("%f %f %f", &a, &b, &c);
    raiz = resolveEquacao(a, b, c);

    if(raiz.retorno == 0)
        printf("Nao e uma equacao do segundo grau!\n");
    else{
        if(raiz.retorno == -1)
            printf("Nao existem raizes reais para essa equacao!\n");
        else if(raiz.retorno == 1)
            printf("Delta = 0; Raizes iguais: x1 = %.4f e x2 = %.4f\n", raiz.x1, raiz.x2);
        else
            printf("Delta > 0; Raizes diferentes: x1 = %.4f e x2 = %.4f\n", raiz.x1, raiz.x2);
    }
    return 0;
}