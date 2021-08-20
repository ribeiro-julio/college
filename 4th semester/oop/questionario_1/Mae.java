public class Mae {
    private String nome;    // Encapsulamento
    private int idade;
    protected int nascimento;
    
    public String getNome() {   // Encapsulamento
        return nome;
    }
    public int getIdade() {   // Encapsulamento
        return idade;
    }
    
    public void setNome(String nome) {   // Encapsulamento
        this.nome = nome;
    }
    public void setIdade(int idade) {   // Encapsulamento
        this.idade = idade;
    }
    
    public void exibeNome() {   // Encapsulamento
        System.out.println("Esta é a classe Mãe");
    }
}
