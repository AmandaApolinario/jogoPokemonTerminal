#ifndef POKEMON_H
#define POKEMON_H

#include "../include/ataque.h"
#include "../include/usuario.h"

typedef struct jogador tJogador; //struct de jogadores
typedef struct pokemon tPokemon; //struct dos pokemons
typedef struct listnode ListNode; //struct para a lista encadeada dos pokemons

//function pointer para o callback das funcoes de ataque
typedef void(*callback)(tPokemon* usuario, tPokemon* inimigo);

//preenche o struct pokemon com as informações recebidas, incluindo os callback de ataques
tPokemon *InicializaPokemon(char nome[128], int tipo, float HP, int atk, int def,char NomeAtaque1[20],callback atk1,char NomeAtaque2[20],callback atk2,char NomeAtaque3[20],callback atk3);

//aloca a memoria do pokemon
tPokemon* MallocPokemon(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon pikachu
tPokemon* CriaPikachu(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon charizard
tPokemon * CriaCharizard(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon blastoise
tPokemon* CriaBlastoise(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon venosaur
tPokemon* CriaVenusaur(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon steelix
tPokemon* CriaSteelix(tPokemon* pokemon);

//chama InicializaPokemon com as informações para criar um pokemon mew
tPokemon* CriaMew(tPokemon* pokemon);

//printa o nome do pokemon passado
void PrintaPokemon(tPokemon *pokemon);

//funcao que calcula o dano do ataque e diminui o HP do pokemon
tPokemon* causaDano(tPokemon* atacante, tPokemon *defesa,float poder,float MT);

//funcao especial para calcular o dano do dois gumes, já que os dois pokemons sofrem o dano
tPokemon* DanoDG(tPokemon* atacante, tPokemon *defesa,float poder, float MT);

//retorna o tipo do pokemon
float RetornaTipo(tPokemon* atacante, tPokemon* defesa);

//restaura o HP do pokemon após o ataque dormir
tPokemon* recuperaHPdormir(tPokemon* pokemon);

//zera o HP do pokemon caso ele morra
tPokemon* zeraHP(tPokemon* pokemon);

//printa o pokemon inimigo que apareceu na batalha
void PrintBatalha(tPokemon* inimigo);

//printa o HP dos dois pokemons na batalha
void PrintaHP(tPokemon* pokemon, tPokemon* inimigo,FILE *arquivo,int teste);

//libera a memoria do pokemon
void FreePokemon(tPokemon* pokemon);

//funcao que permite o usuario escolher os 3 pokemons
ListNode * EscolhePokemons();

//funcao que inicia o array com os pokemons para a escolha do usuario
void InicializaArrayEscolhePokemon();

//por meio de function pointer e o array acima, chama a função para criar o pokemon escolhido
tPokemon *AvaliaTabela(int a);

//adiciona o pokemon correspondente a opcao passada em parametro no fim da lista de pokemons que o usuario possui
ListNode * addLast(ListNode **lista,int opcao);

//printa todos os pokemons que o usuario possui
void printList(ListNode *head);

//remove o primeiro pokemon da lista encadeada de pokemons
ListNode * deleteFirstNode(ListNode *head);

//libera a memoria da lista de pokemons
void deleteList(ListNode** head_ref);

/*retorna o primeiro pokemon da lista
*/
tPokemon * RetornaPokemonDaLista(ListNode *lista);

/*retorna um pokemon aleatorio para a batalha
*/
tPokemon * RetornaPokemonAleatorio(int UltimoMew);

//printa a lista de ataques do pokemon do usuario
void PrintaListaAtaques(tPokemon* pokemon, tJogador *jogador);

//chama a funcao de ataque escolhida caso o pokemon tenha direito a seu turno
int EscolheAtaque(tPokemon* pokemon, tPokemon* inimigo,ListNode* listaDePokemons,tJogador* jogador,FILE *arquivo);

//funcao para calcular se o jogador consegue fugir da batalha
int FogeDaBatalha();

//funcao para verificar se o jogador captura o pokemon inimigo
int CapturaPokemon(ListNode *lista,tJogador* jogador,tPokemon *inimigo,FILE *arquivo);

//retorna o HP atual do pokemon
float GetHP(tPokemon* pokemon);

//escolhe aleatoriamente o ataque do pokemon inimigo
void AtaqueInimigo(tPokemon* usuario, tPokemon* inimigo,FILE *arquivo);

//paralisa o pokemon
tPokemon* Paralisa(tPokemon* pokemon);

//diminui o turno que o pokemon tem que ficar paralisado
tPokemon* ReduzTurnosParalisado(tPokemon* pokemon);

//retorna quantos turnos o pokemon ainda tem paralisado
int GetTurnosParalisado(tPokemon* pokemon);

//desparaliza o pokemon
tPokemon* Desparalisa(tPokemon* pokemon);

//retorna se o pokemon esta paralizado ou nao
int GetParalisa(tPokemon* pokemon);

//funcao que faz o pokemon dormir, e depois retoma todo o seu HP
tPokemon* Dorme(tPokemon* pokemon);

//funcao que calcula quantos turnos o pokemon passada paralizado
tPokemon* PoDeSono(tPokemon* pokemon);

//funcao que reduz a quantidade de turnos dormindo do pokemon
tPokemon* ReduzTurnosDormindo(tPokemon* pokemon);

//funcao que retorna quantos turnos o pokemon tem dormindo
int GetTurnosDormindo(tPokemon *pokemon);

//funcao que acorda o pokemon
tPokemon* Acorda(tPokemon* pokemon);

//retorna se o pokemon esta dormindo
int GetDorme(tPokemon* pokemon);

tPokemon* Queima(tPokemon* pokemon);

int GetQueima(tPokemon* pokemon);

tPokemon* DanoQueima(tPokemon* pokemon);

int InimigoEhMew(tPokemon* pokemon);

tPokemon* Protege(tPokemon* pokemon);

tPokemon* Desprotege(tPokemon* pokemon);

int GetProtege(tPokemon* pokemon);

tPokemon* Cavar(tPokemon* pokemon);

tPokemon* OutCavar(tPokemon* pokemon);

int GetCavar(tPokemon* pokemon);

//funcao pra recuperar 10 pontos de HP apos ganhar uma batalha
tPokemon* RecHPvitoria(tPokemon* pokemon);

void PrintaVSnoArquivo(ListNode *lista,tPokemon *pokemon,int partida,int batalha,FILE *arquivo);

#endif