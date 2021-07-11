#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0, num[1] = {1}, divisions = 0;
    FILE *file;
    file = fopen("primes.dat", "wb");
    while(count < 10000){
        for(int i = 1; i <= num[0]; i++){
            if(num[0]%i == 0)
                divisions++;
            if(divisions > 2)
                break;
        }
        if(divisions == 2){
            count++;
            fwrite(num, sizeof(int), 1, file);
        }
        num[0]++;
        divisions = 0;
    }
    fclose(file);

    //file = fopen("primes.dat", "rb");
    //int nums[10000];
    //fread(nums, sizeof(int), 10000, file);
    //fclose(file);
    //for(int i = 0; i < 10000; i++)
        //printf("%d ", nums[i]);
    
    return 0;
}