#include <windows.h>
#include <stdio.h>



int mostrarMensaje(char *titulo, char *texto, int tipo, int icono)
{
    return MessageBox(NULL, texto, titulo, tipo | icono);
}

/**
*funcion que obtendra el nombre del equipo,del usuario y el directorio y los mostrara en la ventana grafica
*@param int contador variable entera a la que se le asignara el numero de veces que se ejecuta un bucle y 
*se usara para elegir la posicion de los arrays
*@param char nombrepc array de 250 posiciones al que se le asignaran caracteres pertenecientes al nombre del pc
*@param char usuario  array de 250 posiciones al que se le asignaran caracteres pertenecientes al nombre de usuario
*@param char directorio  array de 500 posiciones al que se le asignaran caracteres pertenecientes al directorio actual
*@param char array  array de 40 posiciones al que se le asignara la concatenacion de todos los demas arrays
*@param int numBytes variable entera a la que se le asignara el numero de bytes usados en el array y servira para marcar el
*fin de un array y el principo de otro en la concatenacion de arrays sumando 1
*@param int numBytes1 variable entera a la que se le asignara el numero de bytes usados en el array y que se igualara a numBytes
*@param int numBytes2 variable entera a la que se le asignara el numero de bytes usados en el array y que se igualara a numBytes
*@see <windows.h>
*/

int obtenerUser()
{  
    int nCaracteres = 0;
    int contador = 0;
    char nombrepc[250];
    char User[250];
    char directorio[500];

    for (contador = 0; contador < 500; contador++)
    {
        /* code */
        directorio[contador] = '\0';
    }

    char array[40];
    int numBytes = 0;
    int numBytes1 = 0;
    int numBytes2 = 0;
    int resultado = 0;
  

    numBytes = 250;

    resultado = GetComputerName(nombrepc, &numBytes);
    numBytes1 = numBytes;
    if (resultado != 0)
    {

        printf("El pc es %s\n", nombrepc);
    }
    else
    {
        /* code */
        printf("Fallo al obtener el pc\n");
    }

    numBytes = 250;
    resultado = GetUserName(User, &numBytes);
    numBytes2 = numBytes;

    if (resultado != 0)
    {

        printf("El usuario es: %s\n", User);
    }
    else
    {
        /* code */
        printf("Fallo al obtener el usuario\n");
    }
    numBytes = 500;
    resultado = GetCurrentDirectory(&numBytes, directorio);

    if (resultado != 0)
    {

        printf("El el directorio es: %s\n", directorio);
    }
    else
    {
        /* code */
        printf("Fallo al obtener el directorio\n");
    }

    Beep(748, 1000);//emitira un sonido

    for (contador = 0; contador < numBytes1; contador++)
    {
        /* code */
        array[contador] = nombrepc[contador];
    }

    array[numBytes1] = '\n';

    for (contador = 0; contador < numBytes2; contador++)
    {
        /* code */
        array[contador + numBytes1 + 1] = User[contador];
    }



    array[contador+numBytes1] = '\n';
    for (contador= 0;contador< 500; contador++)
    {
        /* code */
        if (directorio[contador]!='\0'){
            nCaracteres++;
        }
    }
    

    for (contador = 0; contador < 40; contador++)
    {
        /* code */
        array[contador + numBytes1 + 1 + numBytes2] = directorio[contador];
    }

    mostrarMensaje("Prueba ventana C", array, MB_OKCANCEL, MB_ICONINFORMATION);
}

int main(int arg, char **argv)
{
    int resultado = 0;

    resultado = obtenerUser();

    return 0;
}