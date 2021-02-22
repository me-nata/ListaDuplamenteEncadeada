#include <stdlib.h>
#include <stdio.h>

typedef
struct elemento{
    char* nome;
    struct elemento *prox;
    struct elemento *ante;
}Elemento;

typedef
struct cabecaLista{
    struct elemento *inicio;
}C_lista;

C_lista* inicializarLista(){
    C_lista *lista = (C_lista*) malloc(sizeof(C_lista)); 

    lista->inicio = NULL;
    
    return lista;
}

void adicionarElementoFinal(C_lista *lista, char* nome){

    Elemento *new_elemento = (Elemento*) malloc(sizeof(Elemento));

    if(lista->inicio != NULL){
      Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
      
      aux = lista->inicio;
      
      while (aux->prox != NULL){
          aux = aux->prox;
      }
      
      aux->prox = new_elemento;
      
      new_elemento->prox = NULL;
      new_elemento->ante = aux; 
    }else{
      lista->inicio = new_elemento;
      
      new_elemento->prox = NULL;
      new_elemento->ante = NULL; 
    }


    new_elemento->nome = nome;
}

void mostrarLista(C_lista *lista){
    
    Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
    
    aux = lista->inicio;

    printf("_-_");
    while (aux != NULL){
        printf("<-- ");
        printf("%s", aux->nome);
        printf(" -->");
        aux = aux->prox;
    }
    printf("_-_");
}

int main(){
    C_lista *lista;
    
    lista = inicializarLista();
    adicionarElementoFinal(lista, "carnaval");
    adicionarElementoFinal(lista, "carnavalia");
    mostrarLista(lista);

    return 0;
}