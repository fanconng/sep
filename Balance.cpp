//------------------------------------------------------------------------------
// Balance.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Balance.h"
#include "GameView.h"


//------------------------------------------------------------------------------
Balance::Balance()
{
}

//------------------------------------------------------------------------------
Balance::Balance(std::string name) : Command(name)
{
}



//------------------------------------------------------------------------------
Balance::~Balance()
{
}

//------------------------------------------------------------------------------


int Balance::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  std::string output_string;
  int balance = game.getIncome() - game.getExpense();
  
  if(parameters.size() > 0)
  {
    output_engine.print("[ERR] Usage: balance\n");
  }
  else
  {
    output_string += "L: " + std::to_string(game.getLemons()) + "\n";
    output_string += "S: " + std::to_string(game.getSugar())+ "\n";
    output_string += "----------\n";
    output_string += "C: " + std::to_string(game.getCash()) + " $\n";
    output_string += "B: " + std::to_string(balance) + " $\n";
    output_engine.print(output_string);	
  }
  return 0; 
}
