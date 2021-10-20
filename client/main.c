#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "../include/ataque.h"
#include "../include/pokemon.h"
#include "../include/usuario.h"
#include "../include/batalha.h"

int main(void) {
	//lembrar de tirar
	srand(time(NULL));
	//lembrar de tirar
	//srand(semente)

	char arqord[25] = "./data/ordenacao.txt";
	char arqbatalhas[25] = "./data/logDeBatalhas.txt";
	//tirar tbm e colocar o argv
	FILE *logDeBatalhas = fopen(arqbatalhas,"w");

	InicializaArrayEscolhePokemon();

  int op;
	int UltimoMew=0;
	int numbatalha=0;

	//declara as variáveis que vao ser usadas
  tJogador* jogador = NULL;
	tJogador *head = NULL;
	ListNode *lista = NULL;
	tPokemon *inimigo = NULL;
	int teste = 0,partida=0;

	while(op != 3){

		if(system("clear")==1){}
		op = MenuInicial();
		if(system("clear")==1){}

		switch(op){
			case 1: 
				//Inicia a partida
				partida++;

				//cria um novo nó de usuario
				jogador = adicionarJogador(&jogador,partida);
				numbatalha=0;

				if(teste == 0){
					//se for o primeiro usuario, ele é o inicio da lista encadeada
					teste=1;
					head = jogador;
				}
				else{
					jogador = ProxJogador(jogador);
				}
				
				if(system("clear")==1){}

				//retorna lista encadeada com os pokemons escolhidos
				lista = EscolhePokemons();
			
				while(lista != NULL){
					//cria um pokemon inimigo aleatorio
					inimigo = RetornaPokemonAleatorio(UltimoMew);
					if(InimigoEhMew(inimigo)==1){
						UltimoMew++;
					}
					numbatalha++;
					//inicia a batalha
					PrintaVSnoArquivo(lista, inimigo, partida, numbatalha, logDeBatalhas);
					lista = batalha(lista,inimigo, jogador,logDeBatalhas,partida,numbatalha);
					
					if(lista == NULL){
						fprintf(logDeBatalhas,"Fim do jogo %d %s sobreviveu %d batalhas\n\n",partida,NomeJogador(jogador),numbatalha-1);
					}
					if(lista == NULL){
						printf("%s sobreviveu %d rodadas e esta em ? lugar no placar\n",NomeJogador(jogador),numbatalha-1);
						getchar();
					}
					free(inimigo);
				}

				//reinicia o Mew para o proximo jogador
				UltimoMew = 0;
				//libera a memoria dos pokemons escolhidos
				//
				deleteList(&lista); //o vazamento de memoria pode ser isso aq hein, n testei ainda mas fica o comentario aq
				//
				
				break;
			case 2:
				//Exibe a pontuacao ordenada
				OrdenaPontuacao(head, arqord,1);
				break;
			case 3:
				//sai do programa
				break;
		}
		
	}

	OrdenaPontuacao(head,arqord,0);
	fclose(logDeBatalhas);
	LiberaJogadores(&head);

  return 0;
}