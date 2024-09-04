#include "lse.h"
#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    struct No* prox;

};

struct Lista {
    No* inicio;
    int tamanho;

};

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;

}

void inserirElementoInicio(Lista* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio; //cabeça
    lista->inicio = novo;
    lista->tamanho++;

}

void inserirElementoFinal(Lista* lista, int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->inicio == NULL) { //verifica se a lista ta vazia
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->prox != NULL) { // loop ate o final da lista
            atual->prox;
        }
        atual->prox = novo;
    }
    lista->tamanho++;

}

void inserirElementoPosicao(Lista* lista, int valor, int posicao){
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("-POSIÇÃO INVÁLIDA-\n");
        return;
    }

    if (posicao == 0) {
        inserirElementoInicio(lista, valor);
        return;
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    No* atual = lista->inicio;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->prox;

    }
    novo->prox = atual->prox;
    atual->prox = novo;
    lista->tamanho++;

}

void removerElementoPosicao(Lista* lista, int posicao){
    if (posicao < 0 || posicao >= lista->tamanho){
        printf("-POSIÇÃO INVÁLIDA-\n");
        return;
    }

    No* atual = lista->inicio;
    if (posicao == 0) {
        lista->inicio = atual->prox;
        free(atual);
    } else {
        No* ant = NULL;
        for (int i = 0; i < posicao; i++) {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = atual->prox;
        free (atual);
    }

    lista->tamanho--;

}

void removerElementoValor(Lista *lista, int valor){
    No* atual = lista->inicio;
    No* ant = NULL;

    while (atual != NULL && atual->valor != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("-VALOR NÃO ENCONTRADO-\n");
        return;
    }

    if (ant == NULL) {
        lista->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    lista->tamanho--;


}

int obterElementoPosicao(Lista* lista, int posicao){
     if (posicao < 0 || posicao >= lista->tamanho) {
        printf("-POSIÇÃO INVÁLIDA-\n");
        return -1;
    }

    No* atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }

    return atual->valor;


}

int procurarElemento(Lista* lista, int valor){
    No* atual = lista->inicio;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }
        atual = atual->prox;
        posicao++;
    }

    return -1;  // Valor não encontrado

}

int tamanhoLista(Lista* lista){
    return lista->tamanho;

}

void imprimirLista(Lista* lista){
     No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

}

void liberarLista(Lista* lista){
    No* atual = lista->inicio;
    No* proximo;

    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(lista);

}

void menu (){

struct Lista* lista = criarLista();
    int opc, valor, posicao;

    do {
        printf("Menu:\n");
        printf("1. Inserir Elemento no Inicio\n");
        printf("2. Inserir Elemento no Final\n");
        printf("3. Inserir Elemento por Posicao\n");
        printf("4. Remover Elemento por Valor\n");
        printf("5. Remover Elemento por Posicao\n");
        printf("6. Obter Elemento por Posicao\n");
        printf("7. Procurar Elemento\n");
        printf("8. Tamanho da Lista\n");
        printf("9. Imprimir Lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
        system("cls || clear");

        switch (opc) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inserirElementoInicio(lista, valor);
                printf("Elemento inserido no inicio com sucesso!\n");
                sleep(2);
                system("cls || clear");
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                inserirElementoFinal(lista, valor);
                printf("Elemento inserido no final com sucesso!\n");
                sleep(2);
                system("cls || clear");
                break;
            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posição onde deseja inserir: ");
                scanf("%d", &posicao);
                inserirElementoPosicao(lista, valor, posicao);
                printf("Elemento inserido na posicao %d com sucesso!\n", posicao);
                sleep(2);
                system("cls || clear");
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerElementoValor(lista, valor);
                printf("Elemento removido com sucesso!\n");
                sleep(2);
                system("cls || clear");
                break;
            case 5:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                removerElementoPosicao(lista, posicao);
                printf("Elemento na posicao %d removido com sucesso!\n", posicao);
                sleep(2);
                system("cls || clear");
                break;
            case 6:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                valor = obterElementoPosicao(lista, posicao);
                if (valor != -1) {
                    printf("Valor na posicao %d: %d\n", posicao, valor);
                }
                sleep(2);
                system("cls || clear");
                break;
            case 7:
                 printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                posicao = procurarElemento(lista, valor);
                if (posicao != -1) {
                    printf("Valor encontrado na posicao: %d\n", posicao);
                } else {
                    printf("Valor nao encontrado\n");
                }
                sleep(2);
                system("cls || clear");
                break;
            case 8:
                printf("Tamanho da lista: %d\n", tamanhoLista(lista));
                sleep(2);
                system("cls || clear");
                break;
            case 9:
                printf("Lista: ");
                imprimirLista(lista);
                sleep(2);
                system("cls || clear");
                break;
            case 0:
                liberarLista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                sleep(2);
                system("cls || clear");
                break;
        }
    } while (opc != 0);

}


