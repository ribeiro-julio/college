// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Musica {
    private String nome;
    private int duracao;
    
    public String getNome() {
        return nome;
    }
    public int getDuracao() {
        return duracao;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    
    public void cadastrarMusica() {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        System.out.println("Cadastrando uma música...");
        
        System.out.println("Digite o nome da música: ");
        try {
            this.setNome(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Digite a duração da música (em segundos): ");
        try {
            this.setDuracao(Integer.parseInt(br.readLine()));
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        } catch(NumberFormatException nfe) {
            duracao = 0;
        }
    }
}
