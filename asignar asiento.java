/*Una pequeña aereolinea acaba de comprar un ordenador para su nuevo sistema de
reservas automatizado. Se le pide realizar un programa para el nuevo sistema.
Usted va a escribir un applet para asignar asientos en cada vuelo del Ãºnico
avion de las aereolineas (capacidad: 10 asientos).

Su programa debe mostrar las siguientes alternativas: Por favor escriba 1 para
PrimeraClase y Por favor escriba 2 para EconÃ³mico. Si el usuario escribe 1, su
programa debe asignarle un asiento en la secciÃ³n de primera clase (asientos 1 a 5).
Si la persona escribe 2, su programa debe asignarle un asiento en la seccion
economica (asientos 6 a 10). Su programa deberÃ¡ entonces imprimir un pase de
abordaje, indicando el numero del asiento de la persona y si se encuentra en la
seccion de primera clase o economica del avion.

Usar una matriz unidimensional del tipo primitivo boolean para representar la
tabla de asientos del avion.Inicialice, todos los elementos del arreglo con false
para indicar que todos los asientos estan vacios. A medida que se asigne cada
asiento, establezca los elementos correspondientes del arreglo en true para inidicar
que ese elemento ya no esta disponible.

Su programa nunca debera asignar un asiento que ya haya sido asignado. Cuando este
llena la seccion indicar "SU SECCIÃ“N ESTA COMPLETA, RESERVA NO REALIZADA".

NOTA: Utilizar una fuente Monospaced, negrita, tamaÃ±o 12 para el mensaje de solicitud de opciÃ³n y una fuente ARIAL, negrita, tamaÃ±o 14 para mostrar el
billete*/

import java.util.Scanner;

public class Ejercicio8 {
    /**
     * @param opcion 
     * @return  
     */
    public static int menu(){
        
        int opcion;
        
        Scanner entrada= new Scanner(System.in);
        
        System.out.println("Elija una opcion");
        System.out.println("Opcion 1-primera clase");
        System.out.println("Opcion 2-economica ");
       
        opcion=entrada.nextInt();
        
        
        return opcion;
        
        
        
    }
    
    public static boolean buscar(int opcion,boolean asientos[]){
        boolean estaLlena=true;
        
        switch(opcion){
             
            case 1:
                for (int contador = 0; contador<6; contador++) {
                    if(asientos[contador]==false){
                        estaLlena=false;
                    break;
                    }
            
            
                }
                break;
                
            case 2: 
                 for (int contador = 6; contador<10; contador++) {
                    if(asientos[contador]==false){
                    estaLlena=false;
                    break;
                    }
        
                 }
                break;
    
        }
      
        return estaLlena;
    
    }
  
   
    public static int asignar_asiento(int opcion,boolean asientos[]){
        
        int contador=0;
         switch(opcion){
             
            case 1:
                for (contador = 0; contador<=5; contador++) {
                    if(asientos[contador]==false){
                        asientos[contador]=true;
                       
                    break;
                    }
            
            
                }
                break;
                
            case 2: 
                 for (contador = 6; contador<=10; contador++) {
                    if(asientos[contador]==false){
                    asientos[contador]=true;
                      
                    break;
                    }
        
                 }
                break;
    
        }
       
       
         
        
         return contador;
        
    }
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner entrada= new Scanner(System.in);
        int opcion=0;
     
        boolean asientos[] = {false, false,false,false,false,false,false,false,false,false};
        for (int i = 0; i < 11; i++) {
            
        
            opcion=Ejercicio8.menu();
        
       
              if(!Ejercicio8.buscar(opcion,asientos)){
            
                System.out.printf("Su asiento es %d\n",Ejercicio8.asignar_asiento(opcion,asientos));
              
             }else{
                     
              
                    System.out.println("Clase llena");
            }
 
       
       
       
         }
    
    }
    
