#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct date
{
  int dia;
  int mes;
  int ano;
};
typedef struct date Date;


struct employee
{
  int id;
  char name[41];
  double income;
  Date dbirth;
  struct employee *next;
  struct employee *prev;
};
typedef struct employee Employee;


//imprimir todos os elementos da lista

void imprime (Employee * l)
{
  Employee *aux;

  for (aux = l; aux != NULL; aux = aux->next)
    {
      printf("%d  |  ", aux->id);
      printf ("%s\n", aux->name);
    }

}


//limpar todos os elementos da lista

void limpaTudo (Employee * f)
{
  while (f != NULL)
    {
      f = f->next;
      free (f->prev);

    }

}
//funC'C#o para imprimir a lista na ordem inversa, com recursividade

void imprimeReverso (Employee * f)
{
  if (f != NULL)
    {
      imprimeReverso (f->next);
      printf ("%d\n", f->id);
    }

}

// incluir elemento na lista (inC-cio)
Employee *insereItemInicio (Employee * first)
{

  Employee *aux;
  aux = (Employee *) malloc (sizeof (Employee));
  printf ("Digite a ID do funcionC!rio: ");
  scanf ("%d", &aux->id);
  printf ("Digite o nome do funcionC!rio: ");
  scanf (" %[^\n]s", aux->name);


  aux->prev = NULL;
  first->prev = aux;
  aux->next = first;

  return aux;
}


//incluior elemento na lista (fim)

Employee *insereItemFim (Employee * last)
{

  Employee *aux;
  aux = (Employee *) malloc (sizeof (Employee));
  printf ("Digite a ID do funcionC!rio: ");
  scanf ("%d", &aux->id);
  printf ("Digite o nome do funcionC!rio: ");
  scanf (" %[^\n]s", aux->name);

  aux->next = NULL;
  last->next = aux;
  aux->prev = last;
  last = aux;

  return last;
}


// incluir elemento na lista (meio-antes)

Employee *insBefore (Employee *first, int id)
{

  Employee *aux, *cont;

  for (cont = first; cont != NULL; cont = cont->next) {
      if (cont -> id == id) {
          break;
      }}

  if (cont == NULL) {      
      
          printf("ID não encontrado!\n");
          return first;
      }
  
  
  aux = (Employee *) malloc (sizeof (Employee));
  printf ("Digite a ID do funcionC!rio: ");
  scanf ("%d", &aux->id);
  printf ("Digite o nome do funcionC!rio: ");
  scanf (" %[^\n]s", aux->name);
  
  aux->next = cont;
  aux->prev = cont->prev;
  cont->prev->next = aux;
  cont->prev = aux;

  
  return first;
}


//incluir elemento na lista (meio-depois)

Employee *insAfter (Employee *first, int id)
{
  Employee *aux, *cont;
  aux = (Employee *) malloc (sizeof (Employee));
  printf ("Digite a ID do funcionário: ");
  scanf ("%d", &aux->id);
  printf ("Digite o nome do funcionario: ");
  scanf (" %[^\n]s", aux->name);
  
  for (cont = first; cont != NULL; cont = cont->next) {
      if (cont -> id == id) {
          break;
      }
  }
  
  
  aux->prev = cont;
  aux->next = cont->next;
  cont->next->prev = aux;
  cont->next = aux;
  
  return first;
}

//criar um novo nó da lista

//apenas encadear o novo nó criado


//excluir primeiro elemento da lista

Employee *deleteFirst(Employee *first) {
    
    if (first == NULL) {
        printf("A lista está vazia!");
        return first;
    }
    
    first = first->next;
    free(first->prev);
    first->prev = NULL;
    
    return first;
}



//excluir o último elemento da lista 

Employee *deleteLast(Employee *last) {
    
    if (last == NULL) {
        printf("Probrema");
        return last;
    }
    
    last = last->prev;
    free(last->next);
    last->next = NULL;
    
    return last;
}

//excluir elemento da lista (meio-antes)

//excluir elemento da lista (meio-depois)



//procurar elemento na lista
void imprimeEmployee (Employee *l, int id) {
    Employee *aux;
    
    
    for (aux = l; aux != NULL; aux = aux->next) {
        if (aux-> id == id) {
            break;
        }
    }
    
    if (aux == NULL) {
        printf("ID não encontrado!\n");
    }
    
    else {
        printf("%d  | ", aux-> id);
        printf("%s\n", aux-> name);
}
}



int
main ()
{
  Employee *first, *last;

  first = (Employee *) malloc (sizeof (Employee));

  first->id = 1;
  strcpy (first->name, "Daniele Rohr");
  first->income = 30000.00;
  first->dbirth.dia = 2;
  first->dbirth.mes = 12;
  first->dbirth.ano = 1989;
  first->next = NULL;
  first->prev = NULL;
  last = first;

  Employee *aux;
  aux = (Employee *) malloc (sizeof (Employee));


  aux->id = 2;
  strcpy (aux->name, "Lucas Buvi");
  first->next = aux;
  last = aux;
  aux->prev = first;
  aux->next = NULL;


  aux = (Employee *) malloc (sizeof (Employee));
  aux->id = 3;
  strcpy (aux->name, "Fernanda Buvi");
  aux->next = NULL;
  aux->prev = first->next;
  last = aux;
  aux->prev->next = aux;

  imprimeEmployee (first, 4);



 


  /*aux = (Employee*)malloc(sizeof(Employee));

     printf("Digite a ID do funcionC!rio: ");
     scanf("%d", &aux->id);

     while (aux->id != 0) {
     printf("Digite o nome: ");
     scanf(" %[^\n]s", aux->name);
     aux->next = NULL;
     aux->prev = last;
     last = aux;
     aux->prev->next = aux;

     aux = (Employee*)malloc(sizeof(Employee));

     printf("Digite a ID do funcionC!rio: ");
     scanf("%d", &aux->id);

     }
   */



  imprime (first);
  





  return 0;
}
