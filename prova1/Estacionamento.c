#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct funcionario{
char nome[50];
int id;
int idade;
struct funcionario *prox;
};

typedef struct fila Fila;

struct fila{
	struct funcionario *inicio;
	struct funcionario *final;
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
		struct funcionario* mo; 
		while(fi-> inicio != NULL){
			mo = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(mo);  
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
void InseriFila(Fila* fi, char *NOME, int ID, int IDADE){
    struct funcionario  *no;
    struct funcionario *aux = fi->final;
	no = (struct funcionario*) malloc(sizeof( struct funcionario));
	if(no == NULL){
		return;
	}
    strcpy(no->nome, NOME); 
	no->id = ID;
	no->idade = IDADE;
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
	struct funcionario *p = fi->inicio;
	printf("fila de funcionarios:\n");
	if(FilaVazia(fi)){
		printf("lista vazia");
	}
    while(p != NULL){
        printf("funcionário de nome %s (ID = %d; IDADE: %d) Cadastrado; \n", p->nome, p->id, p->idade);
        p = p->prox;
    }
}

//-----------------------------pilha de carro-------------------------------------------------------------
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

int main(){
	Fila *fi;
	pilhaC *pi;
	fi = criaFila();
	pi = criarPilha();
	InseriFila(fi,"alexandro", 1234, 24); 
	InseriFila(fi, "alex", 5679, 26); 
	InseriFila(fi, "sandro", 3461, 42); 
	InseriFila(fi, "gol", 9870, 22); 
	InseriFila(fi, "venom", 7569, 20);
	ImprimeFila(fi);
    liberaFila(fi);
 	ImprimeFila(fi);
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
  printf("\n");
	return(0);
}
