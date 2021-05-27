#include<stdio.h>
#include<stdlib.h>

struct lista {
  float info;
  struct lista* prox;
};
typedef struct lista Lista;

/* estrutura da pilha */
struct pilha {
  Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
void pilha_libera(Pilha* p);
void imprime (Pilha* p);
void pilha_imprime (Pilha *p);
int pilha_vazia(Pilha* p);

Pilha* pilha_cria(void)
{
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL)
	{
		exit(1);
	}
	p->prim = NULL;
	return p;
}

Pilha* troca_topo (Pilha* p)
{
  int v1 = pilha_pop(p);
  int v2 = pilha_pop(p);
  pilha_push(p,v1);
  pilha_push(p,v2);
  return p;
}

int main()
{
  /* Implementação de pilha com lista encadeada */
	Pilha *p;
	p = pilha_cria();
	pilha_push(p,10);
	pilha_push(p,15);
	pilha_push(p,20);
	pilha_push(p,25);
	float v = pilha_pop(p);
	printf("%.2f\n", v);
	printf("\n");
       
  /* vai imprimir do topo para a base, percorrendo a lista encadeada */
	pilha_imprime(p);
	printf("\n");
        
  /* vai imprimir da base para o topo usando as funções já definidas e uma pilha auxiliar */
	imprime(p);
  printf("\n");

  /*vai executar a função troca_topo, que troca o valor do topo com aquele abaixo, usando somente as funções push e pop*/
  // protótipo: void troca_topo(Pilha*p) - emite mensagem de erro para
  // pilha vazia ou com menos de dois elementos.
  troca_topo(p);
  pilha_imprime(p);

	pilha_libera(p);
  system("PAUSE");
	return 0;
}

int pilha_vazia(Pilha* p)
{
  if(p->prim == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void pilha_push(Pilha* p, float v)
{
	Lista* n = (Lista*)malloc(sizeof(Lista));
	if(n == NULL)
	{
		exit(1);
	}
	n->info = v; 
	n->prox = p->prim;
	p->prim = n;
}

float pilha_pop(Pilha* p)
{
	Lista* t;
	float v;
	if(pilha_vazia(p))
	{
		printf("Pilha vazia.\n");
		exit(1);
	}
	
	t = p->prim;
	v = t->info;
	p->prim = t->prox;
	free(t);
	return v;
}

void pilha_libera(Pilha* p)
{
	Lista* q = p->prim;
	
	while(q!=NULL)
	{
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

//Usando recursão
void imprime(Pilha* p)
{
	if(!pilha_vazia(p))
	{
		float v = pilha_pop(p);
		imprime(p);
		printf("%.2f\n",v);
		pilha_push(p,v);
	}
}

void pilha_imprime (Pilha *p)
{
  Lista *q;
  for (q=p->prim; q!=NULL; q=q->prox)
  {
    printf("%.2f\n", q->info);
  }
}
