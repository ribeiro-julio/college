#include <stdio.h>
#include <string.h>

int main(){
    char t[501] = "";
    fgets(t, 500, stdin);
    t[strcspn(t, "\n")] = '\0';
    setbuf(stdin, NULL);
    if(strlen(t) < 141)
        printf("TWEET\n");
    else
        printf("MUTE\n");
    return 0;
}