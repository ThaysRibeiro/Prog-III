#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
    
};
typedef struct lista Lista;

Lista* lst_cria(void) {
    return NULL;
}

Lista* lst_insere(Lista* l, int val) {
    Lista* item_novo = (Lista*)malloc(sizeof(Lista));

    item_novo->info = val;
    item_novo->prox = l;
    

    return item_novo;
}

void lst_imprime(Lista* l) {
    Lista* atual = l;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
}

void lst_limpar(Lista* l) {
    if (l == NULL) return;
    Lista* proximo = l->prox;
    free(l);
    lst_limpar(proximo);
}

int main(void) {
    Lista* l;       /* declara uma lista não iniciada */
    l = lst_cria(); /* inicia lista vazia */

    /* vai inserir no início da lista */
    l = lst_insere(l, 23); /* insere na lista o elemento 23 */
    l = lst_insere(l, 45); /* insere na lista o elemento 45 */
    l = lst_insere(l, 56); /* insere na lista o elemento 56 */
    l = lst_insere(l, 78); /* insere na lista o elemento 78 */

    //vai imprimir toda a lista
    lst_imprime(l); /* imprimirá: 78 56 45 23 */
    printf("\n");
    printf("\n");

    lst_limpar(l);

    printf("\n");
    printf("\n");

    system("PAUSE");
    return 0;
}
