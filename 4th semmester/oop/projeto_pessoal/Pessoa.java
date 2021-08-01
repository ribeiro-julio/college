// Julio Cesar Garcia Ribeiro - RA: 1994484

public abstract class Pessoa {
    private String nome;
    
    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public abstract void cadastrar();
}
