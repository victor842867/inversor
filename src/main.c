/* Data de submissao:
 * Nome: Victor Ferrari
 * RA:206515
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************/
/*Definindo as estruturas que serao utilizadas no meu programa*/

typedef struct No{
  char letra;
  struct No *prox;
} No;

typedef No * p_no;

typedef struct {
  p_no topo;
  int tamanho;
}Pilha;

typedef Pilha * p_pilha;

/******************************************************/


/******************************************************/
/*Definindo as funcoes que serao utilizadas no meu programa*/
p_pilha criar_pilha();
void empilha(p_pilha p, char c);
void imprimir_pilha(p_pilha p);
void destruir_pilha(p_no p);
/******************************************************/
const int tam_buffer=100;

int main() {
  int i; /*contador*/
  char caractere;
  char buffer[tam_buffer];
  p_pilha pilha; /*Minha pilha vai ser do tipo p_no pois ela sera uma lista ligada*/

  pilha = criar_pilha();

  fgets(buffer, tam_buffer, stdin);

  for(i=0;caractere != '\n';i++){
    caractere = buffer[i];
    if(caractere != '\n'){
      if(caractere != ' '){
        empilha(pilha,caractere);
      }
      else if(caractere == ' '){
        imprimir_pilha(pilha);
        printf(" ");
        destruir_pilha(pilha->topo);
        pilha->tamanho = 0;
      }
    }
    else
      imprimir_pilha(pilha);
  }
  printf("\n");
  destruir_pilha(pilha->topo);
  free(pilha);
  return 0;
}

/*Funcoes que foram utilizadas no programa*/
p_pilha criar_pilha(){
  p_pilha pilha = malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->tamanho = 0;
  return pilha;
}

void empilha(p_pilha p, char c){
  p_no novo;
  novo = malloc(sizeof(No));
  novo->letra = c;
  novo->prox = p->topo;
  p->topo = novo;
  p->tamanho++;
}

void imprimir_pilha(p_pilha p){
  int i;
  for(i=0;i<p->tamanho;i++){
    printf("%c",p->topo->letra);
    p->topo = p->topo->prox;
  }
}

void destruir_pilha(p_no p){
  if(p != NULL){
    destruir_pilha(p->prox);
    free(p);
  }
}
