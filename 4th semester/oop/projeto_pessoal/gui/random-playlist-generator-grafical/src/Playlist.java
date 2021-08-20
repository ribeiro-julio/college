// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;

public class Playlist {
    private String nome;
    private int duracao;
    int quantidadeMusicas;
    private List<Musica> musicas;
    
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
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    public void setQuantidadeMusicas(int quantidadeMusicas) {
        this.quantidadeMusicas = quantidadeMusicas;
    }
    public void setMusicas(List<Musica> musicas) {
        this.musicas = musicas;
    }
}
