#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* lst_insere(Lista2* l, int val) {
    Lista2* novo_item = (Lista2*)malloc(sizeof(Lista2));

    novo_item->info = val;
    novo_item->prox = l;
    novo_item->ant = NULL;

    if (l != NULL) l->ant = novo_item;  // Lista encadiada dupla

    return novo_item;
}

void lst_imprime(Lista2* l) {
    Lista2* atual = l;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
}

Lista2* busca(Lista2* l, int valor) {
    for (Lista2* item = l; item != NULL; item = item->prox)
        if (item->info == valor) return item;

    return NULL;
}

Lista2* ins_ultimo_cond(Lista2* l, int valor) {
    Lista2* item;
    Lista2* novo_valor = (Lista2*)malloc(sizeof(Lista2));
    Lista2* ultimo = (Lista2*)malloc(sizeof(Lista2));
    int tem_valor = true;
    for (item = l; item != NULL; item = item->prox) {
        tem_valor = true;
        if (item->info == valor)
            break;
        else {
            tem_valor = false;
            if (item->prox == NULL) ultimo = item;
        }
    }
    if (tem_valor == false) {
        novo_valor->info = valor;
        novo_valor->prox = NULL;
        novo_valor->ant = ultimo;
        ultimo->prox = novo_valor;
    }
    return l;
}

Lista2* separa(Lista2* l, int valor) {
    Lista2* retorno = (Lista2*)malloc(sizeof(Lista2));
    for (Lista2* item = l; item != NULL; item = item->prox) {
        if (item->info == valor) {
            retorno = item->prox;
            retorno->ant = NULL;
            item->prox = NULL;
            return retorno;
        }
    }
}

Lista2* concatena(Lista2* l, Lista2* l2) {
    for (Lista2* item = l; item != NULL; item = item->prox) {
        if (item->prox == NULL) {
            item->prox = l2;
            l2->ant = item;
            break;
        }
    }
    return l;
}

Lista2* lst_libera(Lista2* l) {
    if (l == NULL) return NULL;
    Lista2* proximo = l->prox;
    free(l);
    lst_libera(proximo);
}

int main(void) {
    Lista2 *l, *l2; /* declara uma lista não iniciada */
    l = NULL;       /* inicia lista vazia */

    /* vai inserir no início da lista */
    l = lst_insere(l, 23); /* insere na lista o elemento 23 */
    l = lst_insere(l, 45); /* insere na lista o elemento 45 */
    l = lst_insere(l, 56); /* insere na lista o elemento 56 */
    l = lst_insere(l, 78); /* insere na lista o elemento 78 */
    lst_imprime(l);        /* imprimirá: 78 56 45 23 */
    printf("\n");
    printf("\n");

    /*vai buscar um ponteiro para o nó com a informação 45*/
    Lista2* k = busca(l, 45);
    if (k != NULL) printf("info = %d\n", k->info);  //imprimirá info = 45
    printf("\n");
    printf("\n");

    /*vai inserir o elemento no final da lista, condicionalmente.
    Caso ele ainda não exista, insere, no final, um nó com a informação enviada;
    caso a informação já exista em algum nó da lista, simplesmente não insere e retorna o ponteiro inicial*/
    l = ins_ultimo_cond(l, 82);
    printf("\n");
    printf("\n");
    lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

    l = ins_ultimo_cond(l, 45);
    printf("\n");
    printf("\n");
    lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

    //protótipo e descrição dessa função na Questão 1 do Arquivo de Exercícios, adaptando, agora, para lista dupla
    l2 = separa(l, 56);
    printf("\n");
    printf("\n");
    lst_imprime(l);  //imprimirá 78 56
    printf("\n");
    printf("\n");
    lst_imprime(l2);  //imprimirá 45 23 82

    //protótipo e descrição dessa função na Questão 2 do Arquivo de Exercícios, adaptando, agora, para lista dupla
    l = concatena(l, l2);
    printf("\n");
    printf("\n");
    lst_imprime(l);  //imprimirá 78 56 45 23 82

    /*vai liberar a lista l */
    l = lst_libera(l);
    l2 = NULL;

    system("PAUSE");
    return 0;
}
