//------------------------------------------------------------------------------
// Buy.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef BUY_H_INCLUDED
#define BUY_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"


//----------------------------------------------------------------------------
// Buy Class
// command buy
// buys the passed amounts of lemons and sugar
//
class Buy : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Buy();
    Buy(std::string name);
    

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Buy();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Quits the current session.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);
    
    
};

#endif //BUY_H_INCLUDED
