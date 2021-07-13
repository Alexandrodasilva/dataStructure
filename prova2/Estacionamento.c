#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    int num;
    printf("\n");
   do{
        printf( "1: CADASTRAR CARRO E ESTACIONAR:\n"
                "2: BUSCAR CARRO E RETIRAR DO ESTACIONAMENTO:\n"
                "3:NÚMERO MÉDIO DE PESQUISAS DE ENTRADAS E QUAL MÉTODO DE BUSCA MELHOR\n"
                "4: NÚMERO MÉDIO DE PESQUISAS DE SAÍDAS E QUAL MÉTODO DE BUSCA MELHOR\n"
                "0: SAIR\n");

        scanf("%d", &num);

        switch ( num){
                case 1:
                   printf("arvoreAVL,arvoreBinariaBusca,Fila");
                   break;
                case 2:
                    printf("digite a placa do carro para estacionar:");
                    break;
                case 3:
                    printf("digite a placa do carro para estacionar:");
                break;
                case 4: 
                    break;
         }
   }while(num != 0);
}