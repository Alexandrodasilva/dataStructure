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
    printf("Carro %d  entrou;\n", num);
}

void imprimir(pilhaC *pi){
    Carro *aux = pi->topo;
    if(aux == NULL){
        printf("Estacionamento vazio!\n");
        return;
    }else{
        printf("\n Lista de carros estacionados:\n");
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

//----------------------Arvore de Busca---------------------------------------------------------------

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

void buscarArvBusca(arvBusca *r, int num, int x){
    x++;
    if(r == NULL){
       return(printf("\nNão contem nessa estrutura!\n")); 
    }
    else if(num < r->number){
        return(buscarArvBusca(r->esq, num, x));
    }
    else if(num > r->number){
        return(buscarArvBusca(r->dir, num, x));
    }else if(num == r->number){
        return(printf("%d encontrado na arvore! E número de comprações é:%d\n", r->number, x));
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

//---------------------------------FILA---------------------------------------------------------------------
typedef struct funcionario{;
int placa;
struct funcionario *prox;
}Funcionario;

typedef struct fila Fila;

struct fila{
	Funcionario *inicio;
	Funcionario *final;
};

Fila* criaFila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->final = NULL;
		f->inicio = NULL; 
	}
	return f;
}
 
void liberaFila(Fila* fi){ 
	if(fi != NULL){
		Funcionario* No; 
		while(fi-> inicio != NULL){
			No = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(No);  
		}
		free(fi);
	}
}
int FilaVazia(Fila* fi){
	if(fi == NULL){
		return 1;
	}
	if(fi->inicio == NULL){
		return 1;
	}
	return 0;
}
void InseriFila(Fila* fi, int PLACA){
    Funcionario  *no;
    Funcionario *aux = fi->final;
	no = (Funcionario*) malloc(sizeof( Funcionario));
	if(no == NULL){
		return;
	}
	no->placa = PLACA;
	no->prox = NULL;
    if(FilaVazia(fi)){
		fi->inicio = no;
        fi->final = no;
        return;
	}
    else{ 
		aux->prox = no;
        fi->final = no;
	}
	return;
}

void ImprimeFila(Fila* fi){
	Funcionario *p = fi->inicio;
	//printf("fila de funcionarios:\n");
	if(FilaVazia(fi)){
		printf("lista vazia");
	}
    while(p != NULL){
        printf("\n; IDAD: %d", p->placa);
        printf("\n");
        p = p->prox;
    }
}


void   ordenarIDADE(Fila* fi){
    printf("Ordenação usada: IDADE;\n");
    Funcionario *aux = fi->inicio;
    Funcionario *aux2;
	int PLACA;	
    while(aux != NULL){
        aux2 = aux->prox;
        while(aux2 != NULL){
    		 if((aux->placa) > (aux2->placa)){	 
				PLACA = aux->placa;
				aux->placa = aux2->placa;
				aux2->placa = PLACA; 
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
		
    }
    return(fi);
}

int main(void){
    int x= NULL; // para busca da arvore
    int num; // para do/while
    int placa, s; // para inserção da placa do carro nas estruturas
    Fila *fi;
	fi = criaFila();
    arvBusca *r = criarAvrBusca();
    pilhaC *pi;
    pi = criarPilha();

    printf("\n");
   do{
        printf( "1: CADASTRAR CARRO E ESTACIONAR:\n"
                "2: BUSCAR CARRO E RETIRAR DO ESTACIONAMENTO:\n"
                "0: SAIR\n");

        scanf("%d", &num);

        switch ( num){
                case 1:
                    printf("insira o numero da placa do carro para cadastrar: ");
                    printf("\n");
                    scanf("%d", &placa);
                    empilharC(pi, placa);
                    InseriFila(fi,placa); 
                    r= inserirArvBusca(r, placa);
                   break;
                case 2:
                    printf("Digite a para busca nas três estruturas: ");
                    scanf("%d", &s);
                    buscarArvBusca(r, s, x);
                    //buscaPilha
                    //buscaFila

                    break;
         }
   }while(num != 0);
}