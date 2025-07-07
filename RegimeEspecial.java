package javaapplication16;

public class RegimeEspecial extends Disciplina {

    private double notaP1;
    private double notaP2;

        // metodo construtor    
    public RegimeEspecial(String nome, double notaP1, double notaP2) {
        super(nome);
        this.setNotaP1(notaP1);
        this.setNotaP2(notaP2);
    }

    // metodos sobrescritos
    @Override
    public double calcularMedia() {
        double notaFinal = 0;

        notaFinal = (this.getNotaP1() + this.getNotaP2()) / 2;

        return notaFinal;
    }

    @Override
    public boolean situacaoAprovacao() {
        return this.calcularMedia() >= 5;
    }

    //metodos especiais
    public double getNotaP1() {
        return notaP1;
    }

    public void setNotaP1(double notaP1) {
        this.notaP1 = notaP1;
    }

    public double getNotaP2() {
        return notaP2;
    }

    public void setNotaP2(double notaP2) {
        this.notaP2 = notaP2;
    }


}
