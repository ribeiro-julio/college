// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.NumberFormatException;

public class Matriz2 {
    public static void main(String args[]) {
        InputStreamReader c = new InputStreamReader(System.in);
        BufferedReader cd = new BufferedReader(c);
        
        int tamanhoi = 3;
        int tamanhoj = 3;
        int vetor[][] = new int[tamanhoi][tamanhoj];
        
        System.out.println("Entre com os valores:");
        for(int i = 0; i < tamanhoi; i++) {
            for(int j = 0; j < tamanhoj; j++) {
                System.out.println("vetor[" + i + "][" + j + "]: ");
                try{
                    vetor[i][j] = Integer.parseInt(cd.readLine());
                }
                catch(IOException e){
                    System.out.println("Erro de entrada");
                    System.exit(1);
                }
                catch(NumberFormatException nfe) {
                    System.out.println("Valor deve ser um inteiro");
                    System.exit(2);
                }
            }
        }

        System.out.println("--------------------------");

        for(int i = tamanhoi-1; i >= 0; i--) {
            for(int j = tamanhoj-1; j >= 0; j--)
                System.out.println("vetor[" + i + "][" + j+ "]: " + vetor[i][j]);
        }
    }
}
