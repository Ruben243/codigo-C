#include <stdio.h>
#include <stdlib.h>


int moneda;
int Cantidad=0;
char salir=0;

int caraCruz (int moneda){
	if(moneda==0){
		return 1;
	}else
		return 0;
	
}

int main(int argc, char *argv[]){

	
	while (salir!='s' && salir!='S'){
		
		printf("\nApuesta tu cantidad...: ");
		scanf("%d",&Cantidad);
		
		moneda=rand()%2;
		
		switch(caraCruz(moneda)){
	
			case 1:
				printf("\nHa salido CARA ganas el doble");
				printf("\nHas ganado %d",Cantidad*2);
			break;
		
			default:
				printf("\nHa salido CRUZ no ganas nada ");
		}
	
	
		
	 }	
		
		printf("\n¿Quiere terminar S/N");
		scanf("%c",&salir);
	
	return 0;

}
