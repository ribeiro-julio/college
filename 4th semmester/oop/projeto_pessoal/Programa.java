// Julio Cesar Garcia Ribeiro - RA: 1994484

public class Programa {
    
    private static EntradaDados input = new EntradaDados();
    private static BancoDeBandas bb = new BancoDeBandas();
    private static BancoDeMusicas bma = new BancoDeMusicas();
    private static BancoDeMusicos bmo = new BancoDeMusicos();
    private static BancoDePlaylists bp = new BancoDePlaylists();
    private static BancoDeUsuarios bu = new BancoDeUsuarios();
    private static Sessao sessao = new Sessao();
    
    public static void main(String[] args) {
        while(true) {
            System.out.println("Gerador de Playlists com Músicas Aleatórias");
            System.out.println("Tela Inicial");
            System.out.println("Selecione uma opcao (0 a 2):");
            System.out.println("1 - Entrar");
            System.out.println("2 - Cadastrar Usuário");
            System.out.println("0 - Sair");
            int opcao = input.entraInt(null);
            
            switch(opcao) {
                case 0:
                    System.exit(0);
                break;
                
                case 1:
                    System.out.println("\n----------------------------------------\n");
                    String email = input.entraString("Digite o e-mail: ");
                    String senha = input.entraString("Digite a senha: ");
                    sessao.setUsuarioLogado(bu.cadastrado(email, senha));
                    if(sessao.getUsuarioLogado() != null) {
                        if(sessao.getUsuarioLogado().getAdm()) {
                            System.out.println("\n----------------------------------------\n");
                            telaAdm();
                        }
                        else {
                            System.out.println("\n----------------------------------------\n");
                            telaNaoAdm();
                        }
                    } else
                        System.out.println("Usuário não encontrado");
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 2:
                    System.out.println("\n----------------------------------------\n");
                    bu.cadastrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                default:
                    System.out.println("\n----------------------------------------\n");
                    System.out.println("Opcao inválida");
                    System.out.println("\n----------------------------------------\n");
            }
        }
    }
    
    static void telaAdm() {
        while(true) {
            System.out.println("Tela do Administrador");
            System.out.println("Selecione uma opcao (0 a 10):");
            System.out.println("1 - Cadastrar musico");
            System.out.println("2 - Mostrar musicos cadastrados");
            System.out.println("3 - Cadastrar musica");
            System.out.println("4 - Mostrar musicas cadastradas");
            System.out.println("5 - Cadastrar banda");
            System.out.println("6 - Selecionar músicos da banda");
            System.out.println("7 - Selecionar músicas da banda");
            System.out.println("8 - Mostrar bandas cadastradas");
            System.out.println("9 - Gerar playlist");
            System.out.println("10 - Mostrar playlist que eu cadastrei");
            System.out.println("0 - Deslogar");
            int opcao = input.entraInt(null);
            
            switch(opcao) {
                case 0:
                    System.out.println("\n----------------------------------------\n");
                    return;
                    
                case 1:
                    System.out.println("\n----------------------------------------\n");
                    bmo.cadastrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 2:
                    System.out.println("\n----------------------------------------\n");
                    bmo.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 3:
                    System.out.println("\n----------------------------------------\n");
                    bma.cadastrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 4:
                    System.out.println("\n----------------------------------------\n");
                    bma.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 5:
                    System.out.println("\n----------------------------------------\n");
                    bb.cadastrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 6:
                    System.out.println("\n----------------------------------------\n");
                    bb.selMusicos(bmo.getAll());
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 7:
                    System.out.println("\n----------------------------------------\n");
                    bb.selMusicas(bma.getAll());
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 8:
                    System.out.println("\n----------------------------------------\n");
                    bb.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 9:
                    System.out.println("\n----------------------------------------\n");
                    bp.gerar(sessao, bma.getAll());
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 10:
                    System.out.println("\n----------------------------------------\n");
                    bp.mostrar(sessao);
                    System.out.println("\n----------------------------------------\n");
                break;
                
                default:
                    System.out.println("Opção inválida");
            }
        }
    }
    
    static void telaNaoAdm() {
        while(true) {
            System.out.println("Tela do Usuário");
            System.out.println("Selecione uma opcao (0 a 5):");
            System.out.println("1 - Mostrar musicos cadastrados");
            System.out.println("2 - Mostrar musicas cadastradas");
            System.out.println("3 - Mostrar bandas cadastradas");
            System.out.println("4 - Gerar playlist");
            System.out.println("5 - Mostrar playlist que eu cadastrei");
            System.out.println("0 - Deslogar");
            int opcao = input.entraInt(null);
            
            switch(opcao) {
                case 0:
                    return;
                
                case 1:
                    System.out.println("\n----------------------------------------\n");
                    bmo.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 2:
                    System.out.println("\n----------------------------------------\n");
                    bma.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 3:
                    System.out.println("\n----------------------------------------\n");
                    bb.mostrar();
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 4:
                    System.out.println("\n----------------------------------------\n");
                    bp.gerar(sessao, bma.getAll());
                    System.out.println("\n----------------------------------------\n");
                break;
                
                case 5:
                    System.out.println("\n----------------------------------------\n");
                    bp.mostrar(sessao);
                    System.out.println("\n----------------------------------------\n");
                break;
                
                default:
                    System.out.println("Opção inválida");
            }
        }
    }
}
