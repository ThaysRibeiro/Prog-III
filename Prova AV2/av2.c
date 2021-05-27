// PRIMEIRA QUESTÃO

int insere(Lista* l, int matricula) {
    Lista* item;
    Lista* novo_valor = (Lista*)malloc(sizeof(Lista));
    Lista* ultimo = (Lista*)malloc(sizeof(Lista));
    int possui_valor = 1;
    for (item = l; item != NULL; item = item->prox) {
        possui_valor = 1;
        if (item->mat == matricula)
            return 1;
        else {
            possui_valor = 0;
            if (item->prox == NULL) ultimo = item;
        }
    }
    if (possui_valor == 0) {
        novo_valor->mat = matricula;
        novo_valor->prox = NULL;
        novo_valor->ant = ultimo;
        ultimo->prox = novo_valor;
    }

    return 0;
}

// QUESTÃO 2

void modifica_base(Pilha* p, int val) {
    if (p == NULL || p->prim == NULL) {
        printf("Pilha está VAZIA, alteração NÃO pode ser feita!!!!!\n");

        system("PAUSE");
        exit(0);
    } else if (p->prim->prox == NULL) {
        printf("Existe apenas UM elemento na pilha, alteração NÃO pode ser feita!!!!!\n");
        return;
    }

    for (No* item = p->prim; item != NULL; item = item->prox) {
        if (item->prox == NULL) {
            item->info = val;
            break;
        }
    }
}

// QUESTÃO 3

void imprime_impares(Fila* f) {
    if (f->n == 0) {
        printf("A fila está VAZIA!\n");

        system("PAUSE");
        exit(0);
    }

    int i;
    int ini, fim, n;

    ini = f->ini;
    n = f->n;

    fim = (ini + n - 1) % N;

    for (i = ini; i != fim; i = (i + 1) % N) {
        if (f->vet[i] % 2 != 0)
            printf("%d\n", f->vet[i]);
    }
}
