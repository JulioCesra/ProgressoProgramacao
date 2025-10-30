#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int conteudo;
    struct No *proximo;
}Lista;

Lista *inicializarLista(){
    return NULL;
}

Lista *adicionar_no(Lista *lista, int conteudo){
    Lista *novo_no = (Lista *)malloc(sizeof(Lista));
    if(novo_no == NULL){
        printf("Error na alocação dinâmica!\n");
        return lista;
    }
    novo_no->conteudo = conteudo;
    novo_no->proximo = NULL;
    if(lista == NULL){
        return novo_no;
    }
    Lista *aux = lista;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo_no;
    return lista;
}

int quantidadeNOS(Lista *lista){
    if(lista == NULL){
        return 0;
    }
    return 1 + quantidadeNOS(lista->proximo);
}

void listarNOS(Lista *lista){
    if(lista == NULL){
        return;
    }
    printf("Conteúdo: %d | Endereço: %p -> ",lista->conteudo,&lista);
    listarNOS(lista->proximo);
}

Lista *buscarNo(Lista *lista, int valorBuscado){
    if(lista == NULL){
        printf("Nenhum nó na lista!\n");
        return lista;
    }
    if(lista->conteudo == valorBuscado){
        return lista;
    }
    buscarNo(lista->proximo,valorBuscado);
}

// TODO -> Fazer uma função de remoção simples. primeira ocorrência
Lista *remover(Lista *lista, int valorBuscado){
    if(lista == NULL){
        printf("Nenhum nó na lista!\n");
        return lista;
    }
    Lista *anterior = NULL;
    Lista *atual = lista;
    Lista *noRemover = NULL;
    
}

int main(){
    Lista *l1;
    l1 = inicializarLista();
    l1 = adicionar_no(l1,20);
    l1 = adicionar_no(l1,50);
    l1 = adicionar_no(l1,60);
    int quantidade = quantidadeNOS(l1);
    printf("Quantidade de nós: %d\n\n",quantidade);
    listarNOS(l1);
    Lista *noBuscado;
    noBuscado = buscarNo(l1,50);
    printf("\n\nINFORMAÇÕES DO NÓ BUSCADO:\nConteúdo: %d | Endereço: %p\n",noBuscado->conteudo,&noBuscado);
}