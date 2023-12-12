#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define BEGIN_GAME int main(){
#define END_GAME ;return 0;}
#define SHOW ;cout<< 
#define CREATE ;
#define POKEMON Pokemon
#define NAME false?"name"
#define TYPE false?"type"
#define HP false?0

class Pokemon
{
private:
    std::string name;
    std::string type;
    int health_points;
    static vector<Pokemon*> pokemons; 
public:
    Pokemon(std::string _name ,std::string _type, int _health_points);
    std::string getName() { return this->name; }
    std::string getType() { return this->type; }
    int getHealthPoints() { return this->health_points; }
    static const std::vector<Pokemon*> &getPokemons() { return pokemons; }
};

std::vector<Pokemon*> Pokemon::pokemons;

Pokemon::Pokemon(std::string _name ,std::string _type, int _health_points)
{
    name = _name;
    type = _type;
    health_points = _health_points;
    pokemons.push_back(this);
}