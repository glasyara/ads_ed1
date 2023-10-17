#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct {
    int tamanho;
    int elementos[MAX];
} Lista;

int lista_vazia(Lista *lista){
    return lista->tamanho == 0;
}

int tamanho_da_lista(Lista *lista) {
    return lista->tamanho;
}

int lista_cheia(Lista *lista) {
    if (lista->tamanho == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int insere_no_final(Lista *lista, int valor) {
    if(lista == NULL) {
        return 0;
    }
    if(lista_cheia(lista) == 1) {
        return 0;
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

int insere_na_posicao(Lista *lista, int p, int valor) {
    if(lista == NULL) {
        return 0;
    }
    if(lista_cheia(lista) == 1) {
        return 0;
    }
       int i = 0;
       for(i = lista->tamanho - 1; i >=p; i--);
       lista->elementos[i+1] = lista->elementos[i];
       lista->elementos[p] = valor;
       lista->tamanho++;
    return 1;
    
}

int remove_da_posicao(Lista *lista, int p) {
        if(lista == NULL) {
        return 0;
    }
    if(lista_cheia(lista) == 1) {
        return 0;
    }
       for(p < lista->tamanho - 1; p++;)
       lista->elementos[p] = lista->elementos[p+1];
       lista->tamanho--;
       return 1;
    
}

Lista* cria_lista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    return lista;
}

int main(int argc, char** argv) {
    Lista *lista1 = NULL;

    Lista *lista = cria_lista();
    
    insere_no_final(lista, 7);
    insere_no_final(lista, 3);
    insere_no_final(lista, 5);

    insere_na_posicao(lista, 2, 1);
    insere_na_posicao(lista, 2, 5);
    insere_na_posicao(lista, 3, 9);
    insere_na_posicao(lista, 3, 3);

    int estaVazia = lista_vazia(lista);
    int tamanho = tamanho_da_lista(lista);

    printf("A lista esta vazia? %d", estaVazia);
    printf("\nQuantidade de elementos na lista: %d", tamanho);

    printf("elemento[0] = %d\n", lista->elementos[0]);
    printf("elemento[1] = %d\n", lista->elementos[1]);
    printf("elemento[2] = %d\n", lista->elementos[2]);
    printf("elemento[3] = %d\n", lista->elementos[3]);
    printf("elemento[4] = %d\n", lista->elementos[4]);
    printf("elemento[5] = %d\n", lista->elementos[5]);
    printf("elemento[6] = %d\n", lista->elementos[6]);
    printf("elemento[7] = %d\n", lista->elementos[7]);
    printf("elemento[8] = %d\n", lista->elementos[8]);
    printf("elemento[9] = %d\n", lista->elementos[9]);
    printf("elemento[10] = %d\n", lista->elementos[10]);
}