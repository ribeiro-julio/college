// Julio Cesar Garcia Ribeiro - RA: 1994484

public class NumsException extends Exception {
    private EntradaDados input = new EntradaDados();
    
    public void avisoMaiorZero() {
        System.out.println("Entrada inválida -> Deve ser maior que zero");
    }
    
    public Musica corrigirDuracao(Musica musica) {
        try {
            musica.setDuracao(input.entraInt("Digite a duração da música (em segundos): "));
        } catch(NumsException sve) {
            sve.avisoMaiorZero();
            musica = sve.corrigirDuracao(musica);
        }
        return musica;
    }
    
    public Playlist corrigirQuantidadeMusicas(Playlist playlist) {
        try {
            playlist.setQuantidadeMusicas(input.entraInt("Digite a quantidade de musicas: "));
        } catch(NumsException sve) {
            sve.avisoMaiorZero();
            playlist = sve.corrigirQuantidadeMusicas(playlist);
        }
        return playlist;
    }
}
