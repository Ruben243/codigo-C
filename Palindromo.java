
import java.util.Scanner;


/**
 *
 * @author Alumno33
 */
public class Palindromo {

    /**
     * @param args the command line arguments
     */
    public static boolean esPalindromo(char []cadena){
        for (int contador= 0; contador <(Math.ceil(cadena.length/2));contador++) {
            if(cadena[contador]==cadena[cadena.length-contador-1]){
             return true;
            } 
        
           
       }
        return false;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        char []cadena = null;
        String palabra;
        Scanner entrada=new Scanner(System.in);
        
        
        System.out.println("Introduce una palabra");
        palabra=entrada.next();
        
        
        
        for (int i = 0; i < 10; i++) {
           cadena=palabra.toCharArray();
        }
        
         if ( Palindromo.esPalindromo(cadena)){
                System.out.println("Es palindromo");
            }else{
        System.out.println("No es palindromo");
         }
    }
    
   
   
}
