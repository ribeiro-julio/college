// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.NumberFormatException;

public class H1 {
    public static void main(String args[]) {
        InputStreamReader c = new InputStreamReader(System.in);
        BufferedReader cd = new BufferedReader(c);
        
        int a = 0;
        
        System.out.println("Entre com o valor");
        try{
            a = Integer.parseInt(cd.readLine());
        }
        catch(IOException e){
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        catch(NumberFormatException nfe) {
            System.out.println("Valor inválido");
            System.exit(2);
        }
        
        System.out.println(a % 2 == 0 ? "Numero par" : "Numero impar");
    }
}
