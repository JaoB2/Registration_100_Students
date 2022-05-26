#include<stdio.h>
#include<stdlib.h>

typedef struct Aluno{//CRIAÇÃO DE UM TYPEDEF (APELIDO) DE UM STRUCT (LISTA DE DADOS) QUE CONTEM ARMAZENADO OS DADOS DOS ALUNOS QUE SERÃO SOLICITADOS.
  char nome[50];
  char email[100];
  int matricula;
  float A1;
  float A2;
  float A3;
  float media;
} Aluno;

typedef struct Porcentagens{//CRIAÇÃO DE UM TYPEDEF PARA UM STRUCT QUE CONTEM OS DADOS DO VALOR EM PORCENTAGEM DE CADA PROVA.
  int A1;
  int A2;
  int A3;
  float porcentagemA1;
  float porcentagemA2;
  float porcentagemA3;
  float notaAprov;
} Porcentagens;

Aluno cad_aluno[100];//CRIO UMA VARIAVEL GLOBAL PARA O Aluno (APELIDO) DO STRUCT CRIADO ANTERIORMENTE.

Porcentagens porcento;//CRIO UMA VARIAVEL GLOBAL PARA O Porcentagens (APELIDO) DO STRUCT CRIADO ANTERIORMENTE.

void alterarNota(){//CRIO UMA FUNÇÃO QUE ME DARÁ A POSSIBILIDADE DE ALTERAR O VALOR DA NÓTA DE CORTE(A MÉDIA QUE DEVERÁ SER ALCANSADA PELOS ESTUDANTES).
  printf("Qual o valor da nova nota de aprovação:");
  scanf("%f",&porcento.notaAprov);
}

void zeraCadastro(Aluno aluno[]){//CRIO UMA FUNÇÃO QUE IRÁ COMPARAR AS MATRICULAS JÁ CADASTRADAS E IRÁ SE FOREM IGUAIS,EXCLUIR O ALUNO CADASTRADO DE ACORDO COM A SUA MATRICULA.
  int i;
  int matric;
    printf("Digite a matricula do aluno que deeja excluir: ");
    scanf("%i", &matric);
  for(i = 0; i < 100; i++ ){  
    if(matric == aluno[i].matricula){
      printf("\n\nAluno %s Removido", aluno[i].nome); 
      
      aluno[i].matricula = -1; 
    }
  }
}

void porcentagensProvas(Porcentagens porcentagem){//CRIO UMA FUNÇÃO QUE ME DARÁ A POSSIBILIDADE DE ALTERAR A PORCENTAGEM DOS VALORES DAS PROVAS.
  
  printf("Digite porcentual A1 ");
  scanf("%i", &porcentagem.A1);
  printf("Digite porcentual A2 ");
  scanf("%i", &porcentagem.A2);
  printf("Digite porcentual A3 ");
  scanf("%i", &porcentagem.A3);
  porcentagem.porcentagemA1 = porcentagem.A1 / 100;//COMO SERÁ DIGITADO UM NUMERO INTEIRO É NECESSARIO QUE SEJA FEITO A EQUAÇÃO.
  porcentagem.porcentagemA2 = porcentagem.A2 / 100;//COMO SERÁ DIGITADO UM NUMERO INTEIRO É NECESSARIO QUE SEJA FEITO A EQUAÇÃO.
  porcentagem.porcentagemA3 = porcentagem.A3 / 100;//COMO SERÁ DIGITADO UM NUMERO INTEIRO É NECESSARIO QUE SEJA FEITO A EQUAÇÃO.
}


int main (){
  porcento.porcentagemA1 = 0.20;//ARMAZENO UMA PORCENTAGEM PARA A PRIMEIRA PROVA.
  porcento.porcentagemA2 = 0.30;//ARMAZENO UMA PORCENTAGEM PARA A SEGUNDA PROVA.
  porcento.porcentagemA3 = 0.50;//ARMAZENO UMA PORCENTAGEM PARA A TERCEIRA PROVA.
  porcento.notaAprov = 7.00;//ARMAZENO UM VALOR COMO NOTA MÉDIA DE APROVAÇÃO.
  
  int opcao;
  int i;
  int l;//CRIO TRES VARIÁVEIS QUE IRÃO SER USADAS NOS MÉTODOS.
    
  for (i = 1; i <= 100;){//CRIO UM MÉTODO (for) QUE IRÁ REPETIR TODO O MEU main.  
    printf("\n\nCadastro dos Alunos:\n\n");
    printf("Digite o numero de uma das opções: \n");
    printf("1- Cadastrar aluno \n");
    printf("2- Listar alunos \n");
    printf("3- Alterar os percentuais das provas\n");
    printf("4- Alterar média de aprovação\n");
    printf("5- Listar média e nota dos alunos\n");
    printf("6- Listar alunos aprovados e Reprovados\n");
    printf("7- Apagar alunos\n");    
    printf("0- Sair\n\n");
    scanf("%d", &opcao);   
    switch(opcao){//CRIO UM MÉTODO (switch) QUE QUANDO A PESSOA DIGITAR ALGUM DOS NUMEROS ACIMA EXECUTARA UM MÉTODO DIFERENTE.
      case 1:
        fflush(stdin);//fflush(stdin); É UMA VARIAVEL TEMPORÁRIA, ELA IRÁ GUARDAR UM VALOR POR UM CURTO PERIODO DE TEMPO.
          printf ("\n Digite o nome do aluno:");
          scanf (" %49[^\n]", cad_aluno[i].nome);
        
        fflush(stdin);
          printf ("\n Digite o E-mail do aluno:");
          scanf ("%s", cad_aluno[i].email);
        
        fflush(stdin);
          printf ("\n Digite a matricula do aluno: ");
          scanf ("%i", &cad_aluno[i].matricula);
        
        fflush(stdin);              
          printf ("\n Digitar nota A1 do aluno: ");
          scanf ("%f", &cad_aluno[i].A1);
        
        fflush(stdin);
          printf ("\n Digitar nota A2 aluno: ");
          scanf ("%f", &cad_aluno[i].A2);
        
        fflush(stdin);
          printf ("\n Digitar nota A3 do aluno: ");
          scanf ("%f", &cad_aluno[i].A3);

        fflush(stdin);
          i++;
        
      break;
      case 2:
        for (l = 1; l <= 100; l++){//CRIO UM MÉTODO (for) QUE IRÁ REPETIR ATÉ TER MOSTRADO TODOS OS DADOS ARMAZENADOS NO struct AULA.
          if(l < i && cad_aluno[l].matricula != -1) {
            printf("\n\nNome: %s", cad_aluno[l].nome);
            printf("\nMatricula: %i", cad_aluno[l].matricula);             
            printf("\tEmail: %s", cad_aluno[l].email);
          }
          else{
            l = 100;
          }
        }
      break;
      case 3:
        porcentagensProvas(porcento);//AQUI É REALIZADO A CHAMADA DA FUNÇÃO porcentagensProvas(porcento) QUE QUANDO EXECUTADO DÁ A POSSIBILIDADE DE ALTERAR A PORCENTAGEM DO VALOR DAS NOTAS.
      break;
      case 4 :
        alterarNota();//AQUI É REALIZADO A CHAMADA DA FUNÇÃO alterarNota() QUE QUANDO EXECUTADO DÁ A POSSIBILIDADE DE ALTERAR A MÉDIA DAS NOTAS.
      break;
      case 5 :
        for (l = 1; l < i; l++){//NESTE MÉTODO (for) É IMPRIMIDO (MOSTRADO) NA TELA AS NOTAS E AS MÉDIAS DOS ALUNOS.
          if(l < i && cad_aluno[l].matricula != -1){
            cad_aluno[l].media = (cad_aluno[l].A1 * porcento.porcentagemA1) + (cad_aluno[l].A2 * porcento.porcentagemA2) + (cad_aluno[l].A3 * porcento.porcentagemA3); 

            printf("(%i) Matricula: %d\n", l, cad_aluno[l].matricula);
            printf("Nome:%s\n  Email:%s\n Nota A1: %.2f\n Nota A2: %.2f\n Nota A3: %.2f  \nMedia %.2f \n\n", cad_aluno[l].nome, cad_aluno[l].email, cad_aluno[l].A1, cad_aluno[l].A2, cad_aluno[l].A3, cad_aluno[l].media);
          }
        }
      break;
      case 6: 
        for(l = 1; l < i; l++ && cad_aluno[l].matricula != -1){//NESTE MÉTODO (for) É CONFERIDO A MÉDIA DOS ALUNOS, ELE REPETE VERIFICANDO OS ALUNOS CADASTRADOS LOGO APÓS ELE FAZ UM COMPARATIVO PARA SABER SE O ALUNO FOI APROVADO OU REPROVADO.
          if(l < i && cad_aluno[l].matricula != -1){
            cad_aluno[l].media = (cad_aluno[l].A1 * porcento.porcentagemA1) + (cad_aluno[l].A2 * porcento.porcentagemA2) + (cad_aluno[l].A3 * porcento.porcentagemA3); 
            printf("(%i) Matricula: %d\n", l, cad_aluno[l].matricula);
            printf("Nome:%s  Media:%.2f\n", cad_aluno[l].nome, cad_aluno[l].media);
          
            if (cad_aluno[l].media >= porcento.notaAprov && cad_aluno[l].media <= 10.00){//É REALIZADO UM COMPARATIVO PARA SABER SE O ALUNO FOI APROVADO OU NÃO.
              printf("APROVADO\n\n");
            }
            else {
              printf("REPROVADO\n\n");
            }   
          }
        }
      break;
      case 7:
        zeraCadastro(cad_aluno);//CHAMO A FUNÇÃO zeraCadastro PARA QUE ELE SEJA EXECUTADO E EXCLUA UM ALUNO CADASTRADO DE ACORDO COM A SUA MATRICULA.
      break;
      case 0 :
        exit(0);
      default:
        printf ("Opção invalida\n");//CASO NENHUM NUMERO VÁLIDO SEJA DIGITADO ESTÁ MENSAGEM IRÁ APARECER.
      break;
    }
  }
  return 0;
}
