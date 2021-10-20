#include "../include/usuario.h"
#include "../include/pokemon.h"
#include "../include/ataque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogador{
  char nome[128];
	int id;
  int qtdPokemon;
  int qtdPokebolas;
  int vitorias;
  int ConseguiuPoke;
  tJogador *next;
};

tJogador *MallocJogador(tJogador *jogador){
  jogador = (tJogador*)malloc(sizeof(tJogador));

  return jogador;
}

tJogador * ProxJogador(tJogador *jogador){
	jogador = jogador->next;

	return jogador;
}

void PrintaJogadorAtual(tJogador *jogador){
	printf("atual: %s\n",jogador->nome);
}

int VerificaUser(char user[128]){
  int tam = strlen(user);
  int i=0;
  int valido = 1; //1 para sim 0 para nao
  for(i=0;i<tam;i++){
    if((user[i]>='a' && user[i]<='z') || (user[i]>='A' && user[i]<='Z') || user[i]=='_'){
    }else{
      valido = 0;
    }
  }
  if(valido == 1){
    return 1;
  }else{
    return 0;
  }
}

int MenuInicial(){
  int op = 0;
  printf("1- Jogar\n2- Melhores pontuacoes\n3- Sair\n");
  if(scanf("%d",&op)==1){}
  switch(op){
    case 1:
      return 1;
      break;
    case 2:
      return 2; 
      break;
    case 3:
      return 3;
      break;
    default:
      printf("Entrada invalida.\n");
      MenuInicial();
      break;      
  }
  return 3;
}

tJogador *Login(tJogador *jogador,int partida){
  char user[128];
  int valido=0;
  printf("Qual o seu nome?\n");
  if(scanf("%s",user)==1){}
  jogador = MallocJogador(jogador);

  valido = VerificaUser(user);
  if(valido==1){
    strcpy(jogador->nome,user);
    jogador->vitorias = 0;
    jogador->qtdPokebolas = 3;
    jogador->qtdPokemon = 3;
    jogador->ConseguiuPoke = 0;
		jogador->id = partida; 
    return jogador; //login feito com sucesso
  }else{
    printf("Digite um nome válido!\n\n");
    Login(jogador,partida);
  }
}

tJogador * adicionarJogador(tJogador **head,int partida)
{
    //create a new node
    tJogador *novoJogador;
		novoJogador = Login(novoJogador,partida);
    //if head is NULL, it is an empty list
    if(*head == NULL)
      *head = novoJogador;
    //Otherwise, find the last node and add the newNode
    else
    {
        tJogador *UltimoNo = *head;

        //last node's next address will be NULL.
        while(UltimoNo->next != NULL)
        {
            UltimoNo = UltimoNo->next;
        }

        //add the newNode at the end of the linked list
        UltimoNo->next = novoJogador;
    }

		return *head;

}

void LiberaJogadores(tJogador** head)
{
   /* deref head_ref to get the real head */
   tJogador* current = *head;
   tJogador* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *head = NULL;
}

void PrintaJogadores(tJogador *head)
{
    tJogador *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
      printf("%s %d\n",temp->nome,temp->vitorias);

      temp = temp->next;
    }
    printf("fim\n");
}

int GetVitorias(tJogador* jogador){
  return jogador->vitorias;
}

tJogador* AumentaVitorias(tJogador* jogador){
  jogador->vitorias = jogador->vitorias + 1;

  return jogador;
}

int GetPokebola(tJogador* jogador){
  return jogador->qtdPokebolas;
}

void DiminuitPokebola(tJogador* jogador,int pegouPokemon){
	jogador->qtdPokebolas--;
	if(pegouPokemon == 1){
		jogador->qtdPokemon++;
	}
}

void OrdenaPontuacao(tJogador *jogadores,char *end,int printarNoTerminal){
	FILE *arquivo = fopen(end,"w");
	tJogador *temp;
	temp = jogadores;

	int qtdContas=0;
	while(temp != NULL){
		qtdContas++;
		temp = ProxJogador(temp);
	}

	temp = jogadores;

	int vitorias[qtdContas];
	char *nomes[20];
	for(int i=0;i<qtdContas;i++){
		vitorias[i] = temp->vitorias;
		nomes[i] = temp->nome;
		temp = ProxJogador(temp);
	}
	int maior = 0,auxvit;
	char aux[20];

	for(int i=0;i<qtdContas;i++){
    for(int j=0;j<qtdContas;j++){
      if(strcmp(nomes[i],nomes[j])<0){
        strcpy(aux,nomes[i]);
        strcpy(nomes[i],nomes[j]);
        strcpy(nomes[j],aux);

				auxvit = vitorias[i];
				vitorias[i] = vitorias[j];
				vitorias[j] = auxvit;
      }
    }
  }

	for(int i=0;i<qtdContas;i++){
    for(int j=0;j<qtdContas-1-i;j++){
      if(vitorias[j]<vitorias[j+1]){
        auxvit=vitorias[j];
        vitorias[j]=vitorias[j+1];
        vitorias[j+1]=auxvit;

				strcpy(aux,nomes[j]);
				strcpy(nomes[j],nomes[j+1]);
				strcpy(nomes[j+1],aux);
      }
    }
  }

	for(int i=0;i<qtdContas;i++){
		if(printarNoTerminal == 1){
			printf("%d- %s:%d\n",i+1,nomes[i],vitorias[i]);
		}
		fprintf(arquivo,"%s %d\n",nomes[i],vitorias[i]);
	}

	if(printarNoTerminal == 1){
		getchar();
		getchar();
	}
	fclose(arquivo);
}

tJogador* ChancePokebola(tJogador* jogador, int C){
  float aleatorio = (float)rand()/(float)(RAND_MAX);
  if(aleatorio <= (C/12)){
    jogador->qtdPokebolas = jogador->qtdPokebolas + 1;
    jogador->ConseguiuPoke = 1;
  }

  return jogador;
}

int GetConseguiuPokebola(tJogador* jogador){
  return jogador->ConseguiuPoke;
}

tJogador* ZeraConseguiuPoke(tJogador* jogador){
  jogador->ConseguiuPoke = 0;

  return jogador;
}

void PrintaVitoria(tJogador* jogador,FILE *arquivo){
  printf("%s venceu!\n\n",jogador->nome);
	fprintf(arquivo,"\t%s vence!\n\n",NomeJogador(jogador));
}

char * NomeJogador(tJogador *jogador){
	return jogador->nome;
}