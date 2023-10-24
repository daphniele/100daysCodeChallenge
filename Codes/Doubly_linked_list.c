// Data structure exercise about doubly linked lists, in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int dia;
  int mes;
  int ano;
} Data;


struct funcionario{
  int id;
  char nome[41];
  double salario;
  Data nascimento;
  struct funcionario *prev;
  struct funcionario *next;
}; 
typedef struct funcionario Funcionario;


// função para imprimir o nome de todos os funcioários

void imprime_lista (Funcionario* f) {
    Funcionario *aux;
    
    for (aux = f; aux != NULL; aux = aux->next) {
        printf("%s\n", aux -> nome);
    }
    
}


int main()
{
   
  // criar o primeiro funcionário da lista 
  Funcionario *first, *last;
  first = (Funcionario*) malloc (sizeof(Funcionario));
  first -> id = 1;
  strcpy(first -> nome, "Daniele Rohr");
  first -> salario = 5000.00;
  first -> nascimento.dia = 2;
  first -> nascimento.mes = 12;
  first -> nascimento.ano = 1989;
  first -> prev = NULL;
  first -> next = NULL;
  last = first;
  
  // adicionar o segundo funcionário da lista (no final)
  Funcionario *aux;
  aux = (Funcionario*) malloc (sizeof(Funcionario));
  aux -> id = 2;
  strcpy(aux -> nome, "Luiz Henrique Rigo Faccio");
  aux -> salario = 30000.00;
  aux -> nascimento.dia = 6;
  aux -> nascimento.mes = 11;
  aux -> nascimento.ano = 2003;
  aux -> next = NULL;
  aux -> prev = first;
  first -> next = aux;
  last = aux;
  
    // adicionar o terceiro funcionário da lista (no final)
  Funcionario *tres;
  tres = (Funcionario*) malloc (sizeof(Funcionario));
  tres -> id = 3;
  strcpy(tres -> nome, "Jacir Gaio");
  tres -> salario = 20000.00;
  tres -> nascimento.dia = 25;
  tres -> nascimento.mes = 02;
  tres -> nascimento.ano = 1980;
  tres -> next = NULL;
  tres -> prev = first;
  aux -> next = tres;
  last = tres;
  
  // imprimindo a lista com todos os funcionários
  imprime_lista(first);

    return 0;
}
