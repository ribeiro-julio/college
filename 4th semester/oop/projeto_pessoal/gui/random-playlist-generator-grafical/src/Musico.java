// Julio Cesar Garcia Ribeiro - RA: 1994484

public class Musico {
    private String nome;
    private String funcao;
    private Banda banda;
    
    public String getNome() {
        return nome;
    }
    public String getFuncao() {
        return funcao;
    }
    public Banda getBanda() {
        return banda;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setFuncao(String funcao) {
        this.funcao = funcao;
    }
    public void setBanda(Banda banda) {
        this.banda = banda;
    }
}
