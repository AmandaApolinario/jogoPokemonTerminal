#ifndef BATALHA_H
#define BATALHA_H

/*Funcao para controlar a batalha entre os pokemons do usuario e os da IA
parametros-
listaPokemon: lista encadeada com os pokemons que o usuario possui
inimigo: tPokemon criado aleatoriamente para batalhar
jogador: o usuario jogando, para ter acesso a suas informações
arquivo: o arquivo que o log de batalhas é salvo
return: a lista atualizada com os pokemons que estão vivos
*/
ListNode* batalha(ListNode *listaPokemon,tPokemon *inimigo, tJogador* jogador,FILE *arquivo,int partida,int batalha);

/*Funcao que controla as ações do usuario e se ele tem direito a atacar
parametros-
usuario: pokemon do usuario que esta batalhando
inimigo: pokemon inimigo
jogador: o usuario jogando
arquivo: o arquivo que o log de batalhas é salvo
listaDePokemons: a lista encadeada com os pokemons que o usuario possui	


//return??

*/
int JogadaUsuario(tPokemon* usuario, tPokemon* inimigo, tJogador* jogador,ListNode* listaDePokemons,FILE *arquivo);

/*funcao que controla as jogadas aleatorias do pokemon inimigo
parametros-
usuario: pokemon do usuario que esta batalhando
inimigo: pokemon inimigo
jogador: o usuario jogando
arquivo: o arquivo que o log de batalhas é salvo
return: o pokemon inimigo
*/
tPokemon* JogadaInimigo(tPokemon* usuario, tPokemon* inimigo, tJogador* jogador,FILE *arquivo);

#endif