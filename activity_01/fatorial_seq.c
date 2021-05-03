#include <stdio.h>
int main(){
    
    int i, fat;
    scanf("%d", &fat);       
    for(i = 1; fat > 1; fat = fat - 1){   
        i = i * fat; 
    }
    //printf("\n%d", i);
    return 0;
}
