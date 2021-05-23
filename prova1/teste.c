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
 
/*void liberaFila(Fila* fi){ 
	if(fi != NULL){
		elem* mo; 
		while(fi-> inicio != NULL){
			mo = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(mo);  
		}
		free(fi);
	}
}*/
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
		return;
	}
    while(p != NULL){
        printf("%s %d %d \n", p->nome, p->id, p->idade);
        p = p->prox;
    }
}


int main(){
	Fila *fi;
	fi = criaFila();
	InseriFila(fi,"alexandro", 1234, 24); 
	InseriFila(fi, "alex", 5679, 26); 
	InseriFila(fi, "sandro", 3461, 42); 
	InseriFila(fi, "gol", 9870, 22); 
	InseriFila(fi, "venom", 7569, 20);
	ImprimeFila(fi);
    
  printf("\n");
	return(0);
}
