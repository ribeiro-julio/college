// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.NumberFormatException;

public class Matriz1 {
    public static void main(String args[]) {
        InputStreamReader c = new InputStreamReader(System.in);
        BufferedReader cd = new BufferedReader(c);
        
        int tamanho = 5;
        int vetor[] = new int[tamanho];
        
        System.out.println("Entre com os valores:");
        for(int i = 0; i < tamanho; i++) {
            System.out.println("vetor[" + i + "]: ");
            try{
                vetor[i] = Integer.parseInt(cd.readLine());
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

        System.out.println("--------------------------");

        for(int i = tamanho-1; i >= 0; i--)
            System.out.println("vetor[" + i + "]: " + vetor[i]);
    }
}