#include <stdio.h>
#include <stdlib.h>
int main(){
   
    int x = 0, y = 0, *p; 
    printf("Valor: %d  valor: %d  valor: %d \n",x, y,*p);
    p = &y;
    printf("Valor p: %p \n",p);
    x = *p;
    printf("Valor x: %d \n",x);
    y++;
     printf("Valor y: %d \n",y);
     (*p)++;
     printf("Valor p: %d \n",*p);
     (*p) += x;
      printf("Valor p: %d \n",*p);
      x = *p +3;
      printf("Valor x: %d \n",x);
    return 0;
}
