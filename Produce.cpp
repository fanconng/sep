//------------------------------------------------------------------------------
// Produce.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Produce.h"
#include "GameView.h"
#include <sstream>


//------------------------------------------------------------------------------
Produce::Produce()
{
}

//------------------------------------------------------------------------------
Produce::Produce(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
Produce::~Produce()
{
}

//------------------------------------------------------------------------------
int Produce::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  
  int recipe_lemons = game.getRecipeLemons() / 3; 
  int recipe_sugar = game.getRecipeSugar() / 2;
  int possible_lemons = game.getLemons() / recipe_lemons; 
  int possible_sugar = game.getSugar() / recipe_sugar;
  
  if(parameters.size() != 1)
  {
    output_engine.print("[ERR] Usage: produce <lemonade>\n");
  }
  else
  {
    std::stringstream input_check;
    int lemonades;
    input_check << parameters.at(0);
    input_check >> lemonades;
    
    if(input_check.eof() != 1)
    {
      output_engine.print("[ERR] Wrong parameter.\n");
    }
    int lemons_usage = recipe_lemons * lemonades;
    int sugar_usage = recipe_sugar * lemonades;
    
    if(lemons_usage > game.getLemons() || sugar_usage > game.getSugar())
    {
      std::stringstream message;
      
      if(possible_lemons < possible_sugar)
      {
        game.setProducedLemonade(possible_lemons);
        game.setLemons(game.getLemons() - possible_lemons * recipe_lemons);
        game.setSugar(game.getSugar() - possible_lemons * recipe_sugar);
        message << "You had only enough lemons for " << possible_lemons;
        message << " portions of lemonade.\n";
        output_engine.print(message.str());
      
        
      }
      else
      {
        game.setProducedLemonade(possible_sugar);
        game.setLemons(game.getLemons() - possible_sugar * recipe_lemons);
        game.setSugar(game.getSugar() - possible_sugar * recipe_sugar);
        message << "You had only enough sugar for " << possible_sugar;
        message << " portions of lemonade.\n";
        output_engine.print(message.str());
      }
    }
    else
    {
      game.setProducedLemonade(lemonades);
      game.setLemons(game.getLemons() - lemonades * recipe_lemons);
      game.setSugar(game.getSugar() - lemonades * recipe_sugar);
      
    }
    
  }
  return -1;
}
