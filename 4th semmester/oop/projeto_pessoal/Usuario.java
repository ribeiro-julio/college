// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.InputStreamReader; 
import java.io.BufferedReader;
import java.io.IOException;

public class Usuario extends Pessoa {
    private String email;
    private String senha;
    private boolean adm;
    
    public String getEmail() {
        return email;
    }
    public String getSenha() {
        return senha;
    }
    public boolean getAdm() {
        return adm;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
    public void setSenha(String senha) {
        this.senha = senha;
    }
    public void setAdm(boolean adm) {
        this.adm = adm;
    }
    
    public void cadastrar() {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        System.out.println("Cadastrando um usuário...");
        
        System.out.println("Digite o nome do usuário: ");
        try {
            this.setNome(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Digite o e-mail do usuário: ");
        try {
            this.setEmail(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Digite a senha para o usuário: ");
        try {
            this.setSenha(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("É administrador? (false = não), (true = sim): ");
        try {
            String opcao = br.readLine();
            if(opcao.equals("true") || opcao.equals("false")) {
                this.setAdm(Boolean.parseBoolean(opcao));
            } else {
                System.out.println("Opcao invalida, não é administrador");
                this.setAdm(false);
            }
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
    }
    
    public int noSistema(Usuario usuarios[], String email, String senha) {
        for(int i = 0; i < usuarios.length; i++) {
            if(usuarios[i].getEmail().equals(email) && usuarios[i].getSenha().equals(senha))
                return i;
        }
        return -1;
    }
}
