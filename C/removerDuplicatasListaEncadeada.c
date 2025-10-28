#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No *proximo;
}ListaEncadeada;

ListaEncadeada *inicializarLista(){
    return NULL;
}

ListaEncadeada *adicionarNo(ListaEncadeada *lista, int conteudo){
    ListaEncadeada *novo_no = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (novo_no == NULL){
        printf("Error na alocação dinâmica!\n");
        return lista;
    }
    novo_no->conteudo = conteudo;
    novo_no->proximo = NULL;
    if(lista == NULL){
        return novo_no;
    }else{
        ListaEncadeada *aux = lista;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo_no;
    }
    return lista;
}
void listarListar(ListaEncadeada *lista){
    if(lista == NULL){
        return;
    }
    printf("Conteúdo: %d | Endereço: (%p) -> ",lista->conteudo,&lista);
    return listarListar(lista->proximo);
}
ListaEncadeada *removerDuplicatas(ListaEncadeada *lista){
    if(lista == NULL){
        printf("Nenhum nó anexado a lista encadeada!\n");
        return lista;
    }
    ListaEncadeada *atual = lista;
    while(atual != NULL){
        ListaEncadeada *buscador = atual;
        while(buscador->proximo != NULL){
            if(atual->conteudo == buscador->proximo->conteudo){
                ListaEncadeada *no_remover = buscador->proximo;
                buscador->proximo = no_remover->proximo;
                free(no_remover);
            }else{
                buscador = buscador->proximo;
            }
        }
        atual = atual->proximo;
    }
    return lista;
}



int main(){
    ListaEncadeada *lista;
    lista = inicializarLista(lista);
    lista = adicionarNo(
        lista, 20
    );
    lista = adicionarNo(
        lista, 6
    );
    lista = adicionarNo(
        lista, 20
    );
    lista = adicionarNo(
        lista, 10
    );
    lista = adicionarNo(
        lista, 87
    );
    listarListar(lista);
    printf("\nApós a remoção!\n");
    lista = removerDuplicatas(lista);
    listarListar(lista);
    return 0;
}