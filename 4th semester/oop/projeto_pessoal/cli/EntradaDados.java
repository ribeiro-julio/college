// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EntradaDados {
    private InputStreamReader isr = new InputStreamReader(System.in);
    private BufferedReader br = new BufferedReader(isr);
        
    public String entraString(String descricao) {
        if(descricao != null)
            System.out.println(descricao);
        
        try {
            return br.readLine();
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
            return null;
        }
    }
    
    public int entraInt(String descricao) {
        if(descricao != null)
            System.out.println(descricao);
        
        try {
            return Integer.parseInt(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
            return -1;
        } catch(NumberFormatException nfe) {
            System.out.println("Entrada deve ser um número inteiro (definido -1)");
            return -1;
        }
    }
}
