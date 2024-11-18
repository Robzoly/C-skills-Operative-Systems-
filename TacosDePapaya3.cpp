//@robzoly

#include <stdio.h>
#include <stdlib.h>

int main(){

	int x,y = 0;
	
	printf("Ingresa un número: \n");
	scanf("%d \n", &x);
	printf("Ingresa un segundo número: \n");
	scanf("%d \n", &y);
	
	if (x<y){
	printf("%d es mayor que %d \n", y, x);
	}
	else if (x>y){
	printf("%d es mayor que %d \n", x, y);
	}
	else{
	printf("%d y %d son iguales", x, y);
	}

return 0;
}
