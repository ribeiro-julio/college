// Julio Cesar Garcia Ribeiro - RA: 1994484

import java.util.List;

public interface BancoDeDados<Object> {
    public List<Object> getAll();
    public void cadastrar();
    public void mostrar();
}