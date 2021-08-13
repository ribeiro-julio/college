// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;

public class Banda {
    private String nome;
    private String genero;
    private List<Musico> musicos;
    private List<Musica> musicas;
    
    public Banda(){
        musicos = null;
        musicas = null;
    }
    
    public String getNome() {
        return nome;
    }
    public String getGenero() {
        return genero;
    }
    public List<Musico> getMusicos() {
        return musicos;
    }
    public List<Musica> getMusicas() {
        return musicas;
    }
    
    public void setNome(String nome) throws StringsException {
        if(nome.isEmpty())
            throw new StringsException();
        else
            this.nome = nome;
    }
    public void setGenero(String genero) throws StringsException {
        if(genero.isEmpty())
            throw new StringsException();
        else
            this.genero = genero;
    }
    public void setMusicos(List<Musico> musicos) {
        this.musicos = musicos;
    }
    public void setMusicas(List<Musica> musicas) {
        this.musicas = musicas;
    }
}
