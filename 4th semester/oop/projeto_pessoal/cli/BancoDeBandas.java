// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeBandas implements BancoDeDados {
    private List<Banda> bandas = new ArrayList<>();
    
    @Override
    public List<Banda> getAll() {
        return bandas;
    }
    
    @Override
    public void cadastrar() {
        EntradaDados input = new EntradaDados();
        
        Banda banda = new Banda();
        
        System.out.println("Cadastrando uma banda...");
        
        try {
            banda.setNome(input.entraString("Digite o nome da banda: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            banda = sve.corrigirNomeBanda(banda);
        }
        
        try {
            banda.setGenero(input.entraString("Digite o gênero da banda: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            banda = sve.corrigirGeneroBanda(banda);
        }
        
        bandas.add(banda);
    }
    
    @Override
    public void mostrar() {
        System.out.println("Bandas cadastrados:");
        
        if(getAll().isEmpty()) {
            System.out.println("Nenhuma banda cadastrado");
            return;
        }
        
        for(Banda banda : getAll()) {
            System.out.println(banda.getNome() + ": Gênero: " + banda.getGenero());
            System.out.println("Integrantes:");
            if(banda.getMusicos() == null)
                System.out.println("   Essa banda não tem nenhum integrande cadastrado");
            else {
                for(Musico musico : banda.getMusicos())
                    System.out.println("   - " + musico.getNome() + ": " + musico.getFuncao());
            }
            System.out.println("Musicas:");
            if(banda.getMusicas() == null)
                System.out.println("   Essa banda não tem nenhuma música cadastrada");
            else {
                for(Musica musica : banda.getMusicas())
                    System.out.println("   - " + musica.getNome());
            }
        }
    }
    
    public void selMusicos(List<Musico> musicos) {
        EntradaDados input = new EntradaDados();
        
        mostrar();
        String nome = input.entraString("Digite o nome da banda que deseja selecionar integrantes: ");
        
        for(int i = 0; i < getAll().size(); i++) {
            if(getAll().get(i).getNome().equals(nome)) {
                System.out.println("Selecione os musicos para incluir na banda (-1 para parar):");
        
                if(musicos.isEmpty()) {
                    System.out.println("Erro ao adicionar músicos -> Nenhum músico cadastrado");
                    return;
                }

                int j = 0;
                for(Musico musico : musicos) {    // Mostra os musicos cadastrados
                    System.out.println(j + ": " + musico.getNome() + ": " + musico.getFuncao());
                    j++;
                }
                List<Musico> musicos_toadd = new ArrayList<>();   // Cria uma lista temporária para armazenar os músicos
                int index = 0;
                while(index != -1) {
                    index = input.entraInt(null);
                    if(index >= 0 && index < musicos.size()) {
                        musicos_toadd.add(musicos.get(index));
                    } else {
                        index = -1;
                    }
                }
                getAll().get(i).setMusicos(musicos_toadd);
                return;
            }
        }
        
        System.out.println("Banda não encontrada");
    }
    
    public void selMusicas(List<Musica> musicas) {
        EntradaDados input = new EntradaDados();
        
        mostrar();
        String nome = input.entraString("Digite o nome da banda que deseja selecionar integrantes: ");
        
        for(int i = 0; i < getAll().size(); i++) {
            if(getAll().get(i).getNome().equals(nome)) {
                System.out.println("Selecione as musicas dessa banda (-1 para parar):");
        
                if(musicas.isEmpty()) {
                    System.out.println("Erro ao selecionar músicas -> Nenhuma musica cadastrada");
                    return;
                }

                int j = 0;
                for(Musica musica : musicas) {    // Mostra os musicos cadastrados
                    System.out.println(j + ": " + musica.getNome());
                    j++;
                }
                List<Musica> musicas_toadd = new ArrayList<>();   // Cria uma lista temporária para armazenar os músicos
                int index = 0;
                while(index != -1) {
                    index = input.entraInt(null);
                    if(index >= 0 && index < musicas.size()) {
                        musicas_toadd.add(musicas.get(index));
                    } else {
                        index = -1;
                    }
                }
                getAll().get(i).setMusicas(musicas_toadd);
            }
        }
    }
}
