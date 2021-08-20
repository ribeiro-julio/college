// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.ArrayList;
import java.util.List;

public class BancoDeBandas {
    private List<Banda> bandas = new ArrayList<>();
    
    public List<Banda> getAll() {
        return bandas;
    }
    
    public Banda cadastrar(Banda banda) {
        if(!bandas.isEmpty()) {
            for(Banda cadastrada : bandas) {
                if(cadastrada.getNome().equals(banda.getNome()))
                    return null;
            }
        }
        
        bandas.add(banda);
        return banda;
    }
    
    public Banda procurarBanda(String nome) {
        if(!bandas.isEmpty()) {
            for(Banda banda : bandas) {
                if(banda.getNome().equals(nome))
                    return banda;
            }
        }
        
        return null;
    }
}
