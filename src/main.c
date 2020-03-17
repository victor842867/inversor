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
void criar_pilha(p_pilha pilha);
void empilha(p_pilha p, char c);
/******************************************************/
const int tam_buffer=100;

int main() {
  int i; /*contador*/
  char caractere;
  char buffer[tam_buffer];
  p_pilha pilha; /*Minha pilha vai ser do tipo p_no pois ela sera uma lista ligada*/

  criar_pilha(pilha);
  printf("tamanho = %d\n",pilha->tamanho);
  empilha(pilha,'d');

  fgets(buffer, tam_buffer, stdin);
  printf("%s", buffer);

printf("ˆˆˆˆˆˆˆPrintando as letras da minha frase separadamenteˆˆˆˆˆˆˆ\n");
for(i=0;caractere != '\n';i++){
  caractere = buffer[i];
  if(caractere != '\n'){
  printf("%c\n",caractere);
  }
}

  return 0;
}

/*Funcoes que foram utilizadas no programa*/
void criar_pilha(p_pilha pilha){
  pilha = malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

void empilha(p_pilha p, char c){
  printf("teste1\n");
  p_no novo;
  novo = malloc(sizeof(No));
  printf("teste2\n");
  novo->letra = c;
  printf("letra recebida = %c\n", novo->letra);
  printf("teste3\n");
  novo->prox = p->topo;
  printf("teste4\n");
  p->topo = novo;
  printf("teste5\n");
  p->tamanho++;
  printf("teste6\n");
}
