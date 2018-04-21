//------------------------------------------------------------------------------
// Quote.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Quote.h"
#include "GameView.h"


//------------------------------------------------------------------------------
Quote::Quote()
{
}

//------------------------------------------------------------------------------
Quote::Quote(std::string name) : Command(name)
{
}




//------------------------------------------------------------------------------
Quote::~Quote()
{
}

//------------------------------------------------------------------------------
int Quote::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  std::string output_string;
  int lemonPrice , sugarPrice;
  
  lemonPrice = game.getPriceLemons();
  sugarPrice = game.getPriceSugar();
  
  if(parameters.size() > 0)
  {
    output_engine.print("[ERR] Usage: quote\n"); 
  }
  else
  {
    output_string += "L: " + std::to_string(lemonPrice) + " $\n";
    output_string += "S: " + std::to_string(sugarPrice) + " $\n";
    output_engine.print(output_string);
  }
  return 0;
}
