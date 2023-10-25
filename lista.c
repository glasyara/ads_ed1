#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

#define boolToString(v) ((v) ? "true" : "false")

typedef struct {
  char* valor;
} Elemento;

typedef struct {
  int nelem;
  Elemento elementos[MAX];
} Lista;

Lista* inicializa_lista() {
    Lista* l = malloc(sizeof(Lista));
    l->nelem = 0;

    return l;
}

bool lista_cheia(Lista* l) {
    if (l->nelem == MAX) {
        return true;
    } else {
        return false;
    }
}

bool lista_vazia(Lista* l) {
    if (l->nelem == 0) {
        return true;
    } else {
        return false;
    }
}

void imprimir_lista(Lista* l) {
    printf("{");
    for (int i = 0; i < l->nelem; i++) {
    printf("%c", l->elementos[i]);
    }
    printf("}");
}

bool adiciona_elemento(Lista* l, Elemento e) {
    l->elementos[l->nelem] = e;
    l->nelem++;
}

int main(char* argc, int argv) {
    Lista* lista = NULL;
    Elemento* novo_elemento = NULL;

    lista = inicializa_lista();
    if(lista == NULL) {
        printf("\nErro ao inicializar a lista");
        return -1;
    }

    novo_elemento = malloc(sizeof(Elemento));
    novo_elemento->valor = "gato";
    adiciona_elemento(lista, *novo_elemento);

    bool listacheia = lista_cheia(lista);
    bool listavazia = lista_vazia(lista);

   printf("Lista vazia? %s\n", boolToString(listavazia));
   printf("Lista cheia? %s\n", boolToString(listacheia));



}
