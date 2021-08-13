// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeMusicos implements BancoDeDados {
    private List<Musico> musicos = new ArrayList<>();
    
    @Override
    public List<Musico> getAll() {
        return musicos;
    }
    
    @Override
    public void cadastrar() {
        EntradaDados input = new EntradaDados();
        
        Musico musico = new Musico();
        
        System.out.println("Cadastrando um musico...");
        
        try {
            musico.setNome(input.entraString("Digite o nome do músico: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musico = sve.corrigirNomeMusico(musico);
        }
        
        try {
            musico.setFuncao(input.entraString("Digite a função do musico: "));
        } catch(StringsException sve) {
            sve.avisoVazia();
            musico = sve.corrigirFuncaoMusico(musico);
        }
        
        musicos.add(musico);
    }
    
    @Override
    public void mostrar() {
        System.out.println("Musicos cadastrados:");
        
        if(getAll().isEmpty()) {
            System.out.println("Nenhum musico cadastrado");
            return;
        }
        
        for(Musico musico : getAll())
            System.out.println("- " + musico.getNome() + ": " + musico.getFuncao());
    }
}
