#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;

struct lista {
int info;
struct lista *prox;
struct lista *ant;
};
typedef struct lista Lista;

Lista *lst_insere(Lista *l,int val){
    Lista *novo_item = (Lista *)malloc(sizeof(Lista));

    novo_item->info = val;
    novo_item->prox = l;
    novo_item->ant = NULL;

    if(l!=NULL)l->ant = novo_item; //Lista encadiada dupla

    return novo_item;
}

void lst_imprime(Lista *l){
    Lista *atual = l;
    while(atual != NULL){
        printf("%d ", atual->info);
        atual = atual->prox;
    }
}

Lista *busca_rec(Lista *l,int valor){
    for(Lista  *item = l; item!=NULL;item=item->prox)
        if(item->info==valor)return item;
    
    return NULL;
}

Lista *ins_ultimo_cond(Lista *l,int valor){
    Lista *item;
    Lista *novo_valor=(Lista *)malloc(sizeof(Lista));
    Lista *ultimo=(Lista *)malloc(sizeof(Lista));
    int tem_valor=true;
    for(item=l;item!=NULL;item=item->prox){
        tem_valor=true;
        if(item->info==valor)
            break;
        else{
            tem_valor=false;
            if(item->prox==NULL)ultimo = item;
        }
    }
    if(tem_valor==0){
        novo_valor->info=valor;
        novo_valor->prox=NULL;
        ultimo->prox=novo_valor;
    }
    return l;
}
    Lista *separa(Lista *l,int valor){
        Lista *retorno=(Lista *)malloc(sizeof(Lista));
        for(Lista *item=l;item!=NULL;item=item->prox){
            if(item->info==valor){
                retorno=item->prox;
                retorno->ant=NULL;
                item->prox=NULL;
                return retorno;
            }
        }
    }

    Lista *concatena(Lista *l,Lista *l2){
        for(Lista *item=l;item!=NULL;item=item->prox){
            if(item->prox==NULL){
                item->prox=l2;
                l2->ant=item;
                break;

            }
        }
        return l;
    }

    void lst_libera(Lista *l){
        if(l==NULL)return;
        Lista *proximo=l->prox;
        free(l);
        lst_libera(proximo);
    }

int main (void){
Lista* l, *l2; /* declara uma lista não iniciada */
l = NULL; /* inicia lista vazia */

/* vai inserir no início da lista */
l = lst_insere(l, 23); /* insere na lista o elemento 23 */
l = lst_insere(l, 45); /* insere na lista o elemento 45 */
l = lst_insere(l, 56); /* insere na lista o elemento 56 */
l = lst_insere(l, 78); /* insere na lista o elemento 78 */
lst_imprime(l); /* imprimirá: 78 56 45 23 */
printf("\n");
printf("\n");

/*vai buscar um ponteiro para o nó com a informação 45*/
Lista* k = busca_rec(l,45);
if(k!=NULL)printf("info = %d\n", k->info); //imprimirá info = 45
printf("\n");
printf("\n");


/*vai inserir o elemento no final da lista, condicionalmente.
 Caso ele ainda não exista, insere, no final, um nó com a informação enviada;
 caso a informação já exista em algum nó da lista, simplesmente não insere e retorna o ponteiro inicial*/
l = ins_ultimo_cond(l,82);
printf("\n");
printf("\n");
lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

l = ins_ultimo_cond(l,45);
printf("\n");
printf("\n");
lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

//protótipo e descrição dessa função na Questão 1 do Arquivo de Exercícios
l2 = separa(l,56);
printf("\n");
printf("\n");
lst_imprime(l); //imprimirá 78 56
printf("\n");
printf("\n");
lst_imprime(l2); //imprimirá 45 23 82

//protótipo e descrição dessa função na Questão 2 do Arquivo de Exercícios
l= concatena(l,l2);
printf("\n");
printf("\n");
lst_imprime(l); //imprimirá 78 56 45 23 82

/*vai liberar a lista l */ 
lst_libera(l);
l2 = NULL;
printf("\n");


return 0;
}
