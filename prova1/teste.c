#include<stdio.h>
#include<stdlib.h>

struct carro{
    int placa;
    struct carro *prox;
};
typedef struct carro Carro;

struct pilhac{
    Carro *topo;
};
typedef struct pilhac pilhaC;

pilhaC* criarPilha(){
    pilhaC *pi = (pilhaC*) malloc(sizeof(pilhaC));
    if(pi != NULL){
        pi->topo =NULL;
    }
    return pi;
}

void empilharC(pilhaC *pi, int num){
    Carro *c = (Carro*) malloc(sizeof(Carro));
    c->placa = num;
    c->prox = pi->topo;
    pi->topo = c;
}

void imprimir(pilhaC *pi){
    Carro *aux = pi->topo;
    if(aux == NULL){
        printf("a pilha de carro está vazia !!\n");
        return;
    }else{
         while(aux != NULL){
             printf("%d \n", aux->placa);
             aux = aux->prox;
         }
    }
} 

int desempilhar(pilhaC *pi){
    Carro *aux = pi->topo;
    int placa;
    if(aux == NULL){
        return(printf("A pilha de carro já se encotra  vazio !!\n"));
    }else{
         pi->topo = aux->prox;
        free(aux);
    }
}
int main(void){
    pilhaC *pi;
    pi = criarPilha();
    empilharC(pi, 10);
    empilharC(pi, 23);
    empilharC(pi, 33);
    empilharC(pi, 49);
    imprimir(pi);
    printf("\n");
    printf("desempilhando o último\n",desempilhar(pi));
    imprimir(pi);
    printf("desempilhando o último\n",desempilhar(pi));
    imprimir(pi);
    printf("desempilhando o último\n",desempilhar(pi));
    imprimir(pi);
    printf("desempilhando o último\n",desempilhar(pi));
    imprimir(pi);
    
    return 0;
}