#include "PokemonLeague.h"

BEGIN_GAME

CREATE POKEMON {
    NAME : "pikachu",
    TYPE : "Electric",
    HP : 120
}

CREATE POKEMON {
    NAME : "bulbasaur",
    TYPE : "Grass",
    HP : 120
}

CREATE POKEMONS [
    POKEMON {
        NAME : "squirtle",
        TYPE : "Water",
        HP : 120
    },
    POKEMON {
        NAME : "Ho oh",
        TYPE : "Fire",
        HP : 120
    },
    POKEMON {
        NAME : "charmander",
        TYPE : "Fire",
        HP : 120
    }
]

CREATE ABILITY {
    NAME : "electric_shock",
    ACTION : START 
        IF GET_HP(DEFENDER) == 120 DO
            DAMAGE DEFENDER 100
        ELSE_IF GET_HP(DEFENDER) == 100 DO
            HEAL ATTACKER 20
            DAMAGE DEFENDER 10
        ELSE
            DAMAGE DEFENDER 20
        END
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
    },
    ABILITY {
        NAME : "blaze",
        ACTION : START
            SHOW "blaze" END_LINE
        END
    }
]

DEAR "pikachu" LEARN [
    ABILITY_NAME(electric_shock)
    ABILITY_NAME(bite)
    ABILITY_NAME(slash)
]

DEAR "charmander" LEARN [
    ABILITY_NAME(blaze)
    ABILITY_NAME(slash)
    ABILITY_NAME(bite)
]

DUEL

END_GAME