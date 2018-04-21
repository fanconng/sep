//------------------------------------------------------------------------------
// Quote.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"


//----------------------------------------------------------------------------
// Quote Class
// command quote
// prints the current prices for lemons and sugar
//
class Quote : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Quote();
    Quote(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~Quote();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Prints the current prices for lemons and sugar.
    // @param game The game where action should be performed on
    // @param parameters Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);
    
    
};

#endif //QUOTE_H_INCLUDED
