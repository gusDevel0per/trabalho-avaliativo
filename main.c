#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  struct Professor {
    char nome_professor[40];
    int funcional;
    int titulacao; // Usando tipo inteiro para a titulação
};

struct Disciplina {
    char nome[30];
    int codigo;
    int carga_horaria;
    struct Professor professor_responsavel; 
};

struct Aluno {
    char nome_aluno[40];
    int matricula;
    int idade;
    struct Disciplina disciplina;
};
void ordem_crescente(struct Aluno Aln[]){
	int o=0, p=0, aux=0;
	  for (o = 0; o < 15 - 1; o++) {
        for (p = 0; p < 15 - o - 1; p++) {
            if (Aln[p].idade > Aln[p + 1].idade) {
                aux = Aln[p].idade;
                Aln[p].idade = Aln[p + 1].idade;
                Aln[p + 1].idade = aux;
            }
        }
    }	
}
  
  
int le_valida_idade(){
  int idade;
  do {
    printf("Idade do aluno: ");
    scanf("%d", &idade);
    getchar();

    if(idade < 16 || idade > 26){
      printf("Idade invalida");
    }
  }while(idade < 16 || idade > 26);
  return idade;  
}

int main() {

  struct Professor prof[3];
  struct Disciplina Dsp[2];
  struct Aluno Aln[15];
  
  int i, j, k, m, l, o, p, q, r, aux;
  int num= 0, checker = 0;

  for (i = 0; i < 3; i++) {
        printf("Nome do professor: ");
        scanf(" %[^\n]s", &prof[i].nome_professor);

        printf("Funcional do professor: ");
        scanf("%d", &prof[i].funcional);

        printf("Titulação do professor:\n1- Especialista\n2- Mestrado\n3- Doutorado\n");
        scanf("%d", &prof[i].titulacao);
    
    }
  for(j=0;j<2; j++){
    printf("nome da disciplina: ");
    scanf("%s", &Dsp[j].nome);

    printf("Codigo disciplina: ");
    scanf("%d", &Dsp[j].codigo);

    printf("Carga horaria: ");
    scanf("%d", &Dsp[j].carga_horaria);
      
  }

  

  for(k=0;k<15;k++){
    printf("Nome do aluno: ");
    scanf("%[^\n]s", &Aln[k].nome_aluno);

    printf("Matricula do aluno: ");
    scanf("%d",&Aln[k].matricula);
    
    Aln[k].idade = le_valida_idade();

    if (k<10){
      Aln[k].disciplina = Dsp[0];
    }
    if (k>=10){
      Aln[k].disciplina = Dsp[1];
    }
  }

  ordem_crescente(Aln);

   for (k = 0; k < 15; k++) {
        printf("Idade %d: %d\n", k + 1, Aln[k].idade);
    }

  printf("-----------------------------------------\n");
  for(q=0; q<10; q++){
    printf("%d %s %s %d\n", Aln[i].disciplina.codigo, Aln[i].nome_aluno, Aln[i].disciplina.professor_responsavel.nome_professor, Aln[i].idade);
  }
  for(r=14;r>=10;r--){
    printf("%d %s %s %d\n", Aln[i].disciplina.codigo, Aln[i].nome_aluno, Aln[i].disciplina.professor_responsavel.nome_professor, Aln[i].idade);
  }
  return 0;
}

