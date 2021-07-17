#include<stdio.h>
#include<stdlib.h>



typedef struct arv{
    int  number;
    struct arv *esq;
    struct arv *dir;
}arvBusca;

arvBusca* criarAvrBusca(){
    return;
}

arvBusca* inserirArvBusca(arvBusca *r, int num){
    if(r == NULL){
        r = (arvBusca*)malloc(sizeof(arvBusca));
        r->number = num;
        r->esq = NULL;
        r->dir = NULL;
       // printf("oiii");
    }
    else if(num < r->number){
        r->esq = inserirArvBusca(r->esq, num);
    }else{
        r->dir = inserirArvBusca(r->dir, num);
    }
    return(r);
}

void destruirArvBusca(arvBusca *r){
    if(r != NULL){
        destruirArvBusca(r->esq);
        destruirArvBusca(r->dir);
        free(r);
    }
}

 void preOrdem(arvBusca *r){
     if(r != NULL){
         printf("%d-", r->number);
         preOrdem(r->esq);
         preOrdem(r->dir);
     }
 }

 void emOrdem(arvBusca *r){
     if(r != NULL){
         preOrdem(r->esq);
         printf("%d", r->number);
         preOrdem(r->dir);
     }
 }

 void posOrdem(arvBusca *r){
     if(r != NULL){
         preOrdem(r->esq);
         preOrdem(r->dir);
         printf("%d", r->number);
     }
 }

void buscarArvBusca(arvBusca *r, int num, int n){
    n++;
    if(r == NULL){
       return(printf("\nNão contem nessa estrutura!\n")); 
    }
    else if(num < r->number){
        return(buscarArvBusca(r->esq, num, n));
    }
    else if(num > r->number){
        return(buscarArvBusca(r->dir, num, n));
    }else if(num == r->number){
        return(printf("%d encontrado na arvore! E número de comprações é:%d\n", r->number, n));
    }
}

arvBusca* removerArvBusca(arvBusca *r, int num){
    if(r == NULL){
        return;
    }
    else{
        if(r->number > num){
            r->esq = removerArvBusca(r->esq, num);
        }
        else if(r->number < num){
            r->dir = removerArvBusca(r->dir, num);
        }else{
            if((r->esq== NULL) && (r->dir == NULL)){
                free(r);
                r = NULL;
            }
            else if(r->dir == NULL){
                arvBusca *aux = r;
                r = r->esq;
                free(aux);
            }
            else if(r->esq == NULL){
                arvBusca *aux = r;
                r = r->dir;
                free(aux);
            }else{
                arvBusca *aux = r->esq;
                while (aux->dir != NULL){
                   aux = aux->dir;
                }
                r->number = aux->number;
                aux->number = num;
                r->esq = removerArvBusca(r->esq, num);
            }
        }
    }
    return(r);
}

int alturaArvBusca(arvBusca *r){
    if(r != NULL){
        int x, y;
        x = alturaArvBusca(r->esq);
        y = alturaArvBusca(r->dir);
        if(x<y){
            return(y+1);
        }else{
            return(x+1);
        }
    }else{
        return(0);
    }
}

int main(){
    int  n = NULL;
    arvBusca *r = criarAvrBusca();
    r= inserirArvBusca(r, 10);
    r= inserirArvBusca(r, 30);
    r= inserirArvBusca(r, 9);
    r= inserirArvBusca(r, 7);
    r= inserirArvBusca(r, 40);
    r= inserirArvBusca(r, 35);

     preOrdem(r);
     printf("\n");
    buscarArvBusca(r, 30, n);
    //removerArvBusca(r, 30);
    printf("\n");
    printf(" altura:%d",alturaArvBusca(r));
    printf("\n");
    return 0;
}
