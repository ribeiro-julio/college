// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class Banda {
    private String nome;
    private String genero;
    private List<Musico> musicos;
    private List<Musica> musicas;
    
    public Banda(){
        musicos = new ArrayList<>();
        musicas = new ArrayList<>();
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
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }
    public void adcMusico(Musico musico) {
        musicos.add(musico);
    }
    public void adcMusica(Musica musica) {
        musicas.add(musica);
    }
}
