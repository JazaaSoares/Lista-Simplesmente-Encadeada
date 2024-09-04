#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct Lista Lista;





Lista* criarLista();
void inserirElementoInicio(Lista* lista, int valor);
void inserirElementoFinal(Lista* lista, int valor);
void inserirElementoPosicao(Lista* lista, int valor, int posicao);
void removerElementoPosicao(Lista* lista, int posicao);
void removerElementoValor(Lista *lista, int valor);
int obterElementoPosicao(Lista* lista, int posicao);
int procurarElemento(Lista* lista, int valor);
int tamanhoLista(Lista* lista);
void imprimirLista(Lista* lista);
void liberarLista(Lista* lista);
