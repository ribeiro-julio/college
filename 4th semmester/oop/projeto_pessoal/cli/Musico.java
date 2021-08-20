// Julio Cesar Garcia Ribeiro - RA: 1994484

public class Musico extends Pessoa {
    private String funcao;
    
    public String getFuncao() {
        return funcao;
    }
    
    public void setFuncao(String funcao) throws StringsException {
        if(funcao.isEmpty())
            throw new StringsException();
        else
            this.funcao = funcao;
    }
}
