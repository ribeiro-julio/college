// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.NumberFormatException;

public class G1 {
    public static void main(String args[]) {
        InputStreamReader c = new InputStreamReader(System.in);
        BufferedReader cd = new BufferedReader(c);
        
        int a = 0, b = 0;
        int opcao = 0;
        
        System.out.println("Entre com o valor de a: ");
        try{
            a = Integer.parseInt(cd.readLine());
        }
        catch(IOException e){
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        catch(NumberFormatException nfe) {
            System.out.println("Valor de a inválido");
            System.exit(2);
        }
        
        System.out.println("Entre com o valor de b: ");
        try{
            b = Integer.parseInt(cd.readLine());
        }
        catch(IOException e){
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        catch(NumberFormatException nfe) {
            System.out.println("Valor de b inválido");
            System.exit(2);
        }
        
        System.out.println("Menu de opções:");
        System.out.println("1 - Somar (a+b)");
        System.out.println("2 - Multiplicar (a*b)");
        System.out.println("3 - Subtrair (a-b)");
        System.out.println("4 - Dividir (a/b)");
        System.out.println("Escolha uma opção:");
        try{
            opcao = Integer.parseInt(cd.readLine());
        }
        catch(IOException e){
            System.out.println("Erro de entrada");
            System.exit(1);
        }
        catch(NumberFormatException nfe) {
            System.out.println("Opcao deve ser um inteiro");
            System.exit(2);
        }
        
        switch(opcao) {
            case 1:
                System.out.println("A soma de a + b e: " + (a+b));
                return;
            case 2:
                System.out.println("A multiplicacao de a * b e: " + (a*b));
                return;
            case 3:
                System.out.println("A subtracao de a - b e: " + (a-b));
                return;
            case 4:
                System.out.println("A divisao de a / b e: " + (a/b));
                return;
            default:
                System.out.println("Opcao invalida");
        }
    }
}
