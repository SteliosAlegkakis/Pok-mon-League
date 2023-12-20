#include "PokemonLeague.h"

BEGIN_GAME

CREATE POKEMON {
    NAME : "pikatchu",
    TYPE : "electric",
    HP : 120
}

CREATE ABILITY {
    NAME : "electric_shock",
    ACTION : START 
        deffender.takeDamage(20);
    END
}

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

END_GAME