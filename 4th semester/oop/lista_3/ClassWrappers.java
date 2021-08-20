// Julio Cesar Garcia Ribeiro - RA: 1994484

/*
 * Class Wrappers são classes especiais capazes de converter variáveis primitivas em 
 * objetos. Cada classe possui métodos para que seja possível trabalhar com os tipos
 * primitivos. Utilizando essas classes se pode fazer conversões de um tipo para outro,
 * dentro dos limites de cada classe, por exemplo, string para int ou double, boolean,
 * entre outros.
 * Outra utilidade das Classes Wrappers são de adicionar variáveis primitivas 
 * em elementos que não aceitam variáveis primiticas, como ArrayLists, converter 
 * valores recebidos por caixas de texto (que são recebidas em strings), entre outros.
 * Uma funcionalidade das Classes Wrappers são o boxing e unboxing que facilitam 
 * na hora de instanciar objetos de tipos primitivos, facilitando a sintaxe que deve
 * ser utilizada.
 * Cada tipo primitivo possui o seu empacotador, e neste exemplo se podem observar exemplos
 * de implementação dessas classes.
 * São classes estáticas, podem ser chamadas sem instância.
 * Fontes: http://www.linhadecodigo.com.br/artigo/3667/classes-wrappers-em-java.aspx
 *         https://www.devmedia.com.br/classes-wrapper-explorando-as-classes-que-empacotam-os-tipos-primitivos/24136
 */


public class ClassWrappers {
    public static void main(String args[]) {
        String numero_inteiro = "125";
        String numero_decimal = "125.65";
        String palavra = "Java";
    
        // Conversões de tipos -> string para outros tipos
        Short numeroShort = new Short(numero_inteiro);      // Short 16 bits
        Integer numeroInt = new Integer(numero_inteiro);    // Int 32 bits
        Long numeroLong = new Long(numero_inteiro);         // Long 64 bits
        Float numeroFloat = new Float(numero_decimal);
        Double numeroDouble = new Double(numero_decimal);
        Boolean umBool = new Boolean("true");       // Assume valores true ou false
        Byte umByte = new Byte("1");          // Armazena valores de 1 byte (8 bits)
        
        Character letra = palavra.charAt(1);    // A função charAt() da classes String 
                                                // retorna um objeto do tipo Character
        
        System.out.println("String convertida para Integer: " + numeroInt);
        System.out.println("String convertida para Float: " + numeroFloat);
        System.out.println("String convertida para Double: " + numeroDouble);
        
        System.out.println("Tamanho Short: " + Short.SIZE + " bits");
        System.out.println("Tamanho Int: " + Integer.SIZE + " bits");
        System.out.println("Tamanho Long: " + Long.SIZE + " bits");
        System.out.println("Tamanho Byte: " + Byte.SIZE + " bits");
        
        System.out.println("Segunda letra da palavra Java: " + letra);
        
        if(umBool.equals(true)) {   // Metodo que compara o conteúdo
            System.out.println("Boolean vale true!");
        }
    }
}
