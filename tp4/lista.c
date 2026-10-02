// TAD lista de números inteiros
// Carlos Maziero - DINF/UFPR, Out 2024
//
// Implementação do TAD - a completar
//
// Implementação com lista encadeada dupla não-circular

// estrutura de um item (nó) da lista
struct item_t
{
  int valor;
  struct item_t *ant;
  struct item_t *prox;
} ;

// estrutura de controle da lista
struct lista_t
{
  int tamanho;
  struct item_t *ini;
  struct item_t *fim;
} ;
