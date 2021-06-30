#include <stdio.h>

int tamanhoCorte(int lateral1, int lateral2){
    int tamanho, volume, maiorVolume, maior;
    int i;
    if(lateral1 > lateral2)
        maior = lateral1;
    else
        maior = lateral2;
    for(i = 1; i < maior; i++){
        volume = (lateral1-i)*(lateral2-i)*i;
        if(i == 1){
            maiorVolume = volume;
            tamanho = i;
        }
        else{
            if(volume > maiorVolume){
                maiorVolume = volume;
                tamanho = i;
            }
        }
    }
    return tamanho;
}

int main(){
    int lateral1, lateral2, tamanho, volume;
    printf("Digite as dimensoes da caixa: ");
    scanf("%d %d", &lateral1, &lateral2);
    tamanho = tamanhoCorte(lateral1, lateral2);
    volume = (lateral1-tamanho)*(lateral2-tamanho)*tamanho;
    printf("O tamanho dos cortes deve ser de %dU que gera um volume de %dU", tamanho, volume);
}