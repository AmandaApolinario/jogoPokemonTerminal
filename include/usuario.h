#ifndef USUARIO_H
#define USUARIO_H 
#include <stdio.h>
#include "../include/ataque.h"
#include "../include/pokemon.h"

//struct com as informações do jogador
typedef struct jogador tJogador;

/*função que retorna o proximo jogador na lista encadeada
parametro- jogador: o jogador atual no nó
return - o proximo jogador na lista
*/
tJogador * ProxJogador(tJogador *jogador);

/*aloca a memoria do jogador
parametro- o jogador atual sem estar alocado
return - o jogador alocado na memoria
*/
tJogador *MallocJogador(tJogador *jogador);

/*escolhe a opcao do menu que o usuario deseja escolher
return: 1 - jogar
2- melhores pontuacoes
3- sair
*/
int MenuInicial();

/*verifica se o nome digitado pelo usuario eh valido
parametro- user: nome escolhido pelo usuario
return: 1:nome aceito
2: nome invalido
*/
int VerificaUser(char user[128]);

/*Cria o jogador e preenche a struct
parametros:
jogador: o nó na lista com o jogador
partida: o numero da partida do jogador
return- o struct do jogador
*/
tJogador* Login(tJogador *jogador,int partida);

/*Adiciona o novo jogador ao fim da lista de jogadores
parametros-
head: o primeiro jogador
partida: o numero da partida do jogador
return - a lista atualizada de jogadores
*/
tJogador * adicionarJogador(tJogador **head,int partida);

/*libera os jogadores da memoria
parametro- a lista de jogadores que é pra ser liberada
*/
void LiberaJogadores(tJogador** head);

/*recebe um jogador e retorna a quantidade de vitorias
*/
int GetVitorias(tJogador* jogador);

/*Recebe um jogador e aumenta a quantidade de vitorias dele, retornando o mesmo jogador
*/
tJogador* AumentaVitorias(tJogador* jogador);

//recebe um jogador e retorna a quantidade de pokebolas que ele possui
int GetPokebola(tJogador* jogador);

/*funcao para diminuir a quantidade de pokebolas de um jogador
parametros-
jogador: o jogador da partida atual
pegouPokemon: indica se o pokemon foi capturado caso seja 1 e 0 caso n foi
*/
void DiminuitPokebola(tJogador* jogador,int pegouPokemon);

/*Funcao que ordena a pontuação dos usuarios
parametros-
jogadores: a lista encadeada de jogadores
arquivo: o arquivo para salvar a pontuacao
*/
void OrdenaPontuacao(tJogador *jogadores,char *end,int printarNoTerminal);

/*Funcao que printa todos os jogadores
parametro- o inicio da lista encadeada
*/
void PrintaJogadores(tJogador *head);

/*funcao que printa o jogador que esta jogando no momento
*/
void PrintaJogadorAtual(tJogador *jogador);

//calcula se o jogador conseguiu ou nao a pokebola e, se tiver conseguido, aumenta em 1 o numero de pokebolas do jogador
tJogador* ChancePokebola(tJogador* jogador, int C);

//retorna 1 se o jogador tiver conseguido uma pokebola e 0 se nao tiver conseguido
int GetConseguiuPokebola(tJogador* jogador);

//zera o int que informa se o jogador conseguiu ou nao uma pokebola
tJogador* ZeraConseguiuPoke(tJogador* jogador);

//printa "(nome do jogador) venceu!"
void PrintaVitoria(tJogador* jogador,FILE *arquivo);

char * NomeJogador(tJogador *jogador);

#endif