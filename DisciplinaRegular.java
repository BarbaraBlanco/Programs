package javaapplication16;

public class DisciplinaRegular extends Disciplina {

    private int faltas;
    private int totalAulas;
    private double notasAvaliacoes[];
    private double pesosAvaliacoes[];

    // metodo construtor
    public DisciplinaRegular(String nome, int faltas, int totalAulas, double notasAvaliacoes[], double pesosAvaliacoes[]) {
        super(nome);
        this.setFaltas(faltas);
        this.setNotasAvaliacoes(notasAvaliacoes);
        this.setPesosAvaliacoes(pesosAvaliacoes);
        this.setTotalAulas(totalAulas);
    }

    // metodos   utilitarios
    public double calcularFrequencia() { // deve retornar um valor dentro do intervalo 0-1
        double frequencia = 0;

        frequencia = ((double)(this.getTotalAulas() - this.getFaltas()) / this.getTotalAulas());

        return frequencia;
    }

    // metodos sobrescritos
    @Override
    public double calcularMedia() {
        double nota = 0;
        double vetorSuporte[] = new double[this.notasAvaliacoes.length];

        for (int i = 0; i < this.notasAvaliacoes.length; i++) {
            vetorSuporte[i] = this.notasAvaliacoes[i] * this.pesosAvaliacoes[i];
            nota += vetorSuporte[i];
        }

        return nota;
    }

    @Override
    public boolean situacaoAprovacao() {
        return this.calcularFrequencia() >= 0.75 && this.calcularMedia() > 5;
    }

    //metodos especiais
    public int getFaltas() {
        return faltas;
    }

    public void setFaltas(int faltas) {
        this.faltas = faltas;
    }

    public int getTotalAulas() {
        return totalAulas;
    }

    public void setTotalAulas(int totalAulas) {
        this.totalAulas = totalAulas;
    }

    public double[] getNotasAvaliacoes() {
        return notasAvaliacoes;
    }

    public void setNotasAvaliacoes(double[] notasAvaliacoes) {
        this.notasAvaliacoes = notasAvaliacoes;
    }

    public double[] getPesosAvaliacoes() {
        return pesosAvaliacoes;
    }

    public void setPesosAvaliacoes(double[] pesosAvaliacoes) {
        this.pesosAvaliacoes = pesosAvaliacoes;
    }

}
