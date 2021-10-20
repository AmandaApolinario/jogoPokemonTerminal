#include "../include/usuario.h"
#include "../include/ataque.h"
#include "../include/pokemon.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ELETRICO 1
#define AGUA 2
#define FOGO 3
#define PSIQUICO 4
#define PLANTA 5
#define METAL 6

struct pokemon{
  char nome[20];
  float tipo;
  float HP;
  float HPinicial;
  float atk;
  float def;
  char NomeAtaque1[20];
	callback ataque1;
	char NomeAtaque2[20];
	callback ataque2;
	char NomeAtaque3[20];
	callback ataque3;
  int paralisado;
  int turnosparalisado;
  int queimado;
  int dormindo;
  int turnosdormindo;
  int protecao;
  int atkAtrasado;
};

struct listnode{
	tPokemon * pokemon;
	ListNode *next;
};

tPokemon *InicializaPokemon(char nome[128], int tipo, float HP, int atk, int def,char NomeAtaque1[20],callback atk1,char NomeAtaque2[20],callback atk2,char NomeAtaque3[20],callback atk3){
  tPokemon* pokemon = (tPokemon*)malloc(sizeof(tPokemon));

  strcpy(pokemon->nome,nome);
  pokemon->tipo = tipo;
  pokemon->HP = HP;
  pokemon->HPinicial = HP;
  pokemon->atk = atk;
  pokemon->def = def;
	strcpy(pokemon->NomeAtaque1,NomeAtaque1);
	pokemon->ataque1 = atk1;
	strcpy(pokemon->NomeAtaque2,NomeAtaque2);
	pokemon->ataque2 = atk2;
	strcpy(pokemon->NomeAtaque3,NomeAtaque3);
	pokemon->ataque3 = atk3;
  pokemon->paralisado = 0;
  pokemon->turnosparalisado = 0;
  pokemon->queimado = 0;
  pokemon->dormindo = 0;
  pokemon->turnosdormindo = 0;
  pokemon->protecao = 0;
  pokemon->atkAtrasado = 0;

  return pokemon;
}

tPokemon* MallocPokemon(tPokemon* pokemon){
  pokemon = (tPokemon*)malloc(sizeof(tPokemon));

  return pokemon;
}

tPokemon* CriaPikachu(tPokemon* pokemon){

  pokemon = InicializaPokemon("Pikachu", ELETRICO, 200, 110, 100,"Choque do Trovao",choqueDoTrovao,"Onda de Choque",ondaDeChoque,"Bater",Bater);

  return pokemon;
} 

void PrintaPokemon(tPokemon *pokemon){
	printf("%s\n",pokemon->nome);
}


tPokemon * CriaCharizard(tPokemon* pokemon){

  pokemon = InicializaPokemon("Charizard", FOGO, 260, 160, 150, "Lanca Chamas",lancaChamas,"Dormir",dormir,"Bater",Bater);

  return pokemon;
}


tPokemon* CriaBlastoise(tPokemon* pokemon){

  pokemon = InicializaPokemon("Blastoise", AGUA, 280, 180, 200, "Arma de Agua",armaDeAgua,"Proteger",proteger,"Bater",Bater);

  return pokemon;
}


tPokemon* CriaVenusaur(tPokemon* pokemon){

  pokemon = InicializaPokemon("Venusaur", PLANTA, 300, 160, 160,"Po de sono",poDeSono,"Bomba de Semente",bombaDeSemente,"Dois Gumes",doisGumes);

  return pokemon;
}


tPokemon* CriaSteelix(tPokemon* pokemon){

  pokemon = InicializaPokemon("Steelix", METAL, 280, 170, 400, "Rabo de Ferro",raboDeFerro,"Dormir",dormir,"Cavar",cavar);

  return pokemon;
}


tPokemon* CriaMew(tPokemon* pokemon){

  pokemon = InicializaPokemon("Mew", PSIQUICO, 320, 200, 200,"Metronomo",metronomo,"Bater",Bater,"Auto-Destruir",autoDestruir);
  return pokemon;

}

tPokemon* causaDano(tPokemon* atacante, tPokemon *defesa,float poder, float MT){
	float dano,modificador;
	float critico;
	//RESOLVER ESSE MT AI
	float tipo;

	tipo = RetornaTipo(atacante,defesa);

	float aleatorio = rand()/24;
	if(aleatorio <= 1/24){
		critico = 2;
	}
	else{
		critico = 1;
	}
	
	modificador = critico*MT*tipo;
	dano = (((14 * poder *atacante->atk/defesa->def)/50 )+2)*modificador;

  defesa->HP = defesa->HP - dano;

  return atacante;
}

tPokemon* DanoDG(tPokemon* atacante, tPokemon *defesa,float poder, float MT){
	float dano,modificador;
	float critico;

	float tipo;

	tipo = RetornaTipo(atacante,defesa);

	float aleatorio = rand()/24;
	if(aleatorio <= 1/24){
		critico = 2;
	}
	else{
		critico = 1;
	}
	
	modificador = critico*MT*tipo;
	dano = (((14 * poder *atacante->atk/defesa->def)/50 )+2)*modificador;

  dano = dano/3;

  defesa->HP = defesa->HP - dano;

  return atacante;
}

float RetornaTipo(tPokemon* atacante, tPokemon* defesa){
	if(atacante->tipo == 1){
		if(defesa->tipo == 2){
			return 2;
		}
		else if(defesa->tipo == 1 || defesa->tipo == 5){
			return 0.5;
		}
		else{
			return 1;
		}
	}
	else if(atacante->tipo ==2){
		if(defesa->tipo == 3){
			return 2;
		}
		else if(defesa->tipo == 2 || defesa->tipo == 5){
			return 0.5;
		}
		else{
			return 1;
		}
	}
	else if(atacante->tipo == 3){
		if(defesa->tipo == 5 || defesa->tipo ==6){
			return 2;
		}
		else if(defesa->tipo == 2 || defesa->tipo == 3){
			return 0.5;
		}
		else{
			return 1;
		}
	}
	else if(atacante->tipo == 4){
		if(defesa->tipo == 4 || defesa->tipo == 6){
			return 0.5;
		}
		else{
			return 1;
		}
	}
	else if(atacante->tipo == 5){
		if(defesa->tipo == 2){
			return 2;
		}
		else if(defesa->tipo == 1 || defesa->tipo == 4){
			return 1;
		}
		else{
			return 0.5;
		}
	}
	else if(atacante->tipo ==6){
		if(defesa->tipo == 4 || defesa->tipo == 5){
			return 1;
		}
		else{
			return 0.5;
		}
	}
}

tPokemon* recuperaHPdormir(tPokemon* pokemon){
  pokemon->HP = pokemon->HPinicial;

  return pokemon;
}

tPokemon* zeraHP(tPokemon* pokemon){
  pokemon->HP = 0;

  return pokemon;
}

void PrintBatalha(tPokemon* inimigo){
  printf("Um %s selvagem Apareceu!\n\n",inimigo->nome);

}

void PrintaHP(tPokemon* pokemon, tPokemon* inimigo,FILE *arquivo,int teste){
	float HPinimigo,HPpokemon;

	HPinimigo = (inimigo->HP*100)/inimigo->HPinicial;
	HPpokemon = (pokemon->HP*100)/pokemon->HPinicial;

	printf("%s: %.2f%% HP\n",inimigo->nome,HPinimigo);
	printf("%s: %.2f%% HP\n\n",pokemon->nome,HPpokemon);
	if(teste!=0){
		fprintf(arquivo,"\t%s: %.2f%% HP\n",inimigo->nome,HPinimigo);
		fprintf(arquivo,"\t%s: %.2f%% HP\n\n",pokemon->nome,HPpokemon);
	}

}

void FreePokemon(tPokemon* pokemon){
  free(pokemon);
}


ListNode *EscolhePokemons(){
	ListNode *head = NULL;

	int op,temp;
  char *vetorPokemons[6],*vetorPokemons2[5],*vetorPokemons3[4];
	//inicializa vetoPokemons com todos os pokemons
  vetorPokemons[0] = "Pikachu";
  vetorPokemons[1] = "Charizard";
  vetorPokemons[2] = "Venusaur";
  vetorPokemons[3] = "Blastoise";
  vetorPokemons[4] = "Steelix";
  vetorPokemons[5] = "Mew";

	int Escolhidos[3];
	int teste=0,pos=0;

	printf("Escolha 1 pokemon dos disponiveis abaixo:\n");
	for(int i=0;i<6;i++){
		printf("%d- %s\n",i+1,vetorPokemons[i]);
	}
	if(scanf("%d",&op)==1){}
	while(op>6 || op <1){
		printf("Digite uma opcao valida!\n");
		if(scanf("%d",&op)==1){}
	}
	Escolhidos[0] = op-1;

	if(system("clear")==1){}

	//inicializa vetorPokemons2 com os pokemons que sobraram
	for(int i=0;i<6;i++){
		if(i==op-1){
		}
		else{
			vetorPokemons2[pos] = vetorPokemons[i];
			pos++;
		}
	}


	printf("Escolha outro pokemon dos disponiveis abaixo:\n");
	for(int i=0;i<5;i++){
		printf("%d- %s\n",i+1,vetorPokemons2[i]);
	}	

	if(scanf("%d",&op)==1){}
	while(op>5 || op <1){
		printf("Digite uma opcao valida!\n");
		if(scanf("%d",&op)==1){}
	}

	//encontra o pokemon na lista
	for(int i=0;i<6;i++){
		if(strcmp(vetorPokemons[i],vetorPokemons2[op-1])==0){
			temp = i;
		}
	}
	Escolhidos[1] = temp;
	pos=0;

	if(system("clear")==1){}
	//inicializa a vetorPokemons3 sem os dois pokemons que foram escolhidos
	for(int i=0;i<5;i++){
		if(i==temp){
		}
		else{
			vetorPokemons3[pos] = vetorPokemons2[i];
			pos++;
		}
	}
	
	printf("Escolha mais 1 pokemon dos disponiveis abaixo:\n");
	for(int i=0;i<4;i++){
		printf("%d- %s\n",i+1,vetorPokemons3[i]);
	}

	if(scanf("%d",&op)==1){}
	while(op>4 || op <1){
		printf("Digite uma opcao valida!\n");
		if(scanf("%d",&op)==1){}
	}
	int temp2;
	//encontra no vetorPokemons a posicao correspondente a escolhida
	for(int i=0;i<5;i++){
		if(strcmp(vetorPokemons2[i],vetorPokemons3[op-1])==0){
			temp = i;
		}
	}
	for(int i=0;i<6;i++){
		if(strcmp(vetorPokemons[i],vetorPokemons2[temp])==0){
			temp2 = i;
		}
	}
	
	Escolhidos[2] = temp2;
	
	pos=0;

	if(system("clear")==1){}

	//printf("%s %s %s\n",vetorPokemons[Escolhidos[0]],vetorPokemons[Escolhidos[1]],vetorPokemons[Escolhidos[2]]);

	//cria a lista encadeada
	head = addLast(&head, Escolhidos[0]);
	head = addLast(&head, Escolhidos[1]);
	head = addLast(&head, Escolhidos[2]);

	return head;
}

typedef tPokemon*(*fptrEscolhePokemon)();
fptrEscolhePokemon fptrEscolhePokemonArr[128] = {NULL};

void InicializaArrayEscolhePokemon(){
	fptrEscolhePokemonArr[0] = CriaPikachu;
	fptrEscolhePokemonArr[1] = CriaCharizard;
	fptrEscolhePokemonArr[2] = CriaVenusaur;
	fptrEscolhePokemonArr[3] = CriaBlastoise;
	fptrEscolhePokemonArr[4] = CriaSteelix;
	fptrEscolhePokemonArr[5] = CriaMew;
}

tPokemon *AvaliaTabela(int a){
	fptrEscolhePokemon poke;
	poke = fptrEscolhePokemonArr[a];

	return poke();
}

ListNode* addLast(ListNode **lista,int opcao)
{
    //create a new node
    ListNode *novalista;

		novalista = (ListNode*)malloc(sizeof(ListNode));

		novalista->pokemon = AvaliaTabela(opcao);

    //if head is NULL, it is an empty list
    if(*lista == NULL)
         *lista = novalista;
    //Otherwise, find the last node and add the newNode
    else
    {
        ListNode *lastNode = *lista;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = novalista;
    }

		return *lista;

}

void printList(ListNode *head)
{
    ListNode *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
      printf("%s\n", temp->pokemon->nome);
      temp = temp->next;
    }
    printf("fim\n");
}

ListNode * deleteFirstNode(ListNode *head)
{
    ListNode *toDelete;

    if(head == NULL)
    {
        printf("A lista ja está vazia.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        // Clears the memory occupied by first node
				free(toDelete->pokemon);
        free(toDelete);
    }
		return head;
}

void deleteList(ListNode** head_ref)
{
 
    // deref head_ref to get the real head
    ListNode* current = *head_ref;
    ListNode* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
				free(current->pokemon);
        free(current);
        current = next;
    }
 
    //deref head_ref to affect the real head back
     //   in the caller. 
    *head_ref = NULL;
}

tPokemon * RetornaPokemonDaLista(ListNode *lista){
	return lista->pokemon;
}

tPokemon * RetornaPokemonAleatorio(int UltimoMew){
	tPokemon* inimigo;
	int op;

	float mew = UltimoMew/128.0;
	float aleatorio = rand()/128;
	if(aleatorio <= mew){
		op = 5;
	}
	else{
		op = rand()%4;
	}

	inimigo = AvaliaTabela(op);
}

void PrintaListaAtaques(tPokemon* pokemon, tJogador* jogador){
  int qtdPokebola = GetPokebola(jogador);

	if(pokemon->dormindo <=0 && pokemon->paralisado <=0){
  	printf("Escolha um movimento:\n1- %s\n2- %s\n3- %s\n4- Pokebola (%d disponiveis)\n5- Fugir\n",pokemon->NomeAtaque1, pokemon->NomeAtaque2, pokemon->NomeAtaque3,qtdPokebola); 
	}
}

int EscolheAtaque(tPokemon* pokemon, tPokemon* inimigo, ListNode* listaDePokemons,tJogador* jogador,FILE *arquivo){
	//retorna 1 se jogador fugir da batalha, 0 se n
  int op,verificador,fugir=0;
  if(scanf("%d",&op)==1){}
  if(system("clear")==1){}
  if(op==1){
		printf("%s usa %s\n\n",pokemon->nome,pokemon->NomeAtaque1);
		fprintf(arquivo,"\t%s usa %s\n",pokemon->nome,pokemon->NomeAtaque1);
    pokemon->ataque1(pokemon, inimigo);
    if(inimigo->HP<0){
      inimigo->HP = 0;
    }
    PrintaHP(pokemon, inimigo,arquivo,1);
		return 0;
  }else if(op==2){
		printf("%s usa %s\n\n",pokemon->nome,pokemon->NomeAtaque2);
		fprintf(arquivo,"\t%s usa %s\n",pokemon->nome,pokemon->NomeAtaque2);
    pokemon->ataque2(pokemon, inimigo);
    if(inimigo->HP<0){
      inimigo->HP = 0;
    }
    PrintaHP(pokemon, inimigo,arquivo,1);
		return 0;
  }else if(op==3){
		printf("%s usa %s\n\n",pokemon->nome,pokemon->NomeAtaque3);
		fprintf(arquivo,"\t%s usa %s\n",pokemon->nome,pokemon->NomeAtaque3);
    pokemon->ataque3(pokemon, inimigo);
    if(inimigo->HP<0){
      inimigo->HP = 0;
    }
    PrintaHP(pokemon, inimigo,arquivo,1);
		return 0;
  }else if(op==4){
    verificador = CapturaPokemon(listaDePokemons, jogador, inimigo,arquivo);
		if(verificador == 0){
			PrintaListaAtaques(pokemon, jogador);
			EscolheAtaque(pokemon, inimigo,listaDePokemons,jogador,arquivo);
		}
		return 0;

  }else if(op==5){
		fugir = FogeDaBatalha();
		fprintf(arquivo,"\tTentativa de Fuga\n");
		if(fugir == 1){
			fprintf(arquivo,"\tSucesso\n\n");
		}
		else{
			fprintf(arquivo,"\tFracasso\n\n");
		}
		return fugir;

  }
	else{
    printf("Escolha uma opcao valida!\n");
		EscolheAtaque(pokemon, inimigo,listaDePokemons,jogador,arquivo);
  }
}

int FogeDaBatalha(){
	float aleatorio = (float)rand()/(float)(RAND_MAX);

	//aleatorio = 0;

	if(aleatorio <= 0.16){
		printf("Voce fugiu da batalha!\n");
		return 1;
	}
	else{
		printf("Voce nao fugiu da batalha!\n");
		return 0;
	}
}

int CapturaPokemon(ListNode *lista,tJogador* jogador,tPokemon *inimigo,FILE *arquivo){
	char *vetorPokemons[20];
	vetorPokemons[0] = "Pikachu";
  vetorPokemons[1] = "Charizard";
  vetorPokemons[2] = "Venusaur";
  vetorPokemons[3] = "Blastoise";
  vetorPokemons[4] = "Steelix";
  vetorPokemons[5] = "Mew";

	int qtdPokebolas = GetPokebola(jogador);
	//float prob = (float)rand()/(float)(RAND_MAX);
	float prob;
	if(qtdPokebolas > 0){
		//eu nunca sei se as estatisticas tao certas serio, da uma olhada pra ver se os numeros tao certinhos tipo o 0.2
		prob = (inimigo->HPinicial/inimigo->HP)/20.0;

		//isso ai é se quiser testar a captura pra ver se ta funcionando
		//prob = 0;
		fprintf(arquivo,"\tTentativa de Captura\n");
		if(prob <=0.2){
			fprintf(arquivo,"\tSucesso\n\n");
			printf("%s foi capturado!\n",inimigo->nome);
			for(int i=0;i<6;i++){
				if(strcmp(inimigo->nome,vetorPokemons[i])==0){
					addLast(&lista, i);
				}
				inimigo->HP=-1;
			}
			DiminuitPokebola(jogador, 1);
		}
		else{
			fprintf(arquivo,"\tFracasso\n\n");
			printf("%s nao foi capturado!\n",inimigo->nome);
			DiminuitPokebola(jogador, 0);
		}
		return 1;
	}
	else{
		return 0;
	}
}

float GetHP(tPokemon* pokemon){
  return pokemon->HP;
}

void AtaqueInimigo(tPokemon* usuario, tPokemon* inimigo,FILE *arquivo){
  int op;
	
  op = rand()%3;
  if(op==0){
    printf("\n%s usa %s\n\n",inimigo->nome,inimigo->NomeAtaque1);
		fprintf(arquivo,"\t%s usa %s\n",inimigo->nome,inimigo->NomeAtaque1);
		inimigo->ataque1(inimigo, usuario);
    
    if(usuario->HP<0){
      usuario->HP = 0;
    }
    PrintaHP(usuario, inimigo,arquivo,1);
  }else if(op==1){
    printf("\n%s usa %s\n\n",inimigo->nome,inimigo->NomeAtaque2);
		fprintf(arquivo,"\t%s usa %s\n",inimigo->nome,inimigo->NomeAtaque2);
		inimigo->ataque2(inimigo,usuario);
    
    if(usuario->HP<0){
      usuario->HP = 0;
    }
    PrintaHP(usuario, inimigo,arquivo,1);
  }else if(op==2){
    printf("\n%s usa %s\n\n",inimigo->nome,inimigo->NomeAtaque3); 
		fprintf(arquivo,"\t%s usa %s\n",inimigo->nome,inimigo->NomeAtaque3); 
		inimigo->ataque3(inimigo, usuario);
    
    if(usuario->HP<0){
      usuario->HP = 0;
    }
    PrintaHP(usuario, inimigo,arquivo,1);
  }
}

tPokemon* Paralisa(tPokemon* pokemon){
  pokemon->paralisado = 1;
  pokemon->turnosparalisado = 1;
  return pokemon;
}

tPokemon* ReduzTurnosParalisado(tPokemon* pokemon){
  pokemon->turnosparalisado = 0;
  return pokemon;
}

int GetTurnosParalisado(tPokemon* pokemon){
  return pokemon->turnosparalisado;
}

tPokemon* Desparalisa(tPokemon* pokemon){
  pokemon->paralisado = 0;
  return pokemon;
}

int GetParalisa(tPokemon* pokemon){
  return pokemon->paralisado;
}

tPokemon* Dorme(tPokemon* pokemon){
  pokemon->dormindo = 1;
  pokemon->turnosdormindo = 2;
  return pokemon;
}

tPokemon* PoDeSono(tPokemon* pokemon){
  pokemon->dormindo = 2;
  pokemon->turnosdormindo = rand()%3 + 1;
  return pokemon;
}

tPokemon* ReduzTurnosDormindo(tPokemon* pokemon){
  pokemon->turnosdormindo = pokemon->turnosdormindo - 1;
  return pokemon;
}

int GetTurnosDormindo(tPokemon *pokemon){
  return pokemon->turnosdormindo;
}

tPokemon* Acorda(tPokemon* pokemon){
  pokemon->dormindo = 0;
  return pokemon;
}

int GetDorme(tPokemon* pokemon){
  return pokemon->dormindo;
}

tPokemon* Queima(tPokemon* pokemon){
  pokemon->queimado = 1;
  return pokemon;
}

int GetQueima(tPokemon* pokemon){
  return pokemon->queimado;
}

tPokemon* DanoQueima(tPokemon* pokemon){
  pokemon->HP = pokemon->HP - (pokemon->HPinicial/16);
  return pokemon;
}

int InimigoEhMew(tPokemon* pokemon){
	//retorna 1 se sim e 0 se n
	if(strcmp(pokemon->nome, "Mew")==0){
		return 1;
	}
}

tPokemon* Protege(tPokemon* pokemon){
  pokemon->protecao = 1;
  return pokemon;
}

tPokemon* Desprotege(tPokemon* pokemon){
  pokemon->protecao = 0;
  return pokemon;
}

int GetProtege(tPokemon* pokemon){
  return pokemon->protecao;
}

tPokemon* Cavar(tPokemon* pokemon){
  pokemon->atkAtrasado = 1;
  return pokemon;
}

tPokemon* OutCavar(tPokemon* pokemon){
  pokemon->atkAtrasado = 0;
  return pokemon;
}

int GetCavar(tPokemon* pokemon){
  return pokemon->atkAtrasado;
}

tPokemon* RecHPvitoria(tPokemon* pokemon){
  if(pokemon->HP < (pokemon->HPinicial - 10)){
    pokemon->HP = pokemon->HP + 10;
  }else{
    pokemon->HP = pokemon->HPinicial;
  }

  return pokemon;
}

void PrintaVSnoArquivo(ListNode *lista,tPokemon *pokemon,int partida,int batalha,FILE *arquivo){
	fprintf(arquivo,"%d.%d - %s vs %s\n",partida,batalha,lista->pokemon->nome,pokemon->nome);
}