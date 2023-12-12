#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

#define BEGIN_GAME int main(){
#define END_GAME ;return 0;}
#define SHOW ;cout<< 
#define CREATE ;
#define POKEMON Pokemon
#define NAME false?"name"
#define TYPE false?"type"
#define HP false?0
#define DEAR Pokemon::getPokemon(
#define LEARN ).getName();

class Pokemon
{
private:
    std::string name;
    std::string type;
    int health_points;
    static std::map<std::string, Pokemon*> pokemons;
    
public:
    Pokemon(std::string _name ,std::string _type, int _health_points);
    std::string getName() { return this->name; }
    std::string getType() { return this->type; }
    int getHealthPoints() { return this->health_points; }
    static const std::map<std::string, Pokemon*> getPokemons() { return pokemons; }
    static Pokemon getPokemon(std::string pokemon_name) { return *pokemons[pokemon_name]; }
};

std::map<std::string, Pokemon*> Pokemon::pokemons;

Pokemon::Pokemon(std::string _name ,std::string _type, int _health_points)
{
    name = _name;
    type = _type;
    health_points = _health_points;
    pokemons[_name] = this;
}