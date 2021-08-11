// Julio Cesar Garcia Ribeiro - RA: 1994484

public class StringsException extends Exception {
    private EntradaDados input = new EntradaDados();
    
    public void avisoVazia() {
        System.out.println("Entrada inválida -> Campo não pode ser vazio");
    }
    public void avisoEmail() {
        System.out.println("Email inválido -> Deve estar no formato nome@dominio.com");
    }
    public void avisoAdm() {
        System.out.println("Entrada inválida -> Deve ser true ou false");
    }
    
    public Banda corrigirNomeBanda(Banda banda) {
        try {
            banda.setNome(input.entraString("Digite o nome da banda: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            banda = sve.corrigirNomeBanda(banda);
        }
        return banda;
    }
    public Banda corrigirGeneroBanda(Banda banda) {
        try {
            banda.setGenero(input.entraString("Digite o gênero da banda: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            banda = sve.corrigirGeneroBanda(banda);
        }
        return banda;
    }
    
    public Musica corrigirNomeMusica(Musica musica) {
        try {
            musica.setNome(input.entraString("Digite o nome da música: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musica = sve.corrigirNomeMusica(musica);
        }
        return musica;
    }
    
    public Musico corrigirNomeMusico(Musico musico) {
        try {
            musico.setNome(input.entraString("Digite o nome do músico: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musico = sve.corrigirNomeMusico(musico);
        }
        return musico;
    }
    public Musico corrigirFuncaoMusico(Musico musico) {
        try {
            musico.setFuncao(input.entraString("Digite a função do musico: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musico = sve.corrigirFuncaoMusico(musico);
        }
        return musico;
    }
    
    public Playlist corrigirNomePlaylist(Playlist playlist) {
        try {
            playlist.setNome(input.entraString("Digite o nome da playlist: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            playlist = sve.corrigirNomePlaylist(playlist);
        }
        return playlist;
    }
    
    public Usuario corrigirNomeUsuario(Usuario usuario) {
        try {
            usuario.setNome(input.entraString("Digite o nome do usuário: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            usuario = sve.corrigirNomeUsuario(usuario);
        }
        return usuario;
    }
    public Usuario corrigirEmailUsuario(Usuario usuario) {
        try {
            usuario.setEmail(input.entraString("Digite o e-mail do usuário: "));
        } catch(StringsException sve) {
            sve.avisoEmail();
            usuario = sve.corrigirEmailUsuario(usuario);
        }
        return usuario;
    }
    public Usuario corrigirSenhaUsuario(Usuario usuario) {
        try {
            usuario.setSenha(input.entraString("Digite a senha para o usuário: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            usuario = sve.corrigirSenhaUsuario(usuario);
        }
        return usuario;
    }
    public Usuario corrigirAdmUsuario(Usuario usuario) {
        try {
            usuario.setAdm(input.entraString("Digite a senha para o usuário: "));
        } catch(StringsException sve) {
            sve.avisoAdm();
            usuario = sve.corrigirAdmUsuario(usuario);
        }
        return usuario;
    }
}
