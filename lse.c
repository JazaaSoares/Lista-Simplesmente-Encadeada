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
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    imprimirLista(lista);
}

void inserirElementoFinal(Lista* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));  // Aloca mem�ria para o novo n�
    novo->valor = valor;
    novo->prox = NULL;  // Como o n� � o �ltimo, o pr�ximo ser� NULL

    if (lista->inicio == NULL) {  // Verifica se a lista est� vazia
        lista->inicio = novo;  // Se estiver vazia, o novo n� ser� o primeiro
    } else {
        No* atual = lista->inicio;
        while (atual->prox != NULL) {  // Loop at� o final da lista
            atual = atual->prox;  // Move para o pr�ximo n�
        }
        atual->prox = novo;  // Define o pr�ximo do �ltimo n� como o novo n�
    }
    lista->tamanho++;  // Atualiza o tamanho da lista
    imprimirLista(lista);  // Imprime a lista ap�s a inser��o
}

void inserirElementoPosicao(Lista* lista, int valor, int posicao){
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("-POSI��O INV�LIDA-\n");
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
    imprimirLista(lista);
}

void removerElementoPosicao(Lista* lista, int posicao){
    if (posicao < 0 || posicao >= lista->tamanho){
        printf("-POSI��O INV�LIDA-\n");
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
    imprimirLista(lista);
}

void removerElementoValor(Lista *lista, int valor){
    No* atual = lista->inicio;
    No* ant = NULL;

    while (atual != NULL && atual->valor != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("-VALOR N�O ENCONTRADO-\n");
        return;
    }

    if (ant == NULL) {
        lista->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    lista->tamanho--;
    imprimirLista(lista);

}

int obterElementoPosicao(Lista* lista, int posicao){
     if (posicao < 0 || posicao >= lista->tamanho) {
        printf("-POSI��O INV�LIDA-\n");
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

    return -1;  // Valor n�o encontrado

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
                system("pause");
                system("cls || clear");
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                inserirElementoFinal(lista, valor);
                printf("Elemento inserido no final com sucesso!\n");
                system("pause");
                system("cls || clear");
                break;
            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posi��o onde deseja inserir: ");
                scanf("%d", &posicao);
                inserirElementoPosicao(lista, valor, posicao);
                printf("Elemento inserido na posicao %d com sucesso!\n", posicao);
                system("pause");
                system("cls || clear");
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerElementoValor(lista, valor);
                printf("Elemento removido com sucesso!\n");
                system("pause");
                system("cls || clear");
                break;
            case 5:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                removerElementoPosicao(lista, posicao);
                printf("Elemento na posicao %d removido com sucesso!\n", posicao);
                system("pause");;
                system("cls || clear");
                break;
            case 6:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                valor = obterElementoPosicao(lista, posicao);
                if (valor != -1) {
                    printf("Valor na posicao %d: %d\n", posicao, valor);
                }
                system("pause");
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
                system("pause");
                system("cls || clear");
                break;
            case 8:
                printf("Tamanho da lista: %d\n", tamanhoLista(lista));
                system("pause");
                system("cls || clear");
                break;
            case 9:
                printf("Lista: ");
                imprimirLista(lista);
                system("pause");
                system("cls || clear");
                break;
            case 0:
                liberarLista(lista);
                printf("Saindo...\n");
                sleep(1);
                system("cls || clear");
                break;
            default:
                printf("Opcao invalida\n");
                sleep(1);
                system("cls || clear");
                break;
        }
    } while (opc != 0);

}


