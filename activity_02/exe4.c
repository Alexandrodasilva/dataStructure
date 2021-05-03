#include<stdio.h>

int descrrecente(int n, int *vet){
   int i, j, aux;
    for(i=0; i < n; i++){
        for(j=0; j<n; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    printf("ordem descrescente\n");
      for(i = 0; i <n; i++){
        printf("%d \n", vet[i]) ;
    }
}

int main(){
    int n, i;
    printf("Digite a quantidade do vetor: \n");
    scanf("%d", &n);
    int vet[n];
    for(i = 0; i <n; i++){
        printf("digite  o valor: \n");
        scanf("%d", &vet[i]);
    }
    descrrecente(n, vet);
}