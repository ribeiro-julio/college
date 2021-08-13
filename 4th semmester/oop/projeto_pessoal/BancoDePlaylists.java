// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class BancoDePlaylists {
    private List<Playlist> playlists = new ArrayList<>();
    
    public List<Playlist> getAll() {
        return playlists;
    }
    
    public void gerar(Sessao sessao, List<Musica> musicas) {
        EntradaDados input = new EntradaDados();
        
        Playlist playlist = new Playlist();
        
        System.out.println("Cadastrando uma playlist...");
        
        if(musicas.isEmpty()) {
            System.out.println("Não foi possível gerar a playlist -> Nenhuma música cadastrada");
            return;
        }
        
        try {
            playlist.setNome(input.entraString("Digite o nome da playlist: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            playlist = sve.corrigirNomePlaylist(playlist);
        }
        
        playlist.setUsuario(sessao.getUsuarioLogado());
        
        List<Musica> musicas_toadd = new ArrayList<>();
        int duracao = 0;
        
        try {
            playlist.setQuantidadeMusicas(input.entraInt("Digite a quantidade de musicas: "));
            if(playlist.getQuantidadeMusicas() > musicas.size()) {
                System.out.println("Quantidade de músicas ultrapassa o número de músicas cadastradas -> Definido a quantidade de músicas cadastrada");
                playlist.setQuantidadeMusicas(musicas.size());
            }
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
                    duracao += musicas.get(index).getDuracao();
                    i++;
                }
            }
            playlist.setDuracao(duracao);
            playlist.setMusicas(musicas_toadd);
        }
        
        playlists.add(playlist);
    }
    
    public void mostrar(Sessao sessao) {
        System.out.println("Playlists geradas por esse usuário:");
        
        boolean achou = false;
        for(Playlist playlist : getAll()) {
            if(playlist.GetUsuario().getEmail().equals(sessao.getUsuarioLogado().getEmail())) {
                achou  = true;
                System.out.println("\n" + playlist.getNome());
                System.out.println("Musicas:");
                for(Musica musica : playlist.getMusicas())
                    System.out.println("   " + musica.getNome());
            }
        }
        
        if(!achou)
            System.out.println("Nenhuma playlist cadastrada pelo usuário " + sessao.getUsuarioLogado().getNome());
    }
}
