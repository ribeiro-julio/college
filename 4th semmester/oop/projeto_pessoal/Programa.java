import java.io.InputStreamReader; 
import java.io.BufferedReader;
import java.io.IOException;

public class Programa {
    public static void main(String[] args) {
        Usuario usuarios[] = new Usuario[2];
        Musico musicos[] = new Musico[5];
        Banda bandas[] = new Banda[2];
        Musica musicas[] = new Musica[5];
        Playlist playlists[] = new Playlist[2];
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        Usuario usuario = new Usuario();
        usuario.setNome("Adm");
        usuario.setEmail("adm@adm.com");
        usuario.setSenha("adm");
        usuario.setAdm(true);
        usuarios[0] = usuario;
        
        usuario = new Usuario();
        usuario.setNome("Nao Adm");
        usuario.setEmail("naoadm@naoadm.com");
        usuario.setSenha("naoadm");
        usuario.setAdm(false);
        usuarios[1] = usuario;
        
        String email = "", senha = "";
        System.out.println("Digite seu email: ");
        try {
            email = br.readLine();
        } catch (IOException ioe) {
            System.out.println("Erro de entrada");
        }
        System.out.println("Digite sua senha: ");
        try {
            senha = br.readLine();
        } catch (IOException ioe) {
            System.out.println("Erro de entrada");
        }
        
        System.out.println("-----------------------------------");
        
        int usuarioCadastrado = usuario.noSistema(usuarios, email, senha);
        
        if(usuarioCadastrado != -1) {
            if(usuarios[usuarioCadastrado].getAdm() == true) {
                int opcao = 0;
                
                do {
                    System.out.println("Opcoes:");
                    System.out.println("1 - Cadastrar musico");
                    System.out.println("2 - Cadastrar musica");
                    System.out.println("3 - Cadastrar banda");
                    System.out.println("4 - Gerar playlist");
                    System.out.println("0 - Sair");
                    
                    try {
                        opcao = Integer.parseInt(br.readLine());
                    } catch (IOException ioe) {
                        System.out.println("Erro de entrada");
                    } catch(NumberFormatException nfe) {
                        opcao = -1;
                    }
                    if(opcao < 0 || opcao > 4) {
                        System.out.println("Opcao inválida");
                    }
                    
                    System.out.println("-----------------------------------");
                    
                    switch(opcao) {
                        case 1:
                            Musico musico = new Musico();
                            musico.cadastrar();
                            for(int i = 0; i < 5; i++) {
                                if(musicos[i] == null) {
                                    musicos[i] = musico;
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            
                            System.out.println("Musicos cadastrados:\n");
                            for(int i = 0; i < 5; i++) {
                                if(musicos[i] != null) {
                                    System.out.println(musicos[i].getNome() + ": " + musicos[i].getFuncao() + "\n");
                                } else {
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            break;
                            
                        case 2:
                            Musica musica = new Musica();
                            musica.cadastrarMusica();
                            for(int i = 0; i < 5; i++) {
                                if(musicas[i] == null) {
                                    musicas[i] = musica;
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            
                            System.out.println("Musicas cadastrados:\n");
                            for(int i = 0; i < 5; i++) {
                                if(musicas[i] != null) {
                                    System.out.println(musicas[i].getNome() + " - Duração: " + musicas[i].getDuracao() + "s\n");
                                } else {
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            break;
                        
                        case 3:
                            Banda banda = new Banda();
                            banda.cadastrarBanda(musicos, musicas);
                            for(int i = 0; i < 5; i++) {
                                if(bandas[i] == null) {
                                    bandas[i] = banda;
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            
                            System.out.println("Bandas cadastrados:\n");
                            for(int i = 0; i < 2; i++) {
                                if(bandas[i] != null) {
                                    System.out.println(bandas[i].getNome() + " - " + bandas[i].getGenero());
                                    System.out.println("Integrantes:");
                                    for(int j = 0; j < bandas[i].getMusicos().length; j++) {
                                        if(bandas[i].getMusicos()[j] != null) {
                                            System.out.println("   " + bandas[i].getMusicos()[j].getNome() + ": " + bandas[i].getMusicos()[j].getFuncao());
                                        } else {
                                            break;
                                        }
                                    }
                                    System.out.println("Musicas:");
                                    for(int j = 0; j < bandas[i].getMusicas().length; j++) {
                                        if(bandas[i].getMusicas()[j] != null) {
                                            System.out.println("   " + bandas[i].getMusicas()[j].getNome() + "\n");
                                        } else {
                                            break;
                                        }
                                    }
                                } else {
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            break;
                        
                        case 4:
                            Playlist playlist = new Playlist();
                            playlist.gerarPlaylist(musicas, usuarios[usuarioCadastrado]);
                            for(int i = 0; i < 2; i++) {
                                if(playlists[i] == null) {
                                    playlists[i] = playlist;
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            
                            System.out.println("Playlists geradas:\n");
                            for(int i = 0; i < 2; i++) {
                                if(playlists[i] != null) {
                                    System.out.println(playlists[i].getNome() + " - Duração: " + playlists[i].getDuracao() + "s");
                                    System.out.println("Musicas:");
                                    for(int j = 0; j < playlists[i].getMusicas().length; j++) {
                                        if(playlists[i].getMusicas()[j] != null) {
                                            System.out.println("   " + playlists[i].getMusicas()[j].getNome());
                                        } else {
                                            break;
                                        }
                                    }
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            break;
                    }
                    
                } while(opcao != 0);
            } else {
                int opcao = 0;

                do {
                    System.out.println("Opcoes:");
                    System.out.println("1 - Gerar playlist");
                    System.out.println("0 - Sair");

                    try {
                        opcao = Integer.parseInt(br.readLine());
                    } catch (IOException ioe) {
                        System.out.println("Erro de entrada");
                    } catch(NumberFormatException nfe) {
                        opcao = -1;
                    }
                    if(opcao < 0 || opcao > 1) {
                        System.out.println("Opcao inválida");
                    }
                    
                    // Populando musicas já que o nao adm nao pode cadastrar musicas
                    Musica musica = new Musica();
                    musica.setNome("Musica 1");
                    musica.setDuracao(100);
                    musicas[0] = musica;
                    musica = new Musica();
                    musica.setNome("Musica 2");
                    musica.setDuracao(10);
                    musicas[1] = musica;
                    musica = new Musica();
                    musica.setNome("Musica 3");
                    musica.setDuracao(20);
                    musicas[2] = musica;
                    musica = new Musica();
                    musica.setNome("Musica 4");
                    musica.setDuracao(50);
                    musicas[3] = musica;
                    musica.setNome("Musica 5");
                    musica.setDuracao(110);
                    musicas[4] = musica;

                    switch(opcao){
                        case 1:
                            Playlist playlist = new Playlist();
                            playlist.gerarPlaylist(musicas, usuarios[usuarioCadastrado]);
                            for(int i = 0; i < 2; i++) {
                                if(playlists[i] == null) {
                                    playlists[i] = playlist;
                                    break;
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            
                            System.out.println("Playlists geradas:\n");
                            for(int i = 0; i < 2; i++) {
                                if(playlists[i] != null) {
                                    System.out.println(playlists[i].getNome() + " - Duração: " + playlists[i].getDuracao() + "s");
                                    System.out.println("Musicas:");
                                    for(int j = 0; j < playlists[i].getMusicas().length; j++) {
                                        if(playlists[i].getMusicas()[j] != null) {
                                            System.out.println("   " + playlists[i].getMusicas()[j].getNome());
                                        } else {
                                            break;
                                        }
                                    }
                                }
                            }
                            
                            System.out.println("-----------------------------------");
                            break;
                    }

                } while(opcao != 0);
            }
        } else {
            System.out.println("Acesso negado");
        }
    }
}
