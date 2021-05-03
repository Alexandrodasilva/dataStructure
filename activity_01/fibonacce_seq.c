#include<stdio.h>
int main(){
	int n, num, a, b, i;
	scanf("%d", &n);					//1
	a = 1; 										//1
	b = 0; 										//	1							
	for(i = 0 ; i < n; i++){			//1; n+1, 2*n						
	    num = a + b;					//	2*n	
		printf("%d, ", num);								
	    b = a;									// 	n					 
	    a = num;							//	 n	
				  
	 }
}
