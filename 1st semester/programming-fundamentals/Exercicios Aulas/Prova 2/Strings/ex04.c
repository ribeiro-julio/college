#include <stdio.h>
#include <string.h>

int main(){
    char string[200] = "0";

    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(string, 199, stdin);
    string[strcspn(string, "\n")] = 0;

    int i;
    for (i = 0; i < strlen(string); i++) {
        if(string[i] >= 97 && string[i] <= 122)
            string[i] -= 32;
    }

    printf("%s\n", string);
    
    return 0;
}