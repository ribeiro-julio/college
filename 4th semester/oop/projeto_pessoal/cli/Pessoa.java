// Julio Cesar Garcia Ribeiro - RA: 1994484

public abstract class Pessoa {
    private String nome;
    
    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) throws StringsException {
        if(nome.isEmpty())
            throw new StringsException();
        else
            this.nome = nome;
    }
}
