#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
int dados;
int altura;
struct arvore *dir;
struct arvore *esq;
} Arv;

Arv *raiz;

// Retorna o maior valor entre x e y

int max(int x, int y) {
if (x > y)
return x;
return y;
}

//Retorna a altura do nó

int altura_No(Arv *arv) {
if (arv == NULL) {
return 0;
}
return arv->altura;
};

// Aplica a altura à todos os nós da árvore

int aplicaALTURA(Arv* arv) {
arv->altura = max(altura_No(arv->esq), altura_No(arv->dir)) + 1;
return arv->altura;
}

//Retorna o fator de balanceamento do nó

int fat_bal(Arv* arv) {
return (altura_No(arv->esq) - altura_No(arv->dir));
}

Arv* rotacaoEsquerda(Arv *arv) {
Arv *tmp = arv->dir;
arv->dir = tmp->esq;
tmp->esq = arv;
return tmp;
}

Arv* rotacaoDireita(Arv *arv) {
Arv *tmp = arv->esq;
arv->esq = tmp->dir;
tmp->dir = arv;
return tmp;
}

Arv* inserir(Arv** arv, int v) {
if (*arv == NULL) {
Arv No = (Arv) malloc(sizeof (Arv));
No->dados = v;
No->dir = NULL;
No->esq = NULL;
No->altura = 0;
*arv = No;
} else {
Arv *tmp = *arv;
if (v < tmp->dados) {
inserir(&tmp->esq, v);
tmp->altura = aplicaALTURA(tmp);
//rotação
if(fat_bal(tmp) == 2){
if(fat_bal(tmp->esq) == 1){
*tmp = rotacaoDireita(*tmp);
}
(*tmp).esq = rotacaoDireita((*tmp).esq);
*tmp = rotacaoEsquerda(*tmp);
}

    } else {
        inserir(&tmp->dir, v);
        tmp->altura = aplicaALTURA(tmp);
        //rotação
        if(fat_bal(tmp) == -2){
            if(fat_bal(tmp->dir) == -1){
                *tmp = rotacaoEsquerda(*tmp);
            }
            (*tmp).dir = rotacaoEsquerda((*tmp).dir);
            *tmp = rotacaoDireita(*tmp);
        }
    }
}
}

void listar(Arv *arv) {
if (arv != NULL) {
printf(“No = %d, altura = %d, FATBAL = %d\n”, arv->dados, arv->altura, arv->fatbal);
listar(arv->esq);
listar(arv->dir);
}
}

int main() {
raiz = NULL;
int op, valor;
while (1) {
printf("------------------------------"
"\n| 0- Sair;"
"\n| 1- Inserir;"
"\n| 2- Listar;"
"\n------------------------------"
"\n\n| Opcao: “);
scanf(”%d", &op);
switch (op) {
case 0:
exit(0);
break;
case 1:
printf("\nInforme o valor: “);
scanf(”%d", &valor);
inserir(&raiz, valor);
break;
case 2:
if (raiz == NULL) {
printf("\n| Arvore vazia!\n\n");
} else {
printf("\n");
listar(raiz);
printf("\n\n");
}
break;
}
}
}
