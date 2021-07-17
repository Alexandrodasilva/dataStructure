#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct funcionario{
char nome[50];
int id;
int idade;
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
void InseriFila(Fila* fi, char *NOME, int ID, int IDADE){
    Funcionario  *no;
    Funcionario *aux = fi->final;
	no = (Funcionario*) malloc(sizeof( Funcionario));
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
	Funcionario *p = fi->inicio;
	//printf("fila de funcionarios:\n");
	if(FilaVazia(fi)){
		printf("lista vazia");
	}
    while(p != NULL){
        printf("\nFuncionario de nome: %s (ID = %d; IDAD: %d) cadastrado; \n", p->nome, p->id, p->idade);
        printf("\n");
        p = p->prox;
    }
}

void   ordenarID(Fila* fi){
    printf("Ordenação usada: ID;\n");
    Funcionario *aux = fi->inicio;
    Funcionario *aux2;
	char NOME[50];
    int ID;
	int IDADE;	
    while(aux != NULL){
        aux2 = aux->prox;
        while(aux2 != NULL){
    		 if((aux->id) > (aux2->id)){	 
                strcpy( NOME, aux->nome); 
				IDADE = aux->idade;
				ID = aux->id;

                strcpy(aux->nome, aux2->nome);
				aux->idade = aux2->idade; 
				aux->id = aux2->id;

				strcpy(aux2->nome, NOME);
				aux2->idade = IDADE; 
                aux2->id = ID;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
		
    }
    return(fi);
	
}

void   ordenarIDADE(Fila* fi){
    printf("Ordenação usada: IDADE;\n");
    Funcionario *aux = fi->inicio;
    Funcionario *aux2;
	char NOME[50];
    int ID;
	int IDADE;	
    while(aux != NULL){
        aux2 = aux->prox;
        while(aux2 != NULL){
    		 if((aux->idade) > (aux2->idade)){	 
                strcpy( NOME, aux->nome); 
				ID = aux->id;
				IDADE = aux->idade;

               	strcpy(aux->nome, aux2->nome); 
				aux->id = aux2->id;
				aux->idade = aux2->idade;

				strcpy(aux2->nome, NOME);
                aux2->id = ID;
				aux2->idade = IDADE; 
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
		
    }
    return(fi);
	
}

void   ordenarNOME(Fila* fi){
    printf("Ordenação usada: NOME;\n");
    Funcionario *aux = fi->inicio;
    Funcionario *aux2;
	char NOME[50];
    int ID;
	int IDADE;	
    while(aux != NULL){
        aux2 = aux->prox;
        while(aux2 != NULL){
			if(strcmp(aux->nome,aux2->nome) > 0){	 
                strcpy( NOME, aux->nome); 
				ID = aux->id;
				IDADE = aux->idade;

               	strcpy(aux->nome, aux2->nome); 
				aux->id = aux2->id;
				aux->idade = aux2->idade;

				strcpy(aux2->nome, NOME);
                aux2->id = ID;
				aux2->idade = IDADE; 
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
		
    }
    return(fi);
}

int main(void){
    Fila *fi;
	fi = criaFila();
    //INSERINDO FUNCIONARIO
	InseriFila(fi,"alexandro", 1234, 24); 
	InseriFila(fi, "alex", 5679, 26); 
	InseriFila(fi, "sandro", 3461, 42); 
	InseriFila(fi, "gol", 9870, 22); 
	InseriFila(fi, "venom", 7569, 20);
    ImprimeFila(fi);
    //ORDENANDO A FILA DE FUNCIONÁRIO
    ordenarID(fi);
}