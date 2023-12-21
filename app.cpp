#include "PokemonLeague.h"

BEGIN_GAME

CREATE POKEMON {
    NAME : "pikatchu",
    TYPE : "electric",
    HP : 120
}

CREATE POKEMON {
    NAME : "bulbasaur",
    TYPE : "grass",
    HP : 120
}

// CREATE POKEMONS [
//     POKEMON{
//         NAME : "squirtle"
//         TYPE : "water"
//         HP : 120
//     },
//     POKEMON{
//         NAME: "Ho Oh",
//         TYPE: "Fire",
//         HP: 120
//     },
// ]

CREATE POKEMONS[
    POKEMON{
        NAME : "squirtle",
        TYPE : "water",
        HP : 120
    },
    POKEMON{
        NAME : "Ho oh",
        TYPE : "fire",
        HP : 120
    }
]

CREATE ABILITY {
    NAME : "electric_shock",
    ACTION : START 
        deffender.takeDamage(20);
    END
}

CREATE ABILITIES [
    ABILITY {
        NAME : "bite",
        ACTION : START 
            SHOW "bite" END_LINE
        END
    },
    ABILITY {
        NAME : "slash",
        ACTION : START 
            SHOW "slash" END_LINE
        END
    }
]

;Pokemon::printPokemons();

;Pokemon pikatchu = Pokemon::getPokemon("pikatchu");
DEAR "pikatchu" LEARN [
    ABILITY_NAME(electric_shock)
    ABILITY_NAME(thunderbolt)
    ABILITY_NAME(shockwave)
];
pikatchu.printAbilities();

Pokemon charizard{"charizard","fire",240};
DEAR "charizard" LEARN [
    ABILITY_NAME(fireball)
    ABILITY_NAME(slash)
    ABILITY_NAME(bite)
];
charizard.printAbilities();

Ability::getAbility("electric_shock").execute(pikatchu,charizard);
charizard.printStatus();
pikatchu.printStatus();

SHOW GET_HP(pikatchu) END_LINE
SHOW GET_NAME(pikatchu) END_LINE
SHOW GET_TYPE(pikatchu) END_LINE
SHOW IS_IN_POKEBALL(pikatchu) END_LINE

END_GAME