#include <windows.h>
#include <stdio.h>

/*
*Funcion que retornara una llamada del sistema
*@param char* titulo se le asignara una cadena decaracteres
*@param char texto  se le asignara un array de caracteres
*@param int tipo  se le asignara un entero que mostrarala botonera
*@param int icono se le asignara un entero que mostrara un icono
*@return MessageBoxe mostrara una ventana con datos
*/
int mostrarMensaje(char* titulo, char* texto,int tipo, int icono) {
	return MessageBox(NULL, texto, titulo, tipo | icono);
}
/*
*Funcion que concatenara dos arrays de caracteres y lo mostrara en una ventana
*@param int resultado variable entera que sera retornada y se le asignara la funcion mostrarMensaje
*@param int contador variable entera que hara el conteo del bucle
*@param int numBytes variable entera que nos dira cuantas posiciones del array se han usado
*@param char texto[300] array de 300 posiciones inicializado a "bienvenido" y a la que se le concatenara otro array
*@param char usuario[250] array de 250 posiciones a la que se le asignara el usuario
*@return resultado de la concatenacion de los arrays
*/
int saludar() {
	int resultado=0;
	int contador=0;
	int numBytes=0;

	char texto[300]={"Bienvenido"};
	char usuario[250];

	numBytes=250;
	resultado = GetUserName(usuario, &numBytes);

	if(resultado!=0){
		printf("El usuario es: %s\n", usuario);

	}
	else{
		printf("Fallo al obtener el usuario\n");

	}
	for(contador=0;contador<10;contador++){
		printf("%c",texto[contador]);

	}
	texto[numBytes+2]='\n';
	for(contador=0;contador<numBytes;contador++){
		texto[contador+numBytes+3]=usuario[contador];

	}
	resultado=mostrarMensaje("CASO PRÁCTICO UF1287",texto,MB_OKCANCEL,MB_ICONINFORMATION);



			return resultado;
}

/*
*Funcion que mostrara un menu y retornara la eleccion
*@return opcion
*/
int obtenerMenu(){
	int opcion=0;

	printf("1-DIVIDIR DATOS\n");
	printf("2-CODIFICAR DATOS\n");
	printf("3-SALIR\n");
	scanf("%d",&opcion);

	return opcion;
}



void dividirDatos(int array1[7],int array,int *division){
	int resultado=0;

	int contador=0;

	for(contador=0;contador<7;contador++){
		*division=array1[contador]/array;
		division++;


	}
	
	

}

/*
*funcion que mostrara datos por pantalla
*@param int *division puntero a un entero

*/
void mostrarDatos(int *division){
	int contador=0;

	for(contador=0;contador<7;contador++){
	printf("%d \n",*division);
	division++;
	}


}


/*
*funcion que codificara un array sumandole la primera posicion de otro
*@param int array1[7] array de 7 posiciones
*@param int array variable entera
*@param char ascii puntero a un caracter
*@param int resultado variable entera a la que se lsera asignara el array ascii
*@return resultado
*/
int codificarDatos(int array1[7],int array,char *ascii){
	int contador=0;
	

	for(contador=0;contador<7;contador++){
		*ascii=array1[contador]+array;
		ascii++;


	}

	
	

}
/*
*Funcion que mostrara datos por pantalla
*@param char ascci puntero a un caracter
*/
void mostrarDatos2(char *ascii){
	int contador=0;

	for(contador=0;contador<7;contador++){
	printf("%c \n",*ascii);
	ascii++;
	}


}

int main (int arg,char** argv){
	int numero=0;
	int contador=0;
	int resultado=0;
	int array1[7]= {99,113,0,54,1,45,27};
	int array[2]={0,0};
	int division[7];
	char ascii[7];

	printf("CASO PRÁCTICO UF1287\n");
	resultado=saludar();

	printf("\n");
	if(resultado==1){
		resultado=obtenerMenu();

	}



	switch(resultado){
		case 1:
				for(contador=0;contador<2;contador++){
					printf("Introduce un numero entero: ");
					scanf("%d",&numero);
					array[contador]=numero;
					printf("%d-%d\n",contador,numero);
					
				}

				dividirDatos(array1,array[1],division);
				printf("\n");
					
				mostrarDatos(division);


		break;

		case 2:
		for(contador=0;contador<2;contador++){
					printf("Introduce un numero entero: ");
					scanf("%d",&numero);
					array[contador]=numero;
					printf("%d-%d\n",contador,numero);
					
				}
				codificarDatos(array1,array[0],ascii);
				mostrarDatos2(ascii);

		break;

		default:
		break;

	}


	return 0;
}
