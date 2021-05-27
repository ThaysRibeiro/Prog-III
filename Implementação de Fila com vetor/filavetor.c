#include <stdio.h> 
#include <stdlib.h>
#define N 100 /* número máximo de elementos */

struct fila {
  int n; /* número de elementos na fila */
  int ini; /* posição do próximo elemento a ser retirado da fila */
  float vet[N];
};
typedef struct fila Fila;

void fila_insere (Fila* f, float v);
float fila_retira (Fila* f);
int fila_vazia (Fila *f);
int fila_cheia (Fila *f);
void combina_filas(Fila*f_res,Fila*f1,Fila*f2);
void fila_imprime(Fila* f);
void imprime_fim (Fila *f);
void fila_libera (Fila* f);

Fila* fila_cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f==NULL)
	{
		printf("Memoria cheia!!!");
		exit(1);
	}
	
	f->n = 0; 
	f->ini = 0; 
	
	return f;
}

Fila* filtra(Fila* f, float x)
{
  Fila* f2 = fila_cria();
  
  while (!fila_vazia(f)) 
  { 
    float v = fila_retira(f);
    if (v > x)
      fila_insere(f2,v);   
  }
  return f2;
}

int main()				
{
	Fila *f1,*f2,*f_res,*ff;

  //Cria novas filas vazias
  f1 = fila_cria();
  f2 = fila_cria();
  f_res = fila_cria();

  //Insere elementos na fila f1
  fila_insere(f1,10.0);
  fila_insere(f1,20.0);
  fila_insere(f1,30.0);
  fila_insere(f1,40.0);

  //Retira um elemento da fila f1
  float v = fila_retira(f1);
  printf("\n%.2f ",v);
  printf("\n");
  printf("\n");

  //Imprime elementos de f1 
  fila_imprime(f1);
  printf("\n");
  printf("\n");

  //Insere elementos na fila f2 
  fila_insere(f2,5.0);
  fila_insere(f2,15.0);
  fila_insere(f2,25.0);
  fila_insere(f2,35.0);
  fila_imprime(f2);
  printf("\n");
  printf("\n"); 
   
  //Implementa a função "void combina_filas(Fila *f1, Fila*f2, Fila* f_res)" que, usando as funções anteriores
  //retira, alternadamente, das filas f1 e f2 e insere em f_res 
  combina_filas(f_res,f1,f2);
  fila_imprime(f_res);
   
  printf("\n"); 
  printf("\n"); 
  printf("\n");

  //Implementa a função "void imprime_fim (Fila *f)", que imprime o elemento de f_res que esta no fim da fila
  imprime_fim(f_res);
   
  printf("\n"); 
  printf("\n"); 
  printf("\n");

  //Implementa da função "Fila* filtra (Fila* f, float x)" que, usando as funções anteriores, Cria a nova fila ff, 
  //com elementos de f_res maiores do que x 
  ff = filtra(f_res,20.0);
  fila_imprime(ff);
    
  fila_libera(f1);
  fila_libera(f2);
  fila_libera(f_res);
  fila_libera(ff);
  
  system("PAUSE");
  return 0;			
}

void fila_insere (Fila* f, float v)
{ 
	int fim;
	
	if (f->n == N) 
	{ 
		printf("Capacidade da fila estrapolou.\n");
		exit(1); 
	}
	
	fim = (f->ini + f->n) % N;
	f->vet[fim] = v;
	f->n++;
}

float fila_retira (Fila* f)
{ 
	float v;
	
	if (fila_vazia(f)) 
	{
		printf("Fila vazia.\n");
		exit(1); 
	}
	
	v = f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia (Fila *f)
{
  return f->n == 0;
}

int fila_cheia (Fila *f)
{
  return f->n==N;
}

void combina_filas(Fila*f_res,Fila*f1,Fila*f2)
{
  float v;
  while (!fila_vazia(f1) || !fila_vazia(f2))
  {
    if(!fila_vazia(f1))
    {
      v = fila_retira(f1);
      if (!fila_cheia(f_res)) fila_insere(f_res,v);
    }

    if(!fila_vazia(f2))
    {
      v = fila_retira(f2);
      if (!fila_cheia(f_res)) fila_insere(f_res,v);
    }
  }
}

void fila_imprime(Fila* f)
{
  int i;
  int ini, fim, n;
  if (fila_vazia(f))
  {
    printf("Fila vazia\n");
   return;
  }
  
  ini = f->ini;
  n = f->n;
  
  fim = (ini + n - 1) % N;
  
  for (i=ini; i!=fim; i=(i+1)%N)
  printf("\n%.2f ", f->vet[i]);
  printf("\n%.2f ", f->vet[i]);
}

void imprime_fim (Fila* f)
{
  int i;
  int ini, fim, n;
  float fimdafila;
  if (fila_vazia(f))
  {
    printf("Fila vazia\n");
    return;
  }
  
  for(i=0;i<f->n;i++)
  {
  	fimdafila = f->vet[(f->ini+i)%N];
  }
  printf("%.2f", fimdafila);
}

void fila_libera (Fila* f)
{
  free (f);
} 
