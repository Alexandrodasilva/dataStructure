#include<stdio.h>
int fib(int n){
    if(n == 1 || n == 0){
	    return 1;
	}
    else{				
	    return fib (n - 1) + fib (n - 2);
    }
}

int main (){
  int n;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
      fib (i);  
      printf("%d, ", fib(i));
  }
  return 0;
}

----------------------------------------------------------------------------------
#include<stdio.h>
int main(){
	int n, num, a, b, i;
	scanf("%d", &n);
	a = 1; b = 0; i;
	for(i = 0 ; i < n; i++){
	    printf("%d, ", a);
	    num = a + b;
	    b = a;
	    a = num;
	 }
}
