#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    //int placa;
    if(aux == NULL){
        return(printf("A pilha de carro já se encotra  vazio !!\n"));
    }else{
         pi->topo = aux->prox;
        free(aux);
    }
}


int busca(pilhaC *pi, int NUM ){

    Carro *aux = pi->topo;
    if(aux == NULL){
        return(printf("A pilha de carro já se encotra  vazio !!\n"));
    }
   
    else{
        while(aux != NULL){
            if(NUM == aux){
                free(aux);
            }else{
               // EMPILHA(p, num);
                //num = aux;
               //empilharC(pilhaC *pi, int num)
            }
            aux = aux->prox;
        }
    } 
}

//-----------------outra estrutura---------------------------------------------

struct car{
    int plac;
    struct car *proximo;
};
typedef struct car Car;

struct pilha{
    Car *TOPO;
};

typedef struct pilha pilha;

pilha* CRIAR(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    if(p != NULL){
        p->TOPO =NULL;
    }
    return p;
}

void EMPILHA(pilha *p, int num){
    Car *ca = (Car*) malloc(sizeof(Carro));
    ca->plac = num;
    ca->proximo = p->TOPO;
    p->TOPO = ca;
}

void IMPRIMI(pilha *p){
    Car *aux = p->TOPO;
    if(aux == NULL){
        printf("a pilha de carro está vazia !!\n");
        return;
    }else{
         while(aux != NULL){
             printf("%d \n", aux->plac);
             aux = aux->proximo;
         }
    }
} 

int DESEMPILHA(pilha *p){
    Car *aux = p->TOPO;
    //int placa;
    if(aux == NULL){
        return(printf("A pilha de carro já se encotra  vazio !!\n"));
    }else{
         p->TOPO = aux->proximo;
        free(aux);
    }
}



int main(){

	pilhaC *pi;
	pi = criarPilha();
	printf("\n");
	printf("\n");
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

	return(0);
}