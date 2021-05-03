#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>


int main(){
        int  i,n;
        printf("Digite quantos paragrafos você deseja?");
        scanf("%d", &n);
        char paragrafo[n][100];
        for(i = 0; i < n; i++){
            printf("digite o texto nesse parafrafo? o flag é o enter.");
            scanf("%c ", paragrafo[i]);
            //gets(paragrafo[i]);
        }   
        printf("%d", paragrafo[i][100]);
    return 0;
}