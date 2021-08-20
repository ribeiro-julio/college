// Julio Cesar Garcia Ribeiro - RA: 1994484

import javax.swing.DefaultComboBoxModel;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

public class TelaPrincipal extends javax.swing.JFrame {
    
    BancoDeBandas bb = new BancoDeBandas();
    BancoDeMusicas bma = new BancoDeMusicas();
    BancoDeMusicos bmo = new BancoDeMusicos();
    BancoDePlaylists bp = new BancoDePlaylists();

    private static TelaPrincipal telaPrincipal;
    
    public TelaPrincipal() {
        initComponents();
    }
    
    public static TelaPrincipal getTelaPrincipal() {
        if(telaPrincipal == null){
            telaPrincipal = new TelaPrincipal();
        }
        return telaPrincipal;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tabBandas = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        tabMusicos = new javax.swing.JTable();
        jScrollPane3 = new javax.swing.JScrollPane();
        tabMusicas = new javax.swing.JTable();
        jScrollPane4 = new javax.swing.JScrollPane();
        tabPlaylists = new javax.swing.JTable();
        jPanel1 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        txtBandaNome = new javax.swing.JTextField();
        txtBandaGen = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        btnCadBanda = new javax.swing.JButton();
        btnInfoBanda = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        txtMusicoNome = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        txtMusicoFunc = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        cbBandas1 = new javax.swing.JComboBox<>();
        btnCadMusico = new javax.swing.JButton();
        btnProcurarMusico = new javax.swing.JButton();
        btnRelMusicos = new javax.swing.JButton();
        jPanel3 = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        txtMusicaNome = new javax.swing.JTextField();
        jLabel12 = new javax.swing.JLabel();
        txtMusicaDur = new javax.swing.JTextField();
        jLabel13 = new javax.swing.JLabel();
        cbBandas2 = new javax.swing.JComboBox<>();
        btnCadMusica = new javax.swing.JButton();
        btnProcurarMusica = new javax.swing.JButton();
        btnRelMusicas = new javax.swing.JButton();
        jPanel4 = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        txtPlNome = new javax.swing.JTextField();
        txtPlQntMu = new javax.swing.JTextField();
        jLabel15 = new javax.swing.JLabel();
        btnGerarPl = new javax.swing.JButton();
        btnInfoPl = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        tabBandas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "Nome", "Gênero"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(tabBandas);

        tabMusicos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "Nome", "Função"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane2.setViewportView(tabMusicos);

        tabMusicas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "Nome", "Duração"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane3.setViewportView(tabMusicas);

        tabPlaylists.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Nome", "Quantidade de Músicas", "Duração"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane4.setViewportView(tabPlaylists);

        jLabel3.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        jLabel3.setText("Bandas");

        jLabel6.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel6.setText("Nome");

        jLabel7.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel7.setText("Gênero");

        btnCadBanda.setText("Cadastrar Banda");
        btnCadBanda.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCadBandaActionPerformed(evt);
            }
        });

        btnInfoBanda.setText("Mostrar Informacões");
        btnInfoBanda.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnInfoBandaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(51, 51, 51)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(btnCadBanda)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnInfoBanda))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel7)
                                .addGap(5, 5, 5)))
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(txtBandaNome)
                            .addComponent(txtBandaGen, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(60, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jLabel3)
                .addGap(164, 164, 164))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel6)
                    .addComponent(txtBandaNome, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtBandaGen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnCadBanda)
                    .addComponent(btnInfoBanda))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jLabel2.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        jLabel2.setText("Músicos");

        jLabel8.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel8.setText("Nome");

        jLabel9.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel9.setText("Função");

        jLabel10.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel10.setText("Banda");

        btnCadMusico.setText("Cadastrar Músico");
        btnCadMusico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCadMusicoActionPerformed(evt);
            }
        });

        btnProcurarMusico.setText("Procurar Músico");
        btnProcurarMusico.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnProcurarMusicoActionPerformed(evt);
            }
        });

        btnRelMusicos.setText("Gerar Relatório");
        btnRelMusicos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnRelMusicosActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(btnCadMusico)
                        .addGap(18, 18, 18)
                        .addComponent(btnProcurarMusico)
                        .addGap(18, 18, 18)
                        .addComponent(btnRelMusicos))
                    .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                            .addGap(70, 70, 70)
                            .addComponent(jLabel10)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(cbBandas1, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                            .addGap(71, 71, 71)
                            .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(jPanel2Layout.createSequentialGroup()
                                    .addComponent(jLabel9)
                                    .addGap(5, 5, 5)
                                    .addComponent(txtMusicoFunc, javax.swing.GroupLayout.PREFERRED_SIZE, 213, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGroup(jPanel2Layout.createSequentialGroup()
                                    .addComponent(jLabel8)
                                    .addGap(5, 5, 5)
                                    .addComponent(txtMusicoNome, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE))))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jLabel2)
                .addGap(164, 164, 164))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(txtMusicoNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(txtMusicoFunc, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(cbBandas1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel10))
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnCadMusico)
                    .addComponent(btnProcurarMusico)
                    .addComponent(btnRelMusicos))
                .addGap(0, 17, Short.MAX_VALUE))
        );

        jLabel4.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        jLabel4.setText("Músicas");

        jLabel11.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel11.setText("Nome");

        jLabel12.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel12.setText("Duração");

        jLabel13.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel13.setText("Banda");

        btnCadMusica.setText("Cadastrar Música");
        btnCadMusica.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCadMusicaActionPerformed(evt);
            }
        });

        btnProcurarMusica.setText("Procurar Música");
        btnProcurarMusica.setToolTipText("");
        btnProcurarMusica.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnProcurarMusicaActionPerformed(evt);
            }
        });

        btnRelMusicas.setText("Gerar Relatório");
        btnRelMusicas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnRelMusicasActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(59, 59, 59)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jLabel11)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtMusicaNome, javax.swing.GroupLayout.PREFERRED_SIZE, 218, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel13)
                            .addComponent(jLabel12))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(txtMusicaDur)
                            .addComponent(cbBandas2, 0, 227, Short.MAX_VALUE))))
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(btnCadMusica)
                        .addGap(18, 18, 18)
                        .addComponent(btnProcurarMusica)
                        .addGap(18, 18, 18)
                        .addComponent(btnRelMusicas))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addGap(159, 159, 159)
                        .addComponent(jLabel4)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                .addGap(0, 12, Short.MAX_VALUE)
                .addComponent(jLabel4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel11)
                    .addComponent(txtMusicaNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(txtMusicaDur, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel13)
                    .addComponent(cbBandas2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(16, 16, 16)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnCadMusica)
                    .addComponent(btnProcurarMusica)
                    .addComponent(btnRelMusicas)))
        );

        jLabel5.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        jLabel5.setText("Playlists");

        jLabel14.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel14.setText("Nome");

        jLabel15.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N
        jLabel15.setText("Quantidade de Músicas");

        btnGerarPl.setText("Gerar Playlist");
        btnGerarPl.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGerarPlActionPerformed(evt);
            }
        });

        btnInfoPl.setText("Mostrar Informações");
        btnInfoPl.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnInfoPlActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addGroup(jPanel4Layout.createSequentialGroup()
                        .addComponent(btnGerarPl)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnInfoPl))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel4Layout.createSequentialGroup()
                        .addComponent(jLabel15)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtPlQntMu))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel4Layout.createSequentialGroup()
                        .addComponent(jLabel14)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtPlNome, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel4Layout.createSequentialGroup()
                        .addGap(103, 103, 103)
                        .addComponent(jLabel5)))
                .addGap(73, 73, 73))
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtPlNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel14))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel15)
                    .addComponent(txtPlQntMu, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnGerarPl)
                    .addComponent(btnInfoPl))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jLabel1.setFont(new java.awt.Font("Dialog", 0, 18)); // NOI18N
        jLabel1.setText("Tela Principal");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(24, 24, 24)
                        .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 453, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(33, 33, 33)
                        .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 79, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(34, 34, 34))
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(31, 31, 31)))
                .addGap(63, 63, 63))
            .addGroup(layout.createSequentialGroup()
                .addGap(479, 479, 479)
                .addComponent(jLabel1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(29, 29, 29)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 13, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 194, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 194, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 194, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 194, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(34, 34, 34))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btnCadBandaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCadBandaActionPerformed
        Banda banda = new Banda();
        
        if(txtBandaNome.getText().isEmpty() || txtBandaGen.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            banda.setNome(txtBandaNome.getText());
            banda.setGenero(txtBandaGen.getText());
            
            if(bb.cadastrar(banda) != null)
                JOptionPane.showMessageDialog(null, "Banda cadastrada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            else
                JOptionPane.showMessageDialog(null, "Banda já está cadastrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
        }
        
        limpar();
        popularTabelas();
        popularComboBoxes();
    }//GEN-LAST:event_btnCadBandaActionPerformed

    private void btnCadMusicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCadMusicoActionPerformed
        Musico musico = new Musico();
        
        if(txtMusicoNome.getText().isEmpty() || txtMusicoFunc.getText().isEmpty() || cbBandas1.getSelectedIndex() == -1)
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            musico.setNome(txtMusicoNome.getText());
            musico.setFuncao(txtMusicoFunc.getText());
            musico.setBanda(bb.getAll().get(cbBandas1.getSelectedIndex()));
            
            if(bmo.cadastrar(musico) != null) {
                bb.getAll().get(cbBandas1.getSelectedIndex()).adcMusico(musico);
                JOptionPane.showMessageDialog(null, "Músico cadastrado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            }
            else
                JOptionPane.showMessageDialog(null, "Músico já está cadastrado!", "Erro", JOptionPane.INFORMATION_MESSAGE);
        }
        
        limpar();
        popularTabelas();
    }//GEN-LAST:event_btnCadMusicoActionPerformed

    private void btnCadMusicaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCadMusicaActionPerformed
        Musica musica = new Musica();
        
        if(txtMusicaNome.getText().isEmpty() || txtMusicaDur.getText().isEmpty() || cbBandas2.getSelectedIndex() == -1)
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            try {
                musica.setNome(txtMusicaNome.getText());
                musica.setDuracao(Integer.parseInt(txtMusicaDur.getText()));
                musica.setBanda(bb.getAll().get(cbBandas2.getSelectedIndex()));
                if(bma.cadastrar(musica) != null) {
                    bb.getAll().get(cbBandas2.getSelectedIndex()).adcMusica(musica);
                    JOptionPane.showMessageDialog(null, "Música cadastrada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
                }
                else
                    JOptionPane.showMessageDialog(null, "Música já está cadastrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
            } catch(NumberFormatException nfe) {
                JOptionPane.showMessageDialog(null, "O campo duração deve ser um número inteiro", "Alerta", JOptionPane.INFORMATION_MESSAGE);
            }
        }
        
        limpar();
        popularTabelas();
    }//GEN-LAST:event_btnCadMusicaActionPerformed

    private void btnInfoBandaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnInfoBandaActionPerformed
        if(txtBandaNome.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Digite o nome da banda para mostrar informações!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            Banda banda = bb.procurarBanda(txtBandaNome.getText());
            if(banda == null)
                JOptionPane.showMessageDialog(null, "Banda não encontrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
            else {
                TelaInfoBanda.getTelaRelatorioBandas().mostrarInfo(banda);
            }
        }
        
        limpar();
    }//GEN-LAST:event_btnInfoBandaActionPerformed

    private void btnRelMusicasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnRelMusicasActionPerformed
        TelaRelatorioMusicas.getTelaRelatorioMusicas().gerarRelatorio(bma);
        
        limpar();
    }//GEN-LAST:event_btnRelMusicasActionPerformed

    private void btnRelMusicosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnRelMusicosActionPerformed
        TelaRelatorioMusicos.getTelaRelatorioMusicos().gerarRelatorio(bmo);
        
        limpar();
    }//GEN-LAST:event_btnRelMusicosActionPerformed

    private void btnInfoPlActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnInfoPlActionPerformed
        if(txtPlNome.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Digite o nome da playlist para mostrar informações!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            Playlist playlist = bp.procurarPlaylist(txtPlNome.getText());
            if(playlist == null)
                JOptionPane.showMessageDialog(null, "Playlist não encontrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
            else {
                TelaInfoPlaylist.getTelaInfoPlaylist().mostrarInfo(playlist);
            }
        }
        
        limpar();
    }//GEN-LAST:event_btnInfoPlActionPerformed

    private void btnProcurarMusicoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnProcurarMusicoActionPerformed
        if(txtMusicoNome.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Digite o nome do músico que deseja procurar!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            Musico musico = bmo.procurarMusico(txtMusicoNome.getText());
            if(musico == null)
                JOptionPane.showMessageDialog(null, "Músico não encontrado!", "Erro", JOptionPane.INFORMATION_MESSAGE);
            else
                JOptionPane.showMessageDialog(null, "Nome: " + musico.getNome() + "\nFunção: " + musico.getFuncao() + "\nBanda: " + musico.getBanda().getNome(), "Músico encontrado", JOptionPane.INFORMATION_MESSAGE);
        }
        
        limpar();
    }//GEN-LAST:event_btnProcurarMusicoActionPerformed

    private void btnProcurarMusicaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnProcurarMusicaActionPerformed
        if(txtMusicaNome.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Digite o nome da música que deseja procurar!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            Musica musica = bma.procurarMusica(txtMusicaNome.getText());
            if(musica == null)
                JOptionPane.showMessageDialog(null, "Música não encontrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
            else
                JOptionPane.showMessageDialog(null, "Nome: " + musica.getNome() + "\nFunção: " + musica.getDuracao() + "\nBanda: " + musica.getBanda().getNome(), "Músico encontrada", JOptionPane.INFORMATION_MESSAGE);
        }
        
        limpar();
    }//GEN-LAST:event_btnProcurarMusicaActionPerformed

    private void btnGerarPlActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGerarPlActionPerformed
        Playlist playlist = new Playlist();
        
        if(txtPlNome.getText().isEmpty() || txtPlQntMu.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        else {
            try {
                playlist.setNome(txtPlNome.getText());
                playlist.setQuantidadeMusicas(Integer.parseInt(txtPlQntMu.getText()));
                
                if(playlist.getQuantidadeMusicas() > bma.getAll().size() || playlist.getQuantidadeMusicas() <= 0)
                    JOptionPane.showMessageDialog(null, "A playlist deve ter uma quantidade de músicas maior que 0 e menor que a quantidade de músicas cadastradas!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
                else {
                    if(bp.gerar(playlist, bma.getAll()) != null)
                        JOptionPane.showMessageDialog(null, "Playlist gerada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
                    else
                        JOptionPane.showMessageDialog(null, "Playlist com este nome já foi cadastrada!", "Erro", JOptionPane.INFORMATION_MESSAGE);
                }
            } catch(NumberFormatException nfe) {
                JOptionPane.showMessageDialog(null, "O campo quantidade de músicas deve ser um número inteiro", "Alerta", JOptionPane.INFORMATION_MESSAGE);
            }
        }
        
        limpar();
        popularTabelas();
    }//GEN-LAST:event_btnGerarPlActionPerformed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaPrincipal().setVisible(true);
            }
        });
    }

    public void limpar() {
        txtBandaGen.setText("");
        txtBandaNome.setText("");
        txtMusicaDur.setText("");
        txtMusicaNome.setText("");
        txtMusicoFunc.setText("");
        txtMusicoNome.setText("");
        txtPlNome.setText("");
        txtPlQntMu.setText("");
    }
    
    public void popularTabelas() {
        if(!bb.getAll().isEmpty()) {
            DefaultTableModel modeloBandas = (DefaultTableModel) tabBandas.getModel();
            int i = 0;
            modeloBandas.setRowCount(i);
            for(Banda banda : bb.getAll()) {
                modeloBandas.insertRow(i, new Object[]{
                    banda.getNome(),
                    banda.getGenero()
                });
                i++;
            }
        }
        
        if(!bma.getAll().isEmpty()) {
            DefaultTableModel modeloMusicas = (DefaultTableModel) tabMusicas.getModel();
            int i = 0;
            modeloMusicas.setRowCount(i);
            for(Musica musica : bma.getAll()) {
                modeloMusicas.insertRow(i, new Object[]{
                    musica.getNome(),
                    musica.getDuracao()
                });
                i++;
            }
        }
        
        if(!bmo.getAll().isEmpty()) {
            DefaultTableModel modeloMusicos = (DefaultTableModel) tabMusicos.getModel();
            int i = 0;
            modeloMusicos.setRowCount(i);
            for(Musico musico : bmo.getAll()) {
                modeloMusicos.insertRow(i, new Object[]{
                    musico.getNome(),
                    musico.getFuncao()
                });
                i++;
            }
        }
        
        if(!bp.getAll().isEmpty()) {
            DefaultTableModel modeloPlaylists = (DefaultTableModel) tabPlaylists.getModel();
            int i = 0;
            modeloPlaylists.setRowCount(i);
            for(Playlist playlist : bp.getAll()) {
                modeloPlaylists.insertRow(i, new Object[]{
                    playlist.getNome(),
                    playlist.getQuantidadeMusicas(),
                    playlist.getDuracao()
                });
                i++;
            }
        }
    }
    
    public void popularComboBoxes() {
        DefaultComboBoxModel modeloComboBox1 = (DefaultComboBoxModel) cbBandas1.getModel();
        DefaultComboBoxModel modeloComboBox2 = (DefaultComboBoxModel) cbBandas2.getModel();
        
        modeloComboBox1.removeAllElements();
        modeloComboBox2.removeAllElements();
        
        if(!bb.getAll().isEmpty()) {
            for(Banda banda : bb.getAll()) {
                modeloComboBox1.addElement(banda.getNome());
                modeloComboBox2.addElement(banda.getNome());
            }
        }
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCadBanda;
    private javax.swing.JButton btnCadMusica;
    private javax.swing.JButton btnCadMusico;
    private javax.swing.JButton btnGerarPl;
    private javax.swing.JButton btnInfoBanda;
    private javax.swing.JButton btnInfoPl;
    private javax.swing.JButton btnProcurarMusica;
    private javax.swing.JButton btnProcurarMusico;
    private javax.swing.JButton btnRelMusicas;
    private javax.swing.JButton btnRelMusicos;
    private javax.swing.JComboBox<String> cbBandas1;
    private javax.swing.JComboBox<String> cbBandas2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JTable tabBandas;
    private javax.swing.JTable tabMusicas;
    private javax.swing.JTable tabMusicos;
    private javax.swing.JTable tabPlaylists;
    private javax.swing.JTextField txtBandaGen;
    private javax.swing.JTextField txtBandaNome;
    private javax.swing.JTextField txtMusicaDur;
    private javax.swing.JTextField txtMusicaNome;
    private javax.swing.JTextField txtMusicoFunc;
    private javax.swing.JTextField txtMusicoNome;
    private javax.swing.JTextField txtPlNome;
    private javax.swing.JTextField txtPlQntMu;
    // End of variables declaration//GEN-END:variables
}
