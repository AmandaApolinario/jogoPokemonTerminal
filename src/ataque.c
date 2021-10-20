#include "../include/usuario.h"
#include "../include/pokemon.h"
#include "../include/ataque.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void choqueDoTrovao(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa,40,MT);
    float aleatorio = (float)rand()/(float)RAND_MAX;
    if(aleatorio< 0.1){
      defesa = Paralisa(defesa);
    }
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
}

void ondaDeChoque(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5; //eh mesmo tipo
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = Paralisa(defesa);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  } 
}

void Bater(tPokemon* atacante, tPokemon* defesa){
  float MT = 1; // n eh msm tipo
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa, 40, MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  } 
}

void lancaChamas(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa, 90, MT);
    float aleatorio = (float)rand()/(float)RAND_MAX;
    if(aleatorio< 0.1){
      printf("Pokemon Queimado!\n");
      defesa = Queima(defesa);
    } 
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
}

void dormir(tPokemon* atacante, tPokemon* defesa){
  atacante = Dorme(atacante);
}

void armaDeAgua(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa, 40,MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  } 
}

void proteger(tPokemon* atacante, tPokemon* defesa){
  atacante = Protege(atacante);
}

void poDeSono(tPokemon* atacante, tPokemon* defesa){
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = PoDeSono(defesa);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
}

void bombaDeSemente(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa, 80,MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
}

void doisGumes(tPokemon* atacante, tPokemon* defesa){
  float MT = 1;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa =	causaDano(atacante, defesa, 120, MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
 	atacante = DanoDG(atacante, defesa, 120, MT);
}

void raboDeFerro(tPokemon* atacante, tPokemon* defesa){
  float MT = 1.5;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    atacante = causaDano(atacante, defesa, 100,MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
}

void cavar(tPokemon* usuario, tPokemon* inimigo){
  float MT = 1;
  usuario = Protege(usuario);
  inimigo = Cavar(inimigo);
}

tPokemon* AtaqueAtrasado(tPokemon* atacante, tPokemon* defesa, float poder,float MT){
  defesa = causaDano(atacante,defesa,poder,MT);

	return defesa;
}

fptrAtaqueMetronomo AtaqueAleatorioMetronomoArr[14];

void InicializaArrAtaqueMetronomo(){
	AtaqueAleatorioMetronomoArr[0] = choqueDoTrovao;
	AtaqueAleatorioMetronomoArr[1] = ondaDeChoque;
	AtaqueAleatorioMetronomoArr[2] = Bater;
	AtaqueAleatorioMetronomoArr[3] =lancaChamas;
	AtaqueAleatorioMetronomoArr[4] = dormir;
	AtaqueAleatorioMetronomoArr[5] = armaDeAgua;
	AtaqueAleatorioMetronomoArr[5] = proteger;
	AtaqueAleatorioMetronomoArr[7] = poDeSono;
	AtaqueAleatorioMetronomoArr[8] = bombaDeSemente;
	AtaqueAleatorioMetronomoArr[9] = doisGumes;
	AtaqueAleatorioMetronomoArr[10] = raboDeFerro;
	AtaqueAleatorioMetronomoArr[11] = cavar;
	AtaqueAleatorioMetronomoArr[12] = autoDestruir;
}

void metronomo(tPokemon* usuario, tPokemon* inimigo){
  InicializaArrAtaqueMetronomo();

	fptrAtaqueMetronomo ataque;
	int opcao;
	opcao = rand()%12;
	
	ataque = AtaqueAleatorioMetronomoArr[opcao];
	PrintaAtaqueMetronomo(opcao);
	
	ataque(usuario,inimigo);
}

void PrintaAtaqueMetronomo(int op){
	char *lista[20];
	lista[0] = "Choque do Trovão";
	lista[1] = "Onda de Choque";
	lista[2] = "Bater";
	lista[3] = "Lança Chamas";
	lista[4] ="Dormir";
	lista[5] =	"Arma de Agua";
	lista[6] = "Proteger";
	lista[7] = "Po de Sono";
	lista[8] = "Bomba de semente";
	lista[9] = "Dois Gumes";
	lista[10] =	"Rabo de Ferro";
	lista[11] = "Cavar";
	lista[12] = "Auto-Destruir";

	printf("Mew usa %s\n",lista[op]);

}

void autoDestruir(tPokemon* atacante, tPokemon* defesa){
  float MT = 1;
  int protegido = GetProtege(defesa);
  if(protegido==0){
    defesa = causaDano(atacante, defesa, 200,MT);
  }else{
    printf("Pokemon protegido! Ataque falhou.\n");
    defesa = Desprotege(defesa);
  }
  atacante = zeraHP(atacante);
	
}
