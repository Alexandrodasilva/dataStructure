#include<stdio.h>
#include<sdt.h>
#include<stdlib.h>

struct funcionario{
char nome[50];
int id;
int idade;
};

typedef struct fila Fila;

struct elemento{
	struct funcionario dadosFunc;
	struct elemento *prox;
};

struct fila{
	struct elemento *inicio;
	struct elemento *final;
};

typedef struct elemento elem;

Fila* criaFila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f =! NULL){
		f->final = NULL;
		f->inicio = NULL; 
	}
	return f;
}
 
void liberaFila(Fila* fi){ 
	if(fi* =! NULL){
		elem* no; 
		while(fi-> inicio =! NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);  
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
int InseriFila(Fila* fi, struct funcionario func ){
	if(fi == NULL){
		return 0;
	}
	elem *no = (elem*) malloc(sizeof(elem));
	if(no == NULL){
		return 0;
	} 
	no->dadosFunc = func;
	no->prox = NULL;
	if(fi->final == NULL){
		fi->inicio = no;
	}else{
		fi->final->prox = no;
		fi->final = no;
	}
	return 1; 
}

void ImprimeFila(Fila* fi){
	elem *p;
	printf("fila:\n");
	if(FilaVazia(fi)){
		return;
	}
	for(p = fi->inicio; p != NULL; p = p->prox){
		printf("%f\n", p->dadosFunc);
	}
}


int main(){
	Fila *fi;
	fi = criaFila();
	int x = InseriFila(fi, alexandro, 1234, 24); 
	int x = InseriFila(fi, flavia, 5679, 26); 
	int x = InseriFila(fi, maria, 3461, 42); 
	int x = InseriFila(fi, valeria, 9870, 22); 
	int x = InseriFila(fi, veronica, 7569, 20);
	//int x = FilaVazia(fi); 
	ImprimeFila(fi);
  printf("\n");
  printf("\n");
  printf("\n");
	return(0);
}
