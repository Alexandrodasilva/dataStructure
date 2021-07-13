#include<stdio.h>
#include<stdlib.h>

struct NO{
    int dados;
    struct NO *esq;
    struct NO *dir;
};
typedef struct  NO* arv;

arv* criar(){
    arv* R = (arv*) malloc(sizeof(arv));
    if(R != NULL){
        *R = NULL;
    }
    return(R);
}   

void liberaNO( struct NO* no){
    if(no == NULL){
        return;
    }
    liberaNO(no->esq); 
    liberaNO(no->dir);
    free(no);
    no = NULL; 
}

void libera_arvore(arv* r){
    if(r == NULL){
        return;
    }
    liberaNO(*r); 
    free(r);
}

int arvoreVazia(arv *r){
    if(r == NULL){
        return (1);
    }
    return(0);
}

void preOrdemArvBin(arv *r){   //RED
    if(r == NULL){
        return;
    }
    if(*r != NULL){
        printf("%d\n", (*r)->dados);
        preOrdemArvBin(&((*r)->esq));
        preOrdemArvBin(&((*r)->dir)); 
    }
}
void OrdemArvBin(arv *r){   //ERD
    if(r == NULL){
        return;
    }
    if(*r != NULL){
        OrdemArvBin(&((*r)->esq));
        printf("%d\n", (*r)->dados);
        OrdemArvBin(&((*r)->dir)); 
    }
}
void posOrdemArvBin(arv *r){   //ERD
    if(r == NULL){
        return;
    }
    if(*r != NULL){
        posOrdemArvBin(&((*r)->esq));
        posOrdemArvBin(&((*r)->dir)); 
        printf("%d\n", (*r)->dados);
    }
}
int insercaoArvBusca(arv *r, int info){
    if(r = NULL){
        return 0;
    }
    struct NO* aux = (struct NO*) malloc(sizeof(struct NO));
    if(aux  == NULL){
        return 0;   
    }
    aux->dados =  info;
    aux->dir = NULL;
    aux->esq = NULL;
    if(*r == NULL){
        *r = aux;
    }
    else{
        
    }
}

int main(void){
    arv* r;
    r = criar();
    printf("hello word\n");
    return(0);
}