import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Banda {
    private String nome;
    private String genero;
    private Musico musicos[];
    private Musica musicas[];
    
    public Banda(){
        musicos = new Musico[5];
        musicas = new Musica[5];
    }
    
    public String getNome() {
        return nome;
    }
    public String getGenero() {
        return genero;
    }
    public Musico[] getMusicos() {
        return musicos;
    }
    public Musica[] getMusicas() {
        return musicas;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }
    public void setMusicos(Musico musicos[]) {
        this.musicos = musicos;
    }
    public void setMusicas(Musica musicas[]) {
        this.musicas = musicas;
    }
    
    public void cadastrarBanda(Musico musicos[], Musica musicas[]) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        System.out.println("Cadastrando uma banda...");
        
        System.out.println("Digite o nome da banda: ");
        try {
            this.setNome(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Digite o gênero da banda: ");
        try {
            this.setGenero(br.readLine());
        } catch(IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("Selecione os musicos para incluir na banda (-1 para parar):");
        int i;
        int index = 0;
        while(index != -1) {
            for(i = 0; i < musicos.length; i++) {
                if(musicos[i] != null) {
                    System.out.println(i + " - " + musicos[i].getNome() + ": " + musicos[i].getFuncao());
                } else {
                    break;
                }
            }
            try {
                index = Integer.parseInt(br.readLine());
                if(index >= 0 && index <= i) {
                    for(int j = 0; j < this.musicos.length; j++) {
                        if(this.musicos[j] == null) {
                            this.musicos[j] = musicos[index];
                            break;
                        }
                    }
                } else {
                    index = -1;
                }
            } catch(IOException ioe) {
                System.out.println("Erro de entrada");
            } catch(NumberFormatException nfe) {
                index = -1;
            }
        }
        
        System.out.println("Selecione as musicas dessa banda (-1 para parar):");
        index = 0;
        while(index != -1) {
            for(i = 0; i < musicas.length; i++) {
                if(musicas[i] != null) {
                    System.out.println(i + " - " + musicas[i].getNome() + ": " + musicas[i].getDuracao());
                } else {
                    break;
                }
            }
            try {
                index = Integer.parseInt(br.readLine());
                if(index >= 0 && index <= i) {
                    for(int j = 0; j < this.musicas.length; j++) {
                        if(this.musicas[j] == null) {
                            this.musicas[j] = musicas[index];
                            break;
                        }
                    }
                } else {
                    index = -1;
                }
            } catch(IOException ioe) {
                System.out.println("Erro de entrada");
            } catch(NumberFormatException nfe) {
                index = -1;
            }
        }
    }
}
