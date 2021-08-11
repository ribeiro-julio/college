// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class BancoDePlaylists implements BancoDeDados {
    private List<Playlist> playlists = new ArrayList<>();
    
    @Override
    public List<Playlist> getAll() {
        return playlists;
    }
    
    @Override
    public void cadastrar() {
        EntradaDados input = new EntradaDados();
        
        Playlist playlist = new Playlist();
        
        System.out.println("Cadastrando uma playlist...");
        
        try {
            playlist.setNome(input.entraString("Digite o nome da playlist: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            playlist = sve.corrigirNomePlaylist(playlist);
        }
        
        playlists.add(playlist);
    }
    
    void adcMusicasAleatorias(Playlist playlist, List<Musica> musicas, Sessao sessao) {
        EntradaDados input = new EntradaDados();
        
        playlist.setUsuario(sessao.getUsuarioLogado());
        
        List<Musica> musicas_toadd = playlist.getMusicas();
        
        try {
            int quantidade = input.entraInt("Digite a quantidade de musicas: ");
            playlist.setQuantidadeMusicas(quantidade + playlist.getQuantidadeMusicas());
            if(playlist.getQuantidadeMusicas() > musicas.size())
                playlist.setQuantidadeMusicas(musicas.size());
        } catch(NumsException ne) {
            ne.avisoMaiorZero();
            playlist = ne.corrigirQuantidadeMusicas(playlist);
        }
        
        System.out.println("Adicionando músicas aleatórias da coleção...");
        if(playlist.getQuantidadeMusicas() == musicas.size())
            playlist.setMusicas(musicas);
        else {
            Random rand = new Random();
            int i = 0;
            while(i < playlist.getQuantidadeMusicas()) {
                int index = rand.nextInt(musicas.size());
                if(!musicas_toadd.contains(musicas.get(index))) {
                    musicas_toadd.add(musicas.get(index));
                    playlist.setDuracao(playlist.getDuracao() + playlist.getMusicas().get(i).getDuracao());
                    i++;
                }
            }
            playlist.setMusicas(musicas_toadd);
        }
    }
    
    public void mostrar(Usuario logado) {
        System.out.println("Playlists geradas por esse usuário:");
        for(Playlist playlist : getAll()) {
            if(playlist.GetUsuario() != null && playlist.GetUsuario().getEmail().equals(logado.getEmail())) {
                System.out.println("\n" + playlist.getNome() + " - Duração: " + playlist.getDuracao() + "s");
                System.out.println("Musicas:");
                if(playlist.getMusicas() == null)
                    System.out.println("   Essa playlist não tem nenhuma música cadastrada");
                else {
                    for(Musica musica : playlist.getMusicas()) {
                        System.out.println("   " + musica.getNome());
                    }
                }
            }
        }
    }
}
