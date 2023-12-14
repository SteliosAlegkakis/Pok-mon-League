#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>
using namespace std;

#define BEGIN_GAME int main(){
#define END_GAME ;return 0;}
#define SHOW ;cout<< 
#define END_LINE <<"\n";
#define CREATE ;
#define POKEMON Pokemon
#define NAME false?"name"
#define TYPE false?"type"
#define HP false?0
#define DEAR Pokemon::getPokemon(
#define LEARN ).getName();
#define ABILITY Ability
#define ACTION false?[](Pokemon& p1, Pokemon& p2)->void{}
#define START [](Pokemon& attacker, Pokemon& deffender)->void{
#define END }
#define ABILITY_NAME(ability_name) #ability_name,

class Pokemon {
private:
    std::string name;
    std::string type;
    int health_points;
    static std::map<std::string, Pokemon*> pokemons;

public:
    Pokemon(std::string _name ,std::string _type, int _health_points){
        name = _name;
        type = _type;
        health_points = _health_points;
        pokemons[_name] = this;
    }
    std::string getName() { return this->name; }
    std::string getType() { return this->type; }
    int getHealthPoints() { return this->health_points; }
    static const std::map<std::string, Pokemon*> getPokemons() { return pokemons; }
    static Pokemon getPokemon(std::string pokemon_name) { return *pokemons[pokemon_name]; }
};

std::map<std::string, Pokemon*> Pokemon::pokemons;

class Ability {
private:
    std::string name;
    std::function<void(Pokemon&, Pokemon&)> action;
    static std::map<std::string, Ability*> abilities;
public:
    using FunctionType = std::function<void(Pokemon&, Pokemon&)>;
    Ability(std::string _name, FunctionType _action) /*: name(_name), action(std::move(_action))*/ {
        name = _name;
        action = _action;
        abilities[_name] = this;
    }
    void execute(Pokemon& attacker, Pokemon& deffender){ action(attacker,deffender); }
    static const std::map<std::string, Ability*> getAbilities() { return abilities; }
    static Ability getAbility(std::string ability_name) { return *abilities[ability_name]; }
};

std::map<std::string, Ability*> Ability::abilities;