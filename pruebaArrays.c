
#include <stdio.h>
#include <stdlib.h>

#define filas 3
#define columnas 4

int MatrizA[filas][columnas];
int MatrizB[filas][columnas];

void SoliciteArray(int[][columnas]);
void VisualArray(int[][columnas]);
void Sum(int[][columnas],int [][columnas]);
void Res(int[][columnas],int[][columnas]);
void Tras(int[][columnas]);

// Funcion para solicitar los datos del array

void SoliciteArray(int Matriz[][columnas]){
	int fila=0;
	int columna=0;
	
	printf("\n");
	for (fila=0;fila<filas;fila++){
		for (columna=0;columna<columnas;columna++){
		printf("Posicion %d - %d:",fila,columna);
		scanf("%d",&Matriz[fila][columna]);
		}
	
	}
	printf("\n");
}

// Funcion para visualizar los datos de la matriz

void VisualArray(int Matriz[][columnas]){
	int fila=0;
	int columna=0;
	
	printf("\n");
	for (fila=0;fila<filas;fila++){
		for (columna=0;columna<columnas;columna++){
			printf("%5d",Matriz[fila][columna]);
		}
		printf("\n");
	}
}
// Funcion para sumar matrices

void Sum(int Matriz1[][columnas],int Matriz2[][columnas]){
	int fila=0;
	int columna=0;
	int resultado[filas][columnas];
	
	for (fila=0;fila<filas;fila++){
		for (columna=0;columna<columnas;columna++){
			resultado[fila][columna]=Matriz1[fila][columna]+Matriz2[fila][columna];
			
		}
	}
	VisualArray(resultado);
}

// Funcion para restar matrices

void Res(int Matriz1[][columnas],int Matriz2[][columnas]){
	int fila=0;
	int columna=0;
	int resultado[filas][columnas];
	
	for (fila=0; fila<filas;fila++){
		for (columna=0;columna<columnas;columna++){
			resultado[fila][columna]=Matriz1[fila][columna]- Matriz2[fila][columna];
		}
		VisualArray(resultado);
	}
	
	
}





void Tras(int Matriz[][columnas]){
	int fila=0;
	int columna=0;
	
	printf("\nVisualizar la matriz normal");
	VisualArray(Matriz);
	printf("\nVisualizar la traspuesta de la matriz\n");
		for (fila= 0; fila<columnas;fila++){
			for (columna=0; columna<filas;columna++){
				printf("%5d",Matriz[columna][fila]);
			}
			printf("\n");
		}
}


int main(int arg,char** argv){
	
	int MatrizA[filas][columnas];
	int MatrizB[filas][columnas];
	
	printf("Solicitando datos para la primera matriz");
	
	SoliciteArray(MatrizA);
	
	printf("Solicitando datos para la segunda matriz");
	
	SoliciteArray(MatrizB);
	
	VisualArray(MatrizA);
	
	VisualArray(MatrizB);
	
	printf("\nLa suma de las matrices es la siguiente :\n");
	
	Sum(MatrizA,MatrizB);
	
	printf("\nLa resta de las matrices es la siguiente: \n");
	
	Res(MatrizA,MatrizB);
	
	printf("\nTranspuesta de la matriz a \n");
	Tras(MatrizA);
	printf("\nTranspuesta de la matriz b\n");
	Tras(MatrizB);
	return 0;
	
}

