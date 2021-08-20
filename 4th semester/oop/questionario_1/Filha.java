public class Filha extends Mae {    // Herança
    public Filha(String nome) {   // Polimorfismo por sobrecarga
        setNome(nome);
    }
    public Filha(String nome, int idade, int nascimento) {    // Polimorfismo por sobrecarga
        setNome(nome);
        setIdade(idade);
        this.nascimento = nascimento;   // Protected pode ser acessado sem set()
    }
    
    public void exibeNome() {   // Polimorfismo por sobrescrita
        System.out.println("Esta é a classe Filha");
    }
}
