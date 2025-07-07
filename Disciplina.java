package javaapplication16;

public abstract class Disciplina {

    private String nome;

    public abstract double calcularMedia();

    public abstract boolean situacaoAprovacao();

    // metodo construtor
    public Disciplina(String nome) {
        this.setNome(nome);
    }

    // metodos especiais 
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

}
