#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int conteudo;
    struct No *proximo;
}ListaEncadeada;

ListaEncadeada *inicializarLista(){
    return NULL;
}

ListaEncadeada *adicionar_no(ListaEncadeada *lista, int conteudo){
    ListaEncadeada *novo_no = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if(novo_no==NULL){
        printf("Error na alocação dinâmica!\n");
        return lista;
    }
    novo_no->conteudo = conteudo;
    novo_no->proximo = NULL;
    if(lista==NULL){
        return novo_no;
    }
    ListaEncadeada *aux = lista;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo_no;
    return lista;
}

int contarNos(ListaEncadeada *lista){
    if(lista == NULL){
        return 0;
    }
    return 1 + contarNos(lista->proximo);
}

void listarNos(ListaEncadeada *lista){
    if(lista==NULL){
        return;
    }
    printf("Conteudo: %d | Endereço: %p -> ",lista->conteudo,&lista);
    listarNos(lista->proximo);
}

int compararIgualdade(ListaEncadeada *lista1, ListaEncadeada *lista2){
    if(contarNos(lista1) == contarNos(lista2)){
        ListaEncadeada *aux1 = lista1;
        ListaEncadeada *aux2 = lista2;
        while(aux1!=NULL && aux2!=NULL){
            if(aux1->conteudo != aux2->conteudo){
                return 0;
            }
            aux1 = aux1->proximo;
            aux2 = aux2->proximo;
        }
    }else{
        return 0;
    }
    return 1;
}

int main(){
    ListaEncadeada *lista;
    lista = inicializarLista();
    lista = adicionar_no(lista,20);
    lista = adicionar_no(lista,10);
    int contagem = 0;
    contagem = contarNos(lista);
    printf("Quantidade de nós: %d\n",contagem);
    listarNos(lista);
    int igual = 0;
    ListaEncadeada *lista2;
    lista2 = inicializarLista();
    lista2 = adicionar_no(lista2,20);
    lista2 = adicionar_no(lista2,10);
    igual = compararIgualdade(lista,lista2);
    printf("\n(1) - IGUAL\n(0) - DIFERENTES\nResultado: %d\n",igual);
    return 0;
}