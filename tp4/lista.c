// TAD lista de números inteiros
// Carlos Maziero - DINF/UFPR, Out 2024
//
// Implementação do TAD - a completar
//
// Implementação com lista encadeada dupla não-circular

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

// Cria uma lista vazia.
// Retorno: ponteiro p/ a lista ou NULL em erro.
struct lista_t *lista_cria () {
  lista_t *pLista = malloc(sizeof(struct lista_t));

  if (!pLista)
    return NULL;

  memset(pLista, 0, sizeof(struct lista_t));

  return pLista;
}

// Remove todos os itens da lista e libera a memória.
// Retorno: NULL.
struct lista_t *lista_destroi (struct lista_t *lst) {
  if (!lst)
    return NULL;

  struct elemento *aux;

  for (int i = 0; i < lst->tamanho; i++) {
    aux = lst->ini;
    lst->ini = aux->prox;
    free(aux);
  }

  free(lst);
  return NULL;
}

// Nas operações insere/retira/consulta/procura, a lista inicia na
// posição 0 (primeiro item) e termina na posição TAM-1 (último item).

// Insere o item na lista na posição indicada;
// se a posição for além do fim da lista ou for -1, insere no fim.
// Retorno: número de itens na lista após a operação ou -1 em erro.
int lista_insere (struct lista_t *lst, int item, int pos) {
  struct item_t *novo_elemento = malloc(sizeof(struct item_t));

  memset(novo_elemento, 0, sizeof(struct item_t));

  

  if(pos > lst->tamanho || pos == -1) {
  }

  struct item_t *aux = lst->ini;

  for(int i = 0; i < lst->tamanho; i++) {
    if (i == pos)
      break;
    
    aux = ls
  }

  novo_elemento->valor = item;
  novo_elemento->prox = lst->
  
}

// Retira o item da lista da posição indicada.
// se a posição for além do fim da lista ou for -1, retira do fim.
// Retorno: número de itens na lista após a operação ou -1 em erro.
int lista_retira (struct lista_t *lst, int *item, int pos);

// Informa o valor do item na posição indicada, sem retirá-lo.
// se a posição for além do fim da lista ou for -1, consulta do fim.
// Retorno: número de itens na lista ou -1 em erro.
int lista_consulta (struct lista_t *lst, int *item, int pos);

// Informa a posição da 1ª ocorrência do valor indicado na lista.
// Retorno: posição do valor ou -1 se não encontrar ou erro.
int lista_procura (struct lista_t *lst, int valor);

// Informa o tamanho da lista (o número de itens presentes nela).
// Retorno: número de itens na lista ou -1 em erro.
int lista_tamanho (struct lista_t *lst);

// Imprime o conteúdo da lista do inicio ao fim no formato "item item ...",
// com um espaço entre itens, sem espaços antes/depois, sem newline.
void lista_imprime (struct lista_t *lst);