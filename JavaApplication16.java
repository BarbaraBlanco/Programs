package javaapplication16;
public class JavaApplication16 {
    public static void main(String[] args) {
        Disciplina d1 = new DisciplinaRegular("Cálculo", 14, 80,
                new double[]{8.0, 7.5, 6.4, 7.8},
                new double[]{0.2, 0.3, 0.2, 0.3});
        
        Disciplina d2 = new DisciplinaRegular("Estrutura de Dados II", 17, 80,
                new double[]{6.6, 7.7, 8.8, 9.9},
                new double[]{0.1, 0.2, 0.3, 0.4});
        
        Disciplina d3 = new RegimeEspecial("Matemática Discreta", 7.7, 8.8);

        Disciplina d4 = new RegimeEspecial("Inteligência Artificial", 7.8, 8.9);

        Aluno alunoUm = new Aluno("César Lúcio Maia", "202310010", new Disciplina[]{d1, d2, d3, d4});
        
       Disciplina d5 = new DisciplinaRegular("Cálculo III", 44, 80,
                new double[]{3.0, 4.5, 6.6, 6.8},
                new double[]{0.3, 0.3, 0.3, 0.1});
       
       Disciplina d6 = new DisciplinaRegular("Estrutura de Dados II", 57, 80,
                new double[]{3.6, 6.7, 4.8, 9.9},
                new double[]{0.2, 0.2, 0.2, 0.4});

        Disciplina d7 = new RegimeEspecial("Sistemas Operacionais", 5.7, 4.3);
        

        Disciplina d8 = new RegimeEspecial("Inteligência Artificial", 7.2, 8.4);

        Aluno alunoDois = new Aluno("Bárbara Letícia Blanco", "202310023", new Disciplina[]{d5, d6, d7, d8});

        Aluno[] alunos = {alunoUm, alunoDois};

        for(Aluno aluno : alunos) {
            System.out.println("Aluno: " + aluno.getNome() + " - RA: " + aluno.getRa());

            for (Disciplina disci : aluno.getDisciplinas()) {
                System.out.println("Disciplina: " + disci.getNome());
                System.out.printf("Média: %.2f\n", disci.calcularMedia());
                System.out.println("Situação: " + (disci.situacaoAprovacao() ? "Aprovado" : "Reprovado"));

                if (disci instanceof DisciplinaRegular) {
                    DisciplinaRegular dr = (DisciplinaRegular) disci;
                    System.out.printf("Frequência: %.2f%%\n", dr.calcularFrequencia() * 100);
                }

                System.out.println("---------------------------");
            }
        }
    }
    
    
}
