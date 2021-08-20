// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeMusicas {
    private List<Musica> musicas = new ArrayList<>();
    
    public List<Musica> getAll() {
        return musicas;
    }
    
    public Musica cadastrar(Musica musica) {
        if(!musicas.isEmpty()) {
            for(Musica cadastrada : musicas) {
                if(cadastrada.getNome().equals(musica.getNome()))
                    return null;
            }
        }
        
        musicas.add(musica);
        return musica;
    }
    
    public Musica procurarMusica(String nome) {
        if(!musicas.isEmpty()) {
            for(Musica musica : musicas) {
                if(musica.getNome().equals(nome))
                    return musica;
            }
        }
        
        return null;
    }
}
