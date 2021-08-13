// Julio Cesar Garcia Ribeiro - RA: 1994484

public class Musica {
    private String nome;
    private int duracao;
    
    public String getNome() {
        return nome;
    }
    public int getDuracao() {
        return duracao;
    }
    
    public void setNome(String nome) throws StringsException {
        if(nome.isEmpty())
            throw new StringsException();
        else
            this.nome = nome;
    }
    public void setDuracao(int duracao) throws NumsException {
        if(duracao > 0)
            this.duracao = duracao;
        else
            throw new NumsException();
    }
}
