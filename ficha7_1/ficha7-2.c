#include "alunos.h"
#include <stdio.h>

int main() {
    Aluno a1 = { "Ana Cristina" , 91234, 16}; 
    Aluno a2 = { "Berto Almeida", 88919, 14};
    Aluno a3 = { "Casimiro Portanova", 89456, 15};

    Turma t1 = NULL;
    
    acrescentaAluno(&t1,a1);
    acrescentaAluno(&t1,a2);
    acrescentaAluno(&t1,a3);

    showTurma(t1);
    showTurmaRec(t1);

    showAluno(*procura(t1,88919));

    printf("Passaram %d alunos\n", aprovadosRec(t1));
}