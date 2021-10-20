#include "../include/usuario.h"
#include "../include/ataque.h"
#include "../include/pokemon.h"
#include "../include/batalha.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ListNode* batalha(ListNode *listaPokemon,tPokemon *inimigo, tJogador* jogador,FILE *arquivo,int partida,int numbatalha){
	tPokemon *usuario;
	usuario = RetornaPokemonDaLista(listaPokemon);
  float HPatk, HPdef;
	int foge=0;
  int vitPokeball = 0; //vai aumentar td vez q ganhar uma partida, se o usuario conseguir sortear uma pokebola o cont vai zerar dnv
  int teste=0;
	PrintBatalha(inimigo);


	PrintaHP(usuario,inimigo,arquivo,teste);
	teste=1;
	
  HPatk = GetHP(usuario);
  HPdef = GetHP(inimigo);

  while(HPdef > 0){

    foge = JogadaUsuario(usuario, inimigo, jogador,listaPokemon,arquivo);
		if(foge == 1){
			//fugiu da batalha
			break;
		}
    HPatk = GetHP(usuario);
    HPdef = GetHP(inimigo);

		if(HPatk == 0){
			//fprintf(arquivo,"\n%s perde!\n\n",NomeJogador(jogador));
			printf("Seu pokemon foi derrotado.\n");
			listaPokemon = deleteFirstNode(listaPokemon);
			if(listaPokemon == NULL){
				printf("Fim de Jogo!\n");
				break;
			}
			else{
				PrintaVSnoArquivo(listaPokemon, inimigo, partida, numbatalha, arquivo);
			}
			usuario = RetornaPokemonDaLista(listaPokemon);
		}
		if(HPdef==0 || HPdef == -1){
			AumentaVitorias(jogador);
      break;
    }

		getchar();
		if(system("clear")==1){}

    inimigo = JogadaInimigo(usuario, inimigo, jogador,arquivo);
    HPatk = GetHP(usuario);
    HPdef = GetHP(inimigo);

		if(HPatk == 0){
			//fprintf(arquivo,"%s perde!\n\n",NomeJogador(jogador));
			printf("Seu pokemon foi derrotado.\n");
			listaPokemon = deleteFirstNode(listaPokemon);
			if(listaPokemon == NULL){
				printf("Fim de Jogo!\n");
				break;
			}
			usuario = RetornaPokemonDaLista(listaPokemon);
		}
		if(HPdef==0 || HPdef == -1){
			AumentaVitorias(jogador);
      break;
    }

		HPatk = GetHP(usuario);
    HPdef = GetHP(inimigo);

		getchar();
		if(system("clear")==1){}

  }
	
	if(HPdef == 0){
  	PrintaVitoria(jogador,arquivo);
    usuario = RecHPvitoria(usuario);
  	//jogador = AumentaVitorias(jogador);
    vitPokeball++;
    jogador = ChancePokebola(jogador, vitPokeball);
    int aux;
    aux = GetConseguiuPokebola(jogador);
    if(aux==1){
      printf("Você conseguiu uma Pokebola!\n");
      jogador = ZeraConseguiuPoke(jogador);
      vitPokeball = 0;
    }
	}
	else if(HPdef == -1){
		//se o pokemon for capturado o HP dele vai pra -1 so pra saber q n tem q printar q ele foi derrotado
		//jogador = AumentaVitorias(jogador);
    usuario = RecHPvitoria(usuario);
    vitPokeball++;
    jogador = ChancePokebola(jogador, vitPokeball);
    int aux;
    aux = GetConseguiuPokebola(jogador);
    if(aux==1){
      printf("Você conseguiu uma Pokebola!\n");
      jogador = ZeraConseguiuPoke(jogador);
      vitPokeball = 0;
    }
	}

	return listaPokemon;
}

int JogadaUsuario(tPokemon* usuario, tPokemon* inimigo, tJogador* jogador,ListNode* listaDePokemons,FILE *arquivo){
  int paralisado, queimado, dormindo, atkAtrasado;
  PrintaListaAtaques(usuario, jogador);
  paralisado = GetParalisa(usuario);
  dormindo = GetDorme(usuario);
  queimado = GetQueima(usuario);
  atkAtrasado = GetCavar(inimigo); //se for 1 o inimigo recebe o atk atrasado e o jogador n pode jogar na proxima, vamo ver se consigo fazer isso
	int fugir=0;

  int turnosdormindo, turnosparalisado;
  turnosdormindo = GetTurnosDormindo(usuario);
  turnosparalisado = GetTurnosParalisado(usuario);

  if(paralisado==0 && dormindo==0 && atkAtrasado==0){
    fugir = EscolheAtaque(usuario, inimigo,listaDePokemons,jogador,arquivo);
  }else if(paralisado==1){
    printf("Seu pokemon esta paralisado e nao pode fazer um movimento!\n");
    usuario = ReduzTurnosParalisado(usuario);
    turnosparalisado = GetTurnosParalisado(usuario);
    if(turnosparalisado<=0){
      usuario = Desparalisa(usuario);
    }
  }else if(dormindo==1){
    printf("Seu pokemon está dormindo e nao pode fazer um movimento!\n");
    usuario = ReduzTurnosDormindo(usuario);
    turnosdormindo = GetTurnosDormindo(usuario);
    if(turnosdormindo<=0){
      usuario = Acorda(usuario);
      usuario = recuperaHPdormir(usuario);
    }
  }else if(dormindo==2){
    printf("Seu pokemon está dormindo e nao pode fazer um movimento!\n");
    usuario = ReduzTurnosDormindo(usuario);
    turnosdormindo = GetTurnosDormindo(usuario);
    if(turnosdormindo<=0){
      usuario = Acorda(usuario);
    }
  }else if(atkAtrasado==1){
    inimigo = OutCavar(inimigo);
    inimigo = AtaqueAtrasado(usuario, inimigo, 80,1);
  }
  if(queimado==1){
    usuario = DanoQueima(usuario);
		if(paralisado==0 && dormindo==0){
    	AtaqueInimigo(usuario, inimigo,arquivo);
		}
  }

	return fugir;

}

tPokemon* JogadaInimigo(tPokemon* usuario, tPokemon* inimigo, tJogador* jogador,FILE *arquivo){
  int paralisado1, queimado1, dormindo1, atkAtrasado;
  paralisado1 = GetParalisa(inimigo);
  queimado1 = GetQueima(inimigo);
  dormindo1 = GetDorme(inimigo);
  atkAtrasado = GetCavar(usuario);

  int turnosdormindo, turnosparalisado;
  turnosdormindo = GetTurnosDormindo(inimigo);
  turnosparalisado = GetTurnosParalisado(inimigo);

  if(paralisado1 == 0 && queimado1 == 0 && atkAtrasado==0){
    AtaqueInimigo(usuario, inimigo,arquivo);
  }else if(paralisado1==1){
    printf("Inimigo está paralisado e não pode fazer um movimento!\n");
    inimigo = ReduzTurnosParalisado(inimigo);
    turnosparalisado = GetTurnosParalisado(inimigo);
    if(turnosparalisado <= 0){
      inimigo = Desparalisa(inimigo);
    }
  }else if(dormindo1==1){
    printf("Inimigo está dormindo e não pode fazer um movimento!\n");
    inimigo = ReduzTurnosDormindo(inimigo);
    turnosdormindo = GetTurnosDormindo(inimigo);
    if(turnosdormindo <= 0){
      inimigo = Acorda(inimigo);
      inimigo = recuperaHPdormir(inimigo);
    }
  }else if(dormindo1==2){
    printf("Inimigo está dormindo e não pode fazer um movimento!\n");
    inimigo = ReduzTurnosDormindo(inimigo);
    turnosdormindo = GetTurnosDormindo(inimigo);
    if(turnosdormindo <= 0){
      inimigo = Acorda(inimigo);
    }
  }else if(atkAtrasado==1){
    usuario = OutCavar(usuario);
    usuario = AtaqueAtrasado(inimigo, usuario, 80,1);
  }
  if(queimado1==1){
    inimigo = DanoQueima(inimigo);
    AtaqueInimigo(usuario, inimigo,arquivo);
  }
  return inimigo;
}
