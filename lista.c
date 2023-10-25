#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

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
    printf("[%s]", l->elementos[i]);
    }
    printf("}\n");
}

bool adiciona_elemento(Lista* l, Elemento e) {
    
    if (l->nelem == MAX) {
        return false;
    }
    
    l->elementos[l->nelem] = e;
    l->nelem++;
    return true;
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
    
    bool listacheia = lista_cheia(lista);
    bool listavazia = lista_vazia(lista);

   printf("\nLista vazia? %s\n", boolToString(lista_vazia(lista)));
   printf("Lista cheia? %s\n", boolToString(lista_cheia(lista)));

    imprimir_lista(lista);

    novo_elemento->valor = "gato";
    if (adiciona_elemento(lista, *novo_elemento) == true) {
        printf("Elemento '%s' inserido com sucesso na lista.\n", novo_elemento->valor);
    } else {
        printf("Erro ao inserir elemento na lista, lista cheia.\n");
    }
    novo_elemento->valor = "cachorro";
    if (adiciona_elemento(lista, *novo_elemento) == true) {
        printf("Elemento '%s' inserido com sucesso na lista.\n", novo_elemento->valor);
    } else {
        printf("Erro ao inserir elemento na lista, lista cheia.\n");
    }
    novo_elemento->valor = "pato";
    if (adiciona_elemento(lista, *novo_elemento) == true) {
        printf("Elemento '%s' inserido com sucesso na lista.\n", novo_elemento->valor);
    } else {
        printf("Erro ao inserir elemento na lista, lista cheia.\n");
    }
    

    printf("\nLista vazia? %s\n", boolToString(lista_vazia(lista)));
    printf("Lista cheia? %s\n", boolToString(lista_cheia(lista)));
    
    novo_elemento->valor = "galinha";
    if (adiciona_elemento(lista, *novo_elemento) == true) {
        printf("Elemento '%s' inserido com sucesso na lista.\n", novo_elemento->valor);
    } else {
        printf("Erro ao inserir elemento na lista, lista cheia.\n");
    }
    
    imprimir_lista(lista);

    return 1;
}
