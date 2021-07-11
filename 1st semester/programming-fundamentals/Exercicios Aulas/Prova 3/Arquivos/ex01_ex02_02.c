#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int random;
    FILE *file;
    file = fopen("numbers.dat", "wb");
    for(int i = 0; i < 100; i++){
        random = rand();
        fwrite(random, sizeof(int), 1, file);
    }
    fclose(file);

    file = fopen("numbers.dat", "rb");
    int nums[100];
    int sum = 0;
    fread(nums, sizeof(int), 100, file);
    fclose(file);
    for(int i = 0; i < 100; i++)
        sum += nums[i];
    printf("A soma dos numeros gerados e: %d", sum);
    
    return 0;
}