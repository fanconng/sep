//------------------------------------------------------------------------------
// Echo.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Echo.h"
#include "GameView.h"

//------------------------------------------------------------------------------
Echo::Echo()
{
}

//------------------------------------------------------------------------------
Echo::Echo(std::string name) : Command(name)
{
}


//------------------------------------------------------------------------------
Echo::~Echo()
{
}

//------------------------------------------------------------------------------
int Echo::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  std::string output_string;
  
  // if the parameters vector is empty only a '\n' will be sent to the console.
  if(parameters.size() != 0)
  {
    for(unsigned int i = 0; i < parameters.size(); ++i)
    {
      output_string += parameters.at(i);
      if(i != parameters.size() - 1)
      {
        output_string += " ";
      }
    }
  
  }
  output_string += "\n";
  output_engine.print(output_string);
  return 0;
}
