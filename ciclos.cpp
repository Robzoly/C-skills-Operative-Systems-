//@robzolyxx

#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, count, res=0;
	

	printf("Ingresa un número: ");
	scanf("%d \n", &num);

	while(count<=10){
	res=num*count;
	printf("%d X %d = %d \n",num, count, res);
	count++;
	}

return 0;
}
