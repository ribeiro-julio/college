import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Musico extends Pessoa {
    private String funcao;
    
    public String getFuncao() {
        return funcao;
    }
    
    public void setFuncao(String funcao) {
        this.funcao = funcao;
    }
    
    public void cadastrar() {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        System.out.println("Cadastrando um musico...");
        
        System.out.println("Digite o nome do musico: ");
        try {
            this.setNome(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Digite a função do musico: ");
        try {
            this.setFuncao(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
    }
}
