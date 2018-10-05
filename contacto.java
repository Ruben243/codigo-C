public class Contacto {
    
    private String nombre;
    private String apellido;
    private String telefono;
    
   
    public Contacto(String nombre, String apellido, String telefono){
        this.setNombre (nombre);
        this.setApellido(apellido);
        this.setTelefono(telefono);
        
    }

   
   public void setNombre(String nombre){
    
       this.nombre=nombre.toUpperCase();
    
   }
   
   public void setApellido (String apellido){
    
       this.apellido = apellido;
  }
   
   
   public void setTelefono(String telefono){
       
    this.telefono="+34" + telefono ;
    
    }
   
   public String getNombre(){
    
    return this.nombre;
    }
   
   public String getApellido(){
    
    return this.apellido;
    }
   
   public String getTelefono(){
    
       return this.telefono;
    
    }
   
   
}

//////////////////////////////////////////////////////////////////


public class pruebaContacto {
    
    public static void main(String[] args) {
        
    Contacto pepe= new Contacto("ruben","perez","65");
        
    
    
        System.out.println("Nombre: " + pepe.getNombre());
        System.out.println("Apellidos: " + pepe.getApellido());
        System.out.println("Telefono: "+ pepe.getTelefono());
        
        
    }
    
}

