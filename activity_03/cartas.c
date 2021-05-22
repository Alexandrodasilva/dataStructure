#include <stdio.h>
#include<stdlib.h>



float obtendoCartas(float *cartas){
   int i, j;
    float pedra=  1.0, papel= 1.5, tesoura= 2.0, lagarto= 2.5, spock= 3.0;
      
    float carta[13];

    for(i=1; i <= 13; i++ ){
          
            carta[i] = i*pedra;
  
    }
    for(i=1; i <= 13; i++ ){
          
            cartas[i] = carta[i];
  
    }


     for(i=1; i <= 13; i++ ){
          
            carta[i] = i*papel;
  
    }
    for(i=1; i <= 13; i++ ){
          
            cartas[i + 13] = carta[i];
  
    }

     for(i=1; i <= 13; i++ ){
          
            carta[i] = i*tesoura;
  
    }
    for(i=1; i <= 13; i++ ){
          
            cartas[i + 26] = carta[i];
  
    }


     for(i=1; i <= 13; i++ ){
          
            carta[i] = i*lagarto;
  
    }
    for(i=1; i <= 13; i++ ){
          
            cartas[i + 39] = carta[i];
  
    }


     for(i=1; i <= 13; i++ ){
          
            carta[i] = i*spock;
  
    }
    for(i=1; i <= 13; i++ ){
          
            cartas[i + 52] = carta[i];
  
    }empilhar (&minhapilha, valor);
    
   // for(i=1; i <= 65; i++ ){
    //  printf("%.1f\n", cartas[i]);
    //}
}

struct Pilha {

	int topo; /* posiÃ§Ã£o elemento topo */
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )

      return 1;   // true

   else

      return 0;   // false

}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capa - 1)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){

   return p->pElem [p->topo];

}

int main(void){
  float cartas[65];
  //obtendoCartas(cartas);
  criarpilha (&minhapilha, 65);
  empilhar (&minhapilha, valor);
  return 0;
}