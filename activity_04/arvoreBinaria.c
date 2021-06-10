#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct NO *esq;
    struct NO *dir;
}NO;

typedef struct arvoreBinaria{
    NO  *raiz;
}arvore;

arvore* criar(){
    arvore* R = (arvore*) malloc(sizeof(arvore));
    if(R != NULL){
        R->raiz = NULL;
    }
    return(R);
}

void liberaNO(NO* no){
    if(no == NULL){
        return;
    }
    liberaNO(no->esq); 
    liberaNO(no->dir);
    free(no);
    no = NULL;
    
}

void libera_arvore(arvore* r){
    if(r == NULL){
        return;
    }
    liberaNO(r); 
    free(r);
}

int main(void){
    arvore *r;
    r = criar();
    printf("hello word\n");
    return(0);
}