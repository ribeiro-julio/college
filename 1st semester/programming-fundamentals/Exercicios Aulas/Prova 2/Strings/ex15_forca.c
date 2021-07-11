#include <stdio.h>
#include <string.h>

void mostrarForca(int erros){
    printf("________\n");
    printf("|      |\n");
    switch(erros){
        case 0:
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 1:
            printf("|      0\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf("|      0\n");
            printf("|     /|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 3: 
            printf("|      0\n");
            printf("|     /|\\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf("|      0\n");
            printf("|     /|\\\n");
            printf("|      |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 5:
            printf("|      0\n");
            printf("|     /|\\\n");
            printf("|      |\n");
            printf("|     /\n");
            printf("|\n");
            printf("|\n");
            break;
        case 6:
            printf("|      0\n");
            printf("|     /|\\\n");
            printf("|      |\n");
            printf("|     / \\\n");
            printf("|\n");
            printf("|   PERDEU!\n");
            break;
    }
}

int main(){
    int erros = 0, countPalpites = 0;
    char palavra[30] = "", preencherPalavra[29] = "", palpite[2] = "", palpites[30] = "";
    int i, jaDigitou = 0, acertos = 0;

    printf("Jogador 1: Digite a palavra para o Jogador 2 adivinhar:\n");
    setbuf(stdin, NULL);
    scanf("%29s", &palavra);
    system("cls");
    mostrarForca(erros);
    for(i = 0; i < strlen(palavra); i++){
        if(i == 0)
            printf("     _ ");
        else if(i == (strlen(palavra)-1))
            printf("_\n\n");
        else
            printf("_ ");
    }

    while(erros < 6 && acertos != strlen(palavra)){
        do{
            jaDigitou = 0;
            printf("Palpite do Jogador 2: ");
            setbuf(stdin, NULL);
            scanf("%1s", &palpite);
            for(i = 0; i <= countPalpites; i++){
                if(palpites[i] == palpite[0]){
                    printf("Letra ja foi digitada!\n");
                    jaDigitou = 1;
                }
            }
        }while(jaDigitou == 1);

        if(strstr(palavra, palpite) == NULL)
            erros++;
        else{
            for(i = 0; i < strlen(palavra); i++){
                if(palavra[i] == palpite[0]){
                    preencherPalavra[i] = palpite[0];
                    acertos++;
                }
            }
        }

        palpites[countPalpites] = palpite[0];
        countPalpites++;

        system("cls");
        mostrarForca(erros);
        for(i = 0; i < strlen(palavra); i++){
            if(i == 0 && preencherPalavra[i] == '\0')
                printf("     _ ");
            else if(i == 0 && preencherPalavra[i] != '\0')
                printf("     %c ", preencherPalavra[i]);
            else if(i == (strlen(palavra)-1) && preencherPalavra[i] == '\0')
                printf("_\n\n");
            else if(i == (strlen(palavra)-1) && preencherPalavra[i] != '\0')
                printf("%c\n\n", preencherPalavra[i]);
            else{
                if(preencherPalavra[i] == '\0')
                    printf("_ ");
                else
                    printf("%c ", preencherPalavra[i]);
            }
        }
        printf("Palpites ja feitos: ");
        for(i = 0; i <= countPalpites; i++){
            if(i == countPalpites)
                printf("%c\n", palpites[i]);
            else
                printf("%c ", palpites[i]);
        }
        if(acertos == strlen(palavra))
            printf("GANHOU!\n");
    }
}