// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;

public class Playlist {
    private String nome;
    private int duracao;
    int quantidadeMusicas;
    private List<Musica> musicas;
    private Usuario usuario;
    
    public String getNome() {
        return nome;
    }
    public int getDuracao() {
        return duracao;
    }
    public int getQuantidadeMusicas() {
        return quantidadeMusicas;
    }
    public List<Musica> getMusicas() {
        return musicas;
    }
    public Usuario GetUsuario() {
        return usuario;
    }
    
    public void setNome(String nome) throws StringsException {
        if(nome.isEmpty())
            throw new StringsException();
        else
            this.nome = nome;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    public void setQuantidadeMusicas(int quantidadeMusicas) throws NumsException {
        if(quantidadeMusicas > 0)
            this.quantidadeMusicas = quantidadeMusicas;
        else
            throw new NumsException();
    }
    public void setMusicas(List<Musica> musicas) {
        this.musicas = musicas;
    }
    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
}
