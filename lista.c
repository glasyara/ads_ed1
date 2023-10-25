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
        printf("Erro ao inserir elemento na lista, lista cheia.\n");
        return false;
    }
    
    l->elementos[l->nelem] = e;
    l->nelem++;
    printf("Elemento '%s' iserido com sucesso na lista.\n", e);
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
    adiciona_elemento(lista, *novo_elemento);
    novo_elemento->valor = "cachorro";
    adiciona_elemento(lista, *novo_elemento);
    novo_elemento->valor = "pato";
    adiciona_elemento(lista, *novo_elemento);
    

    printf("\nLista vazia? %s\n", boolToString(lista_vazia(lista)));
    printf("Lista cheia? %s\n", boolToString(lista_cheia(lista)));
    
    novo_elemento->valor = "galinha";
    adiciona_elemento(lista, *novo_elemento);
    
    imprimir_lista(lista);

}
