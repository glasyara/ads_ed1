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

    int added = 0;
    added = lista->tamanho;

    int i = 0;
    i = lista->tamanho;
    do {
        
       if (i != p) {
        lista->elementos[i] = lista->elementos[i-1];
        i--;
       }
        else if (i == p) {
            lista->elementos[i] = valor;
            lista->tamanho++;
        }

    } while (added == lista->tamanho);

       //int i = 0;
       //for(i = lista->tamanho - 1; i >=p; i--);
       //lista->elementos[i+1] = lista->elementos[i];
       //lista->elementos[p] = valor;
       //lista->tamanho++;
    return 1;
    
}

int remove_da_posicao(Lista *lista, int p) {
        if(lista == NULL) {
        return 0;
    }
    if(lista_cheia(lista) == 1) {
        return 0;
    }


    int i = 0;
    i = lista->tamanho - 1;
    do {
        
        if (i != p) {
        lista->elementos[p] = lista->elementos[p+1];
        p++;
        }
        if (i == p) {
            lista->tamanho--;
        }
        

    } while (i != p); 


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

    remove_da_posicao(lista, 4);

    int estaVazia = lista_vazia(lista);
    int tamanho = tamanho_da_lista(lista);

    printf("A lista esta vazia? %d", estaVazia);
    printf("\nQuantidade de elementos na lista: %d", tamanho);

    
    for (int i = 0; i < lista->tamanho; i++)
    printf("\nelemento[%i] = %d\n", i, lista->elementos[i]);
    return 0;
}