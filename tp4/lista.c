// TAD lista de números inteiros
// Carlos Maziero - DINF/UFPR, Out 2024
//
// Implementação do TAD - a completar
//
// Implementação com lista encadeada dupla não-circular

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

// estrutura de um item (nó) da lista
struct item_t
{
  int valor;
  struct item_t *ant;
  struct item_t *prox;
};

// estrutura de controle da lista
struct lista_t
{
  int tamanho;
  struct item_t *ini;
  struct item_t *fim;
};

// Cria uma lista vazia.
// Retorno: ponteiro p/ a lista ou NULL em erro.
struct lista_t *lista_cria()
{
  struct lista_t *pLista = malloc(sizeof(struct lista_t));

  if (!pLista)
    return NULL;

  memset(pLista, 0, sizeof(struct lista_t));

  return pLista;
}

// Remove todos os itens da lista e libera a memória.
// Retorno: NULL.
struct lista_t *lista_destroi(struct lista_t *lst)
{
  if (!lst)
    return NULL;

  struct item_t *aux;

  for (int i = 0; i < lst->tamanho; i++)
  {
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
int lista_insere(struct lista_t *lst, int item, int pos)
{
  if (!lst || pos < -1)
    return -1;

  struct item_t *novo_elemento = malloc(sizeof(struct item_t));

  if (!novo_elemento)
    return -1;

  memset(novo_elemento, 0, sizeof(struct item_t));

  novo_elemento->valor = item;

  // caso seja o primeiro elemento da lista
  if (!lst->tamanho)
  {
    lst->ini = novo_elemento;
    lst->fim = novo_elemento;
    return ++lst->tamanho;
  }

  // caso seja o ultimo elemento da lista
  if (pos >= lst->tamanho || pos == -1)
  {
    lst->fim->prox = novo_elemento;
    novo_elemento->ant = lst->fim;
    lst->fim = novo_elemento;
    return ++lst->tamanho;
  }

  struct item_t *aux = lst->ini;

  int i = 0;

  // caso seja no meio da lista
  while (i < pos)
  {
    aux = aux->prox;
    i++;
  }

  novo_elemento->prox = aux;
  novo_elemento->ant = aux->ant;

  if (pos)
    aux->ant->prox = novo_elemento;
  else
    lst->ini = novo_elemento;

  aux->ant = novo_elemento;

  return ++lst->tamanho;
}

// Retira o item da lista da posição indicada.
// se a posição for além do fim da lista ou for -1, retira do fim.
// Retorno: número de itens na lista após a operação ou -1 em erro.
int lista_retira(struct lista_t *lst, int *item, int pos)
{
  if (!lst || lst->tamanho == 0 || pos < -1)
    return -1;

  struct item_t *aux = lst->ini;

  // caso seja o primeiro
  if (!pos)
  {
    aux = lst->ini;
    *item = lst->ini->valor;
    lst->ini = aux->prox;

    if (lst->ini)
      lst->ini->ant = NULL;
    else
      lst->fim = NULL;

    free(aux);
    return --lst->tamanho;
  }

  // caso seja o ultimo
  if (pos >= lst->tamanho || pos == -1)
  {
    aux = lst->fim;
    *item = lst->fim->valor;
    lst->fim = aux->ant;

    if (lst->fim)
      lst->fim->prox = NULL;
    else
      lst->ini = NULL;

    free(aux);
    return --lst->tamanho;
  }

  // caso seja no meio do vetor
  int i = 0;

  while (i < pos)
  {
    aux = aux->prox;
    i++;
  }

  *item = aux->valor;
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;

  free(aux);

  return --lst->tamanho;
}

// Informa o valor do item na posição indicada, sem retirá-lo.
// se a posição for além do fim da lista ou for -1, consulta do fim.
// Retorno: número de itens na lista ou -1 em erro.
int lista_consulta(struct lista_t *lst, int *item, int pos)
{
  if (!lst || !item || lst->tamanho == 0 || pos < -1)
    return -1;

  struct item_t *aux = lst->ini;

  if (pos >= lst->tamanho)
    return -1;

  if(pos == -1) {
    *item = lst->fim->valor;
    return lst->tamanho;
  }

  int i = 0;

  while (i < pos)
  {
    aux = aux->prox;
    i++;
  }

  *item = aux->valor;

  return lst->tamanho;
}

// Informa a posição da 1ª ocorrência do valor indicado na lista.
// Retorno: posição do valor ou -1 se não encontrar ou erro.
int lista_procura(struct lista_t *lst, int valor)
{
  if (!lst)
    return -1;

  struct item_t *aux = lst->ini;

  int i = 0;

  while (i < lst->tamanho)
  {
    if (aux->valor == valor)
      return i;

    aux = aux->prox;
    i++;
  }

  return -1;
}

// Informa o tamanho da lista (o número de itens presentes nela).
// Retorno: número de itens na lista ou -1 em erro.
int lista_tamanho(struct lista_t *lst)
{
  if (!lst)
    return -1;

  return lst->tamanho;
}

// Imprime o conteúdo da lista do inicio ao fim no formato "item item ...",
// com um espaço entre itens, sem espaços antes/depois, sem newline.
void lista_imprime(struct lista_t *lst)
{
  if (!lst)
    return;

  struct item_t *aux = lst->ini;

  if (!lst->tamanho)
  {
    return;
  }

  for (int i = 0; i < lst->tamanho - 1; i++)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }

  printf("%d", aux->valor);
}