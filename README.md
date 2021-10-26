# Pokemon-Game
This is a terminal-based game developed in my first year of college by my friend and I. We were assigned to do this game as a comprehensive exam of our knowledge in order to pass the class we were taking.

The idea of the game is simple: the player chooses 3 pokemons in the beggining of the game among 6 available, each of them have different HP values and skills that will make the game more interesting.

After choosing them, the player's pokemon will battle with an enemy AI-based pokemon, having always the option of use any of the 3 special skills they have, try to capture the enemy pokemon or try to flee from the battle.

The game ends after all the player's pokemons get defeated by the enemy.

To run it:
* make (compiling)
* ./tp2 (running)

---
### Pokemons
1) Pikachu
> * HP = 200
> * Attack = 110
> * Defense = 100
> * Type = Eletric
> * Skills: Choque do Trovão, Onda de Choque, Bater

2) Charizard
> * HP = 260
> * Attack = 160
> * Defense = 150
> * Type = Fire
> * Skills: Lança Chamas, Dormir, Bater

3) Blastoise
> * HP = 280
> * Attack = 180
> * Defense = 200
> * Type = Water
> * Skills: Arma de Água, Proteger, Bater

4) Venusaur
> * HP = 300
> * Attack = 160
> * Defense = 160
> * Type = Plant
> * Skills: Pó de sono, Bomba de Semente, Dois Gumes

5) Steelix
> * HP = 280
> * Attack = 170
> * Defense = 400
> * Type = Metal
> * Skills: Rabo de Ferro, Dormir, Cavar

6) Mew
> * HP = 320
> * Attack = 200
> * Defense = 200
> * Type = Psychic
> * Skills: Metronomo, Bater, Auto-Destruir

---
### Skills
We used callback functions to make this work. Each skill has a different amount of damage inflicted depending on various variables and some skills can set a status to the enemy pokemon or the player's pokemon, such as **paralizar**, or *stun*: the pokemon can't make any actions, but can still be attacked; **queimar**, or *burn*: the pokemon will receive damage of 1/16 of it's HP until the end of the battle, as if they're losing HP from burning; **dormir**, or *sleep*: the pokemon can't make any moves, but can still be attacked.

Listed bellow are all the skills available in the game:

* Choque do trovão/thunder shock
> Deals damage to opponent, with 10% chance to stun for one turn.
* Onda de Choque/shock wave
> Stun the opponent for one turn.
* Bater/hit
> Deals damage to opponent.
* Lança Chamas/flame thrower
> Deals damage to opponent, with 10% chance to burn.
* Dormir/sleep
> The player's pokemon sleeps during two turns, but recover 100% of its HP after waking up.
* Arma de Água/water gun
> Deals damage to opponent.
* Proteger/protect
> The pokemon will be protected from all attacks in the next turn.
* Pó de Sono/sleeping powder
> The opponent will sleep from 1 to 3 turns, not recovering HP when waking up.
* Bomba de Semente/seed bomb
> Deals damage to opponent.
* Dois Gumes/double edged
> Deals great damage to opponent, but the player's pokemon receives 1/3 of the damage inflicted.
* Rabo de Ferro/iron tail
> Deals damage to opponent.
* Cavar/dig
> Hides in the ground, getting protected in the current turn, and deals damage in the next turn.
* Metrônomo/metronome
> Ramdomly selects one of the available skills.
* Auto-Destruir/self destruction
> Deals great damage to opponent, but the player's pokemon is defeated.

---
### Pokebola/pokeball
In the beginning of the game, the player receives 3 pokeballs. It can be used during the battles to capture an enemy pokemon and add it the player's list of pokemons. The lower the HP of the enemy pokemon is, the greater is the chance of a successfull capture. And everytime the player wins a battle, there's a chance to also win a pokeball.

---
### Fugir/flee
The player can also try to flee from a battle when he's afraid he can't win. There's C/4 chance of succeding, C being the number of times he already tried to flee from the same battle.

---
With this being said, please enjoy the game we made. It was a lot of work but also kinda fun to do. It was also the first time I used callback functions and lists, so I guess I learned a lot from it.

The game has some bugs but in general it's working fine, kinda proud of it hehe. Anywayyy, hope you enjoy (;
Thanks to my friend who wrote this readme s2

