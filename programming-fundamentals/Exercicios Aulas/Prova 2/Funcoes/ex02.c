#include <stdio.h>

char retornaConceito(float media){
    if(media >= 0.0 && media < 5.0)
        return 'D';
    else if(media >= 5.0 && media < 7.0)
        return 'C';
    else if(media >= 7.0 && media < 9.0)
        return 'B';
    else
        return 'A';
}

int main(){
    float media;
    printf("Digite a media: ");
    scanf("%f", &media);
    printf("O conceito e %c", retornaConceito(media));
    return 0;
}