#include <windows.h>
#include <stdio.h>


int mostrarMensaje(char* titulo, char* texto,int tipo, int icono) {
	return MessageBox(NULL, texto, titulo, tipo | icono);
}

/**
*funcion que obtendra el nombre del equipo,del usuario,el tiempo de actividad y el directorio
*@param int hora variable entera que recibira la suma de dos enteros (horas+49)
*@param int nCaracteres
*@param int contador variable entera a la que se le asignara el numero de veces que se ejecuta un bucle y se usara para elegir la posicion de los arrays
*@param char nombrepc array de 250 posiciones al que se le asignaran caracteres
*@param char usuario  array de 250 posiciones al que se le asignaran caracteres
*@param char directorio  array de 500 posiciones al que se le asignaran caracteres
*@param char array  array de 40 posiciones al que se le asignara la concatenacion de todos los demas arrays
*@param int numBytes variable entera a la que se le asignara el numero de bytes usados en el array
*@param int numBytes1 variable entera a la que se le asignara el numero de bytes usados en el array
*@param int numBytes2 variable entera a la que se le asignara el numero de bytes usados en el array
*@param int numBytes3 variable entera a la que se le asignara el numero de bytes usados en el array
*@param int resultado variable entera que recibira el retorno de las llamadas del sistema
*@param int tiempoMs variable entera que recibira tiempo en milisegundos
*@param int segundos variable entera que recibira tiempo calculado en segundos
*@param int minutos variable entera que recibira tiempo calculado en minutos
*@param int horas variable entera que recibira el tiempo calculado en horas
*@see <windows.h>
*/
void obtenerUsuario() {
	int hora=0;
	int nCaracteres=0;
	int contador=0;
	char nombrepc[250];
	char usuario[250];
	char directorio[500];
	for(contador=0;contador<500;contador++){
		directorio[contador]='\0';
	}
	char array[40];
	int numBytes = 0;
	int numBytes1=0;
	int numBytes2=0;
	int numBytes3=0;
	int resultado = 0;
	int tiempoMs = 0;
	int segundos = 0;
	int minutos = 0;
	int horas = 0;
	
	numBytes=250;
	
	resultado = GetComputerName(nombrepc, &numBytes);
	numBytes1=numBytes;
	if(resultado!=0){
		printf("El pc es: %s\n", nombrepc);
		
	}
	else{
		printf("Fallo al obtener el pc\n");
		
	}
	

	numBytes=250;
	resultado = GetUserName(usuario, &numBytes);
	numBytes2=numBytes;
	if(resultado!=0){
		printf("El usuario es: %s\n", usuario);
		
	}
	else{
		printf("Fallo al obtener el usuario\n");
		
	}
	
	numBytes=500;
	resultado = GetCurrentDirectory(&numBytes,directorio);
	numBytes3=numBytes;
	if(resultado!=0){
		printf("El directorio es: %s\n", directorio);
	
	}
	else{
		printf("Fallo al obtener el directorio\n");
		
	}
	
	tiempoMs = GetTickCount();

	tiempoMs = tiempoMs / 1000;

	horas = (tiempoMs / 3600);
	tiempoMs -= (horas * 3600);

	minutos = (tiempoMs / 60);
	tiempoMs -= (minutos * 60);

	segundos = tiempoMs;

	printf("Tiempo encendido: %d horas %d minutos %d segundos\n", horas, minutos, segundos);
	
	
	
    Beep(748, 1000);
	
	
	for(contador=0;contador<numBytes1;contador++){
		array[contador]=nombrepc[contador];
	
	}

	array[numBytes1]='\n';
	for(contador=0;contador<numBytes2;contador++){
		array[contador+numBytes1+1]=usuario[contador];
		
	}
	array[contador+numBytes1]='\n';	
	for(contador=0;contador<500;contador++){
		if(directorio[contador]!='\0'){
			nCaracteres++;
		}
	}
	
	for(contador=0;contador<40;contador++){
		array[contador+numBytes1+1+numBytes2]=directorio[contador];
		
	}

	hora=horas+48;
	array[numBytes1+numBytes2+nCaracteres+1]='\n';
	for(contador=0;contador<40;contador++){
		array[numBytes1+numBytes2+nCaracteres+2]=hora;
	}
	
	mostrarMensaje("Ventana sin icono",array ,MB_OK,MB_ICONINFORMATION);
	
}


/**
*Funcion que creara un directorio,se movera a ese directorio,copiara un archivo y borrara el de origen
*@param int resultado variable entera que recibira el retorno de las llamadas del sistema
*@see <windows.h>
*/
void obtenerProcesos(){
	int resultado=0;
	
	resultado=CreateDirectory("C:\\cygwin\\home\\usuario\\procesos",0);
	

	if(resultado==1){
		printf("el directorio ha sido creado\n");
	}
	
	SetCurrentDirectory("C:\\cygwin\\home\\usuario\\procesos");
	resultado=CopyFile("C:\\Users\\usuario\\Desktop\\procesos.txt","procesos.txt", FALSE);
	if(resultado==1){
		printf("el archivo a sido creado\n");
}
	resultado=mostrarMensaje(NULL,"¿Desea eliminar el archivo?",MB_YESNO,MB_ICONINFORMATION);
	if(resultado==6){
		resultado=DeleteFile("C:\\Users\\usuario\\Desktop\\procesos.txt");
		if(resultado==1){
		printf("el archivo a sido borrado");
		}
	}else{
		printf("el archivo no se a eliminado");
	}

}


/**
*funcion que mostrara una ventana de error y te preguntara si quieres apagar el sistema en menos de un minuto,si se producen 3 respuestas negativas,se mostrara una ventana de ayuda
*@param int resultado variable entera que recibira el retorno de las llamadas del sistema
*@param int negativa variable entera a la que se le asignara el contero de un bucle
*@see <windows.h>
*/
void apagar(){
	int resultado=0;
	int negativa=0;
	resultado=mostrarMensaje("Ventana con icono de error grave", "¡Error grave!el sistema se apagara en 1 minuto", MB_YESNO, MB_ICONERROR);
	
	
	
	for(negativa=0;negativa<3;negativa++){
		
		printf("%d\n",resultado);
		if(resultado==6){
			Sleep(50);
			mostrarMensaje(NULL,"APAGADO",MB_OK,MB_ICONINFORMATION);
			negativa=3;
		}else{
			Sleep(10);
			mostrarMensaje("Ventana con icono de error grave", "¡Error grave!el sistema se apagara en 1 minuto", MB_YESNO, MB_ICONERROR);
		}
	}	
	mostrarMensaje(NULL,"¿necesita ayuda?",MB_YESNO,MB_ICONINFORMATION);
	 Beep(748, 1000);

}
int main(){

	obtenerUsuario();
	obtenerProcesos();
	apagar();

	
	
	return 0;	
}
