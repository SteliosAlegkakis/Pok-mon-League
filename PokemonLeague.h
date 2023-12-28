#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <sstream>

using namespace std;

#define BEGIN_GAME int main(){
#define END_GAME ;return 0;}
#define SHOW ;cout<< 
#define END_LINE <<"\n";
#define CREATE ;
#define POKEMON Pokemon
#define POKEMONS Pokemons{}
#define NAME false?"name"
#define TYPE false?"type"
#define HP false?0
#define DEAR ;Pokemon::getPokemon(
#define LEARN )
#define ABILITY Ability
#define ABILITIES Abilities{}
#define ACTION false?[](Pokemon& p1, Pokemon& p2)->void{}
#define START [](Pokemon& attacker, Pokemon& defender)->void{
#define END ;}
#define ABILITY_NAME(ability_name) #ability_name" "
#define ATTACKER attacker,
#define DEFENDER defender,
#define IF if(
#define DO ){
#define ELSE_IF ;}else if(
#define ELSE ;}else{
#define HEAL ;Heal(),
#define DAMAGE ;Damage(attacker.getType()),
#define GET_NAME(pokemon) getName(pokemon 0)
#define GET_HP(pokemon) getHp(pokemon 0)
#define GET_TYPE(pokemon) getType(pokemon 0)
#define IS_IN_POKEBALL(pokemon) isInPokeball(pokemon 0)
#define _heal 0
#define _damage 1
#define DUEL ;duel();
#define in true
#define out false
#define POKEBALL ;
#define _ -1
#define _1 -2
#define α -Pokeball()

class Pokemon {
private:
    std::string name;
    std::string type;
    int health_points;
    int max_health;
    bool inPokeball = out;
    std::string owner;
    int heal_damage = 0;
    std::string attacker_type = "";
    static std::map<std::string,std::vector<std::string>> abilities;
    static std::map<std::string, Pokemon*> pokemons;
    static int round;
public:
    Pokemon(std::string _name ,std::string _type, int _health_points){
        name = _name;
        type = _type;
        health_points = _health_points;
        max_health = _health_points;
        pokemons[_name] = this;
    }
    std::string getName() { return this->name; }
    std::string getType() { return this->type; }
    int getHealthPoints() { return this->health_points; }
    int getMaxHealth() { return this->max_health; } 
    bool isInPokeball() { return this-> inPokeball; }
    void setHealDamage(int value) { this->heal_damage = value; }
    void setAttackerType(std::string _attacker_type) { this->attacker_type = _attacker_type; }
    void setOwner(std::string _owner) { this->owner = _owner; }
    std::string getOwner() {return owner;}

    static const std::map<std::string, Pokemon*> getPokemons() { return pokemons; }
    static Pokemon getPokemon(std::string pokemon_name) { return *pokemons[pokemon_name]; }
    static void incrementRound() { 
        round++;
        SHOW "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" END_LINE
        SHOW "Round " << round END_LINE 
        SHOW "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" END_LINE
    }
    static int getRound() { return round; }

    void damage(int damage_points) {
        if(type == "Electric"){
            if(attacker_type == "Fire") damage_points -= damage_points*0.3;
            else  damage_points -= damage_points*0.2;
        }
        else if(type == "Water") damage_points -= damage_points*0.07; 

        if(attacker_type == "Fire"){
            if(type == "Electric") damage_points += damage_points*0.2;
            else damage_points += damage_points*0.15;
        }
        else if(attacker_type == "Water") damage_points += damage_points*0.07;
        else if(attacker_type == "Grass") if(round%2!=0) damage_points += damage_points*0.07;

        health_points -= damage_points;
        if(health_points < 0) health_points = 0;
    }

    void heal(int heal_points) { health_points += heal_points; }

    static void printPokemons() {
        SHOW "--------------------------" END_LINE
        for (auto pair = pokemons.begin(); pair != pokemons.end(); ++pair) cout << pair->first END_LINE
        SHOW "--------------------------" END_LINE
    }

    void printAbilities() { 
        std::vector<std::string> abs = abilities[name];
        SHOW "--------------------------" END_LINE
        for(int i=0;i<abs.size();i++) cout << abs.at(i) END_LINE
        SHOW "--------------------------" END_LINE
    }

    void printStatus() {
        SHOW " " END_LINE
        SHOW "##########################" END_LINE
        SHOW "NAME : " << name END_LINE
        SHOW "HP : " << health_points END_LINE
        SHOW "Pokemon " << (inPokeball?"in pokeball":"out of Pokeball") END_LINE
        SHOW "##########################" END_LINE
        SHOW " " END_LINE
    }

    void operator[](std::string _abilities){
        std::istringstream s(_abilities);
        std::string token;
        std::vector<std::string> abilities_vector;

        while (s >> token) abilities_vector.push_back(token);

        abilities[name] = abilities_vector;
    }

    void operator,(const int& hp){
        SHOW hp END_LINE
        if(hp == -1) this->inPokeball = out;
        else if(hp == -2) this->inPokeball = in;
        else this->heal_damage == _damage?damage(hp):heal(hp);
    }
};

std::map<std::string, Pokemon*> Pokemon::pokemons;
std::map<std::string, std::vector<std::string>> Pokemon::abilities;
int Pokemon::round = 0;

std::string getName(Pokemon pokemon,int foo) { return pokemon.getName(); }
std::string getType(Pokemon pokemon,int foo) { return pokemon.getType(); }
int getHp(Pokemon pokemon,int foo) { return pokemon.getHealthPoints(); }
bool isInPokeball(Pokemon pokemon,int foo) { return pokemon.isInPokeball(); }

class Pokemons{
public:
    Pokemons(){}
    template<typename... Args> 
    void operator[](Args... args){}   
};

class Heal{
public:
    Heal(){}
    Pokemon& operator,(Pokemon& pokemon){
        pokemon.setHealDamage(_heal);
        return pokemon;
    }
};

class Damage{
private:
    std::string attacker_type;
public:
    Damage(std::string _attacker_type){ attacker_type = _attacker_type; }
    Pokemon& operator,(Pokemon& pokemon){ 
        pokemon.setHealDamage(_damage);
        pokemon.setAttackerType(attacker_type);
        return pokemon; 
    }
};

class Pokeball {
public:
    Pokeball(){}
    Pokeball operator-(){ return *this; }
    int operator--() {return -2;}
};

class Ability {
private:
    std::string name;
    std::function<void(Pokemon&, Pokemon&)> action;
    static std::map<std::string, Ability*> abilities;
public:
    using FunctionType = std::function<void(Pokemon&, Pokemon&)>;
    Ability(std::string _name, FunctionType _action) {
        name = _name;
        action = _action;
        abilities[_name] = this;
    }
    void execute(Pokemon& attacker, Pokemon& deffender){ action(attacker,deffender); }
    static const std::map<std::string, Ability*> getAbilities() { return abilities; }
    static Ability getAbility(std::string ability_name) { return *abilities[ability_name]; }
};

std::map<std::string, Ability*> Ability::abilities;

class Abilities {
public:
    Abilities(){}
    template<typename... Args> 
    void operator[](Args... args){} 
};

template<typename... Args>
bool AND(bool arg1,bool arg2,Args... args){
    if(!arg1 || !arg2) return false;
    bool result = ((args == false) || ...);
    return !result;
}

template<typename... Args>
bool OR(bool arg1,bool arg2,Args... args){
    if(arg1 || arg2) return true;
    bool result = ((args == true) || ...);
    return result;
}

bool NOT(bool argument){
    return !argument;
}

Pokemon selectPokemon(std::string player_name){
    SHOW player_name << " select pokemon: " END_LINE
    Pokemon::printPokemons();
    std::string pokemon_name;
    std:getline(cin,pokemon_name);
    SHOW "\n";
    Pokemon pokemon = Pokemon::getPokemon(pokemon_name);
    pokemon.setOwner(player_name);
    return pokemon;
}

std::string selectAbility(Pokemon pokemon){
    SHOW "\n";
    SHOW pokemon.getName() << "(" << pokemon.getOwner() << ") select ability:" END_LINE
    pokemon.printAbilities();
    std::string ability;
    getline(cin,ability);
    return ability; 
}

void printStatus(Pokemon p1,Pokemon p2){
    p1.printStatus();
    p2.printStatus();
}

bool isGameFinished(Pokemon p1,Pokemon p2){
    return (p1.getHealthPoints() <= 0 || p2.getHealthPoints() <= 0);
}

bool play(Pokemon &attacker,Pokemon &defender){
    if(attacker.getType() == "Grass" && Pokemon::getRound()%2 != 0) attacker.heal(attacker.getMaxHealth()*0.07);
    if(!attacker.isInPokeball()) {
        Ability::getAbility(selectAbility(attacker)).execute(attacker,defender);
        printStatus(attacker,defender);
    } else {
        SHOW "\n" << attacker.getName() << "(" << attacker.getOwner() <<") has not a pokemon out of pokeball so he can't cast an ability" END_LINE
    }
    return isGameFinished(attacker,defender);
}

void duel(){
    SHOW "\n";
    SHOW "----------------------------- POKEMON THE GAME --------------------------------" END_LINE
    SHOW "\n";

    Pokemon player_1 = selectPokemon("Player 1");
    Pokemon player_2 = selectPokemon("Player 2");

    while(true){
        Pokemon::incrementRound();
        if(play(player_1,player_2)) break;
        if(play(player_2,player_1)) break;
    }

    player_1.getHealthPoints()<=0?cout<<"\nPlayer 2 won":cout<<"\nPlayer 1 won";
}