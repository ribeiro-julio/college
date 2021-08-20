// Julio Cesar Garcia Ribeiro - RA: 1994484

public class Usuario extends Pessoa {
    private String email;
    private String senha;
    private boolean adm;
    
    public String getEmail() {
        return email;
    }
    public String getSenha() {
        return senha;
    }
    public boolean getAdm() {
        return adm;
    }
    
    public void setEmail(String email) throws StringsException {
        if(email.isEmpty() || (!email.contains("@") || !email.contains(".com")))
            throw new StringsException();
        else
            this.email = email;
    }
    public void setSenha(String senha) throws StringsException {
        if(senha.isEmpty())
            throw new StringsException();
        else
            this.senha = senha;
    }
    public void setAdm(String adm) throws StringsException {
        if(adm.isEmpty() || (!adm.equals("true") && !adm.equals("false")))
            throw new StringsException();
        else
            this.adm = Boolean.parseBoolean(adm);
    }
}
