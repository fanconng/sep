//------------------------------------------------------------------------------
// Recipe.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Recipe.h"
#include "GameView.h"
#include <sstream>

//------------------------------------------------------------------------------
Recipe::Recipe()
{
}

//------------------------------------------------------------------------------
Recipe::Recipe(std::string name) : Command(name)
{
}



//------------------------------------------------------------------------------
Recipe::~Recipe()
{
}

//------------------------------------------------------------------------------
int Recipe::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  
  int lemon, sugar, water;
  std::stringstream stream_lemon, stream_sugar, stream_water;
  std::string output_string;
  std::string usage_error = "[ERR] Usage: recipe [lemon] [sugar] [water]\n";
  if(parameters.size() == 0)
  {
    lemon = game.getRecipeLemons();
    sugar = game.getRecipeSugar();
    water = game.getRecipeWater();
           
    output_string += "L: " + std::to_string(lemon) + "%\n";
    output_string += "S: " + std::to_string(sugar) + "%\n";
    output_string += "W: " + std::to_string(water) + "%\n";
    output_engine.print(output_string);
  }
  
  else
  {
    if(parameters.size() != 3)
    {
        output_engine.print(usage_error); 
    }
    else
    {
      stream_lemon << parameters.at(0);
      stream_sugar << parameters.at(1);
      stream_water << parameters.at(2);
      stream_lemon >> lemon;
      stream_sugar >> sugar;
      stream_water >> water;

    if(stream_lemon.eof() != 1 ||
       stream_sugar.eof() != 1 ||
       stream_water.eof() != 1)
    {
      output_engine.print(usage_error);
    }
    else if((sugar + lemon + water) != 100)
    {
      output_engine.print("[ERR] The sum of parts must be 100.\n");
    }
    else if((sugar % 2) != 0)
    {
      output_engine.print("[ERR] The value of Sugar must be a multiple of 2.\n");
    }
    else if((lemon % 3) != 0)
    {
      output_engine.print("[ERR] The value of Lemon must be a multiple of 3.\n");
    }
    else
    {
      game.setRecipeLemons(lemon);
      game.setRecipeSugar(sugar);
      game.setRecipeWater(water);
    }
    }
  }
    
  return 0;
}
