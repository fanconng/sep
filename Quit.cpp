//------------------------------------------------------------------------------
// Quit.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Quit.h"
#include "GameView.h"


//------------------------------------------------------------------------------
Quit::Quit()
{
}

//------------------------------------------------------------------------------
Quit::Quit(std::string name) : Command(name)
{
}




//------------------------------------------------------------------------------
Quit::~Quit()
{
}

//------------------------------------------------------------------------------
int Quit::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  
  
  if(parameters.size() != 0)
  {
    output_engine.print("[ERR] Usage: quit\n");
  }
  else
  {
    output_engine.print("Going out of business!\n");
    game.setRunning(false);
  }
  return -1;
}
