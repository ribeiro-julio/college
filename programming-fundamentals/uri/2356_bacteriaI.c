#include <stdio.h>
#include <string.h>

int main(){
    char d[101] = "", s[101] = "";
    setbuf(stdin, NULL);
    while(scanf("%s %s", d, s) != EOF){
        if(strstr(d, s) == NULL)
            printf("Nao resistente\n");
        else
            printf("Resistente\n");
    }
    return 0;
}