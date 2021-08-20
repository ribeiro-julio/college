// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class BancoDePlaylists {
    private List<Playlist> playlists = new ArrayList<>();
    
    public List<Playlist> getAll() {
        return playlists;
    }
    
    public Playlist gerar(Playlist playlist, List<Musica> musicas) {
        if(!playlists.isEmpty()) {
            for(Playlist cadastrada : playlists) {
                if(cadastrada.getNome().equals(playlist.getNome()))
                    return null;
            }
        }
        
        List<Musica> musicas_toadd = new ArrayList<>();
        int duracao = 0;
        
        if(playlist.getQuantidadeMusicas() == musicas.size()) {
            musicas_toadd = musicas;
            for(Musica musica : musicas)
                duracao += musica.getDuracao();
        } else {
            Random rand = new Random();
            int i = 0;
            while(i < playlist.getQuantidadeMusicas()) {
                int index = rand.nextInt(musicas.size());
                if(!musicas_toadd.contains(musicas.get(index))) {
                    musicas_toadd.add(musicas.get(index));
                    duracao += musicas.get(index).getDuracao();
                    i++;
                }
            }
        }
        
        playlist.setDuracao(duracao);
        playlist.setMusicas(musicas_toadd);
        playlists.add(playlist);
        
        return playlist;
    }
    
    public Playlist procurarPlaylist(String nome) {
        if(!playlists.isEmpty()) {
            for(Playlist playlist : playlists) {
                if(playlist.getNome().equals(nome))
                    return playlist;
            }
        }
        
        return null;
    }
}
