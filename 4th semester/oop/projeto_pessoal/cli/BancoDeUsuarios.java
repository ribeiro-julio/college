// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeUsuarios {
    private List<Usuario> usuarios = new ArrayList<>();
    
    public void cadastrar() {
        EntradaDados input = new EntradaDados();
        
        Usuario usuario = new Usuario();
        
        System.out.println("Cadastrando um usuário...");
        
        try {
            usuario.setNome(input.entraString("Digite o nome do usuário: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            usuario = sve.corrigirNomeUsuario(usuario);
        }
        
        try {
            usuario.setEmail(input.entraString("Digite o e-mail do usuário: "));
        } catch(StringsException sve) {
            sve.avisoEmail();
            usuario = sve.corrigirEmailUsuario(usuario);
        }
        
        try {
            usuario.setSenha(input.entraString("Digite a senha para o usuário: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            usuario = sve.corrigirSenhaUsuario(usuario);
        }
        
        try {
            usuario.setAdm(input.entraString("É administrador? (false = não), (true = sim): "));
        } catch(StringsException sve) {
            sve.avisoAdm();
            usuario = sve.corrigirAdmUsuario(usuario);
        }
        
        usuarios.add(usuario);
    }
    
    public Usuario cadastrado(String email, String senha) {
        if(usuarios.isEmpty()) {
            System.out.println("Nenhum usuário cadastrado no sistema");
            return null;
        }
        
        for(Usuario usuario : usuarios) {
            if(usuario.getEmail().equals(email) && usuario.getSenha().equals(senha))
                return usuario;
        }
        
        return null;
    }
}
