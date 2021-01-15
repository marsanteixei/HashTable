#include <stdio.h>
#include <stdlib.h>

#define M 11
typedef struct no{
	int num;
	struct no* proximo;
}No;
typedef struct{
	No* inicio;
	int tam;
}Lista;


Lista *tabela[M];


Lista* criarLista(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->inicio = NULL;
	l->tam = 0;
	return l;
}

inserirnoinicio(int n,Lista *lista){
	No* no = (No*)malloc(sizeof(No));
	no->num=n;
	no->proximo = lista->inicio;
	lista->inicio=no;
	lista->tam++;
}

void imprimirlista(No *inicio){                               
	while(inicio!=NULL){
	
		printf("numero -----> %d\n",inicio->num);
		inicio=inicio->proximo;
	}
}

void inicializar(){
	int i;
	for(i=0;i<M;i++)
	tabela[i]=criarLista();
}

int funcaoespalhamento(int numero){
	return numero%M;
	
}

void inserirnatabela(int numero){
	int x=numero;
	int indice = funcaoespalhamento(x);
	inserirnoinicio(x,tabela[indice]);
}

void imprirmirtabela(){
	int i;
	for(i=0;i<M;i++){
		printf("Posicao %d - Lista tamanho : %d\n",i,tabela[i]->tam);
		printf("------------------------------------------------\n");
		imprimirlista(tabela[i]->inicio);
	}
}

int main(){
	
	inicializar();
	FILE *arq;
	int n,a,i;
    printf("entre com a quantidade de elementos\n");
	scanf("%d",&n);
	printf("entre com o final do intervalo para gerar numeros aleatorios\n");
	scanf("%d",&a);
	int vet[n];
	for(i=0;i<n;i++)
	{
		vet[i]= (rand() %a);
	}
	char nomearq[100];
	printf("entre com um nome para o arquivo\n");
    fflush(stdin);
    gets(nomearq);
    arq=fopen(nomearq,"w+t");
    fprintf(arq,"%d \n",n);
	for(i=0;i<n;i++)
	{
		fprintf(arq,"%d ",vet[i]);
	}
	fclose(arq);
	int n1;
	arq=fopen(nomearq,"rt");
	fscanf(arq,"%d ",&n1);
	int vet1[n1];
	for(i=0;i<n1;i++)
	{
		fscanf(arq,"%d ",&vet1[i]);
	}
	fclose(arq);
	
	for(i=0;i<n1;i++){
	    int aux=vet1[i];
		inserirnatabela(aux);
	}
	
	imprirmirtabela();
	
	
}

