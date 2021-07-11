// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ExString {
    public static void main(String args[]) {
        InputStreamReader c = new InputStreamReader(System.in);
        BufferedReader cd = new BufferedReader(c);
        
        String frase = new String();
        char letra = '\0';
        int count = 0;
        
        System.out.println("Digite uma frase:");
        try {
            frase = cd.readLine();
        }
        catch(IOException e) {
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        frase = frase.toLowerCase();
        
        System.out.println("Digite uma letra:");
        try {
            letra = (char)cd.read();
        }
        catch(IOException e) {
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        letra = Character.toLowerCase(letra);
        
        for(int i = 0; i < frase.length(); i++) {
            if(Character.compare(frase.charAt(i), letra) == 0) {
                count++;
                System.out.println("Letra encontrada na posicao frase[" + i + "]");
            }
        }
        
        if(count == 0)
            System.out.println("Letra nao foi encontrada na frase");
        else
            System.out.println("A letra " + letra + " foi encontrada " + count + " vezes na frase");
    }
}
