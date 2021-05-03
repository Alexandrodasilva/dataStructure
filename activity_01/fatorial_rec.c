#include <stdio.h>
int fatorial(int n){
  int fat;
  if ( n <= 1 ){     
    return (1);  
  }
  else{
    fat = n * fatorial(n - 1);
    return (fat);
  }
}

int main(void){
  int fat;
  fat = 4; 
   fatorial(fat);
  printf("  Resultado: %d \n",  fatorial(fat));
  return 0;
}

