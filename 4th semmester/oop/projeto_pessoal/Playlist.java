// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Playlist {
    private String nome;
    private int duracao;
    private Musica musicas[];
    private Usuario usuario;
    
    public Playlist() {
        musicas = new Musica[3];
    }
    
    public String getNome() {
        return nome;
    }
    public int getDuracao() {
        return duracao;
    }
    public Musica[] getMusicas() {
        return musicas;
    }
    public Usuario GetUsuario() {
        return usuario;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    public void setMusicas(Musica musicas[]) {
        this.musicas = musicas;
    }
    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
    
    public void gerarPlaylist(Musica musicas[], Usuario usuario) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        System.out.println("Gerando uma playlist...");
        
        System.out.println("Digite o nome da playlist: ");
        try {
            this.setNome(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Adicionando músicas aleatórias da coleção...");
        Random rand = new Random();
        int index = 0;
        while(index < 3) {
            int i = rand.nextInt(5);
            if(musicas[i] != null) {
                this.musicas[index] = musicas[i];
                this.setDuracao(this.getDuracao() + musicas[i].getDuracao());
            }
            index++;
        }        
    }
}
