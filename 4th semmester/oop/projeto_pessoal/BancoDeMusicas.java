// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeMusicas implements BancoDeDados{
    private List<Musica> musicas = new ArrayList<>();
    
    @Override
    public List<Musica> getAll() {
        return musicas;
    }
    
    @Override
    public void cadastrar() {
        EntradaDados input = new EntradaDados();
        
        Musica musica  = new Musica();
        
        System.out.println("Cadastrando uma música...");
        
        try {
            musica.setNome(input.entraString("Digite o nome da musica: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musica = sve.corrigirNomeMusica(musica);
        }
        
        try {
            musica.setDuracao(input.entraInt("Digite a duração da música (em segundos): "));
        } catch(NumsException ne) {
            ne.avisoMaiorZero();
            musica = ne.corrigirDuracao(musica);
        }
        
        musicas.add(musica);
    }
    
    public void mostrar() {
        System.out.println("Musicas cadastrados:");
            for(Musica musica : getAll())
                System.out.println("- " + musica.getNome() + " - Duração: " + musica.getDuracao());
    }
}
