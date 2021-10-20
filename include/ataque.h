#ifndef ATAQUE_H
#define ATAQUE_H

#include "../include/pokemon.h"
#include "../include/usuario.h"

//Function Pointer para o ataque do metronomo
typedef void(*fptrAtaqueMetronomo)(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com choque do trovao
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void choqueDoTrovao(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Onda de choque
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void ondaDeChoque(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon com Bater
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void Bater(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Lança Chamas
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void lancaChamas(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Dormir
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void dormir(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon com Arma de Agua
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void armaDeAgua(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Proteger
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void proteger(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon com Pó de sono
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void poDeSono(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon com Bomba De Semente
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void bombaDeSemente(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Dois Gumes
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void doisGumes(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Rabo de Ferro
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void raboDeFerro(tPokemon* atacante, tPokemon* defesa);

/*Funcao para atacar o pokemon com Cavar
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void cavar(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon após o Cavar, já que o ataque nao é imediato
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
tPokemon* AtaqueAtrasado(tPokemon* atacante, tPokemon* defesa, float poder, float MT);

/*Funcao escolher aleatoriamente o ataque do metronomo
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void metronomo(tPokemon* usuario, tPokemon* inimigo);

/*Funcao para atacar o pokemon com auto-Destruir
parametros:
atacante - pokemon que esta praticando o ataque
defesa - pokemon que esta se defendendo
*/
void autoDestruir(tPokemon* atacante, tPokemon* defesa);

//Cria o array com os ataques que o metronomo pode escolher
void InicializaArrAtaqueMetronomo();

//printa no terminal o ataque escolhido pelo metronomo
//parametro - op é a posicao do ataque no array dos ataques do metronomo
void PrintaAtaqueMetronomo(int op);

#endif