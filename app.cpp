#include "PokemonLeague.h"

BEGIN_GAME

CREATE POKEMON {
    NAME : "Pikachu",
    TYPE : "Electric",
    HP : 120
}

CREATE POKEMONS [
    POKEMON {
        NAME : "Squirtle",
        TYPE : "Water",
        HP : 120
    },
    POKEMON {
        NAME : "Charmander",
        TYPE : "Fire",
        HP : 120
    },
    POKEMON {
        NAME : "Bulbasaur",
        TYPE : "Grass",
        HP : 120
    }
]

CREATE ABILITY {
    NAME : "electric_shock",
    ACTION : START 
        IF NOT(IS_IN_POKEBALL(DEFENDER)) DO
            DAMAGE DEFENDER 20
            POKEBALL DEFENDER ---α
        ELSE
            POKEBALL DEFENDER _
        END
    END
}

CREATE ABILITIES [
    ABILITY {
        NAME : "bite",
        ACTION : START 
            IF AND(GET_HP(DEFENDER) >= 100,NOT(IS_IN_POKEBALL(DEFENDER))) DO
                DAMAGE DEFENDER 20
            ELSE
                DAMAGE DEFENDER 10
            END
        END
    },
    ABILITY {
        NAME : "slash",
        ACTION : START 
            IF OR(GET_TYPE(ATTACKER) == "Fire",GET_TYPE(ATTACKER) == "Water") DO
                DAMAGE DEFENDER 20
            ELSE
                DAMAGE DEFENDER 10
            END
        END
    },
    ABILITY {
        NAME : "blaze",
        ACTION : START
            DAMAGE DEFENDER 30
            HEAL ATTACKER 20
        END
    }
]

DEAR "Pikachu" LEARN [
    ABILITY_NAME(electric_shock)
    ABILITY_NAME(bite)
    ABILITY_NAME(slash)
]

DEAR "Charmander" LEARN [
    ABILITY_NAME(blaze)
    ABILITY_NAME(slash)
    ABILITY_NAME(bite)
]

DEAR "Bulbasaur" LEARN [
    ABILITY_NAME(bite)
    ABILITY_NAME(slash)
]

DEAR "Squirtle" LEARN [
    ABILITY_NAME(bite)
    ABILITY_NAME(slash)
]

DUEL

END_GAME