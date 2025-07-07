package javaapplication16;

public class Aluno {

    private String nome;
    private String ra;
    private Disciplina disciplinas[];

//metodo construtor
    public Aluno(String nome, String ra, Disciplina disciplinas[]) {
        this.setNome(nome);
        this.setRa(ra);
        this.setDisciplinas(disciplinas);
    }

//metodos especiais 
    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getRa() {
        return ra;
    }
    
    public void setRa(String ra) {
        this.ra = ra;
    }
    
    public Disciplina[] getDisciplinas() {
        return disciplinas;
    }
    
    public void setDisciplinas(Disciplina[] disciplinas) {
        this.disciplinas = disciplinas;
    }
    
}
