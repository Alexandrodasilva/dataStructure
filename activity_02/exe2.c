#include<stdio.h>

int media( int  *vet){
   int i, soma= 0, med =0;

    for( i = 0; i < 10; i++){
        soma += vet[i];
    }
    med = soma/10;
    return(printf("media: %d, endereço:%p \n", med, &med));
    }

int maior(int *vet){
    int i, M;
    M = vet[0];
    for(i = 0;  i< 10;   i++ ){
       if(M < vet[i]){
           M = vet[i];
       }
    }
    return(printf("maior valor: %d, endereço:%p \n", M, &M));
}

int menor(int *vet){
    int i, m;
    m = vet[0];
    for(i = 0;  i< 10;   i++ ){
       if(m > vet[i] ){
           m = vet[i];
       }
    }
    return(printf("menor valor: %d, endereço:%p\n", m, &m));
}

int modificar(int *vet){
    int i, aux, soma= 0, med =0;
    for( i = 0; i < 10; i++){
        soma += vet[i];
    }
    med = soma/10;
    for( i = 0; i < 10; i++){
        if(vet[i] > med){
            aux = (vet[i])/(vet[i]);
            vet[i] = aux;
            printf("%d \n", vet[i]);
        }else if(vet[i] < med){
            printf("%d \n", vet[i]);
        }
        
    }
}

int main(){

 int vet[10], i ;
    for(i = 0; i < 10; i++){
        printf("Digite o numero na posição %d  \n",   i+1);
        scanf( "%d", &vet[i]);
      // printf(" endereço %p ",  &vet[i]); 
    }
    
    printf("\n");
    media(vet);
    menor(vet);
    maior(vet);
    printf("End 1º posição: %p, num:%d \n",&vet[0],vet[0] );
    printf("End 2º posição: %p, num:%d \n",&vet[9],vet[9]);

    modificar(vet);

    media(vet);
    menor(vet);
    maior(vet);
    printf("End 1º posição: %p, num:%d \n",&vet[0],vet[0] );
    printf("End 2º posição: %p, num:%d \n",&vet[9],vet[9]);
    //printf("\n");
  
     
}
