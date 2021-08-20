// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeMusicos {
    private List<Musico> musicos = new ArrayList<>();
    
    public List<Musico> getAll() {
        return musicos;
    }
    
    public Musico cadastrar(Musico musico) {
        if(!musicos.isEmpty()) {
            for(Musico cadastrado : musicos) {
                if(cadastrado.getNome().equals(musico.getNome()))
                    return null;
            }
        }
        
        musicos.add(musico);
            return musico;
    }
    
    public Musico procurarMusico(String nome) {
        if(!musicos.isEmpty()) {
            for(Musico musico : musicos) {
                if(musico.getNome().equals(nome))
                    return musico;
            }
        }
        
        return null;
    }
}
