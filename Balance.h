//------------------------------------------------------------------------------
// Balance.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef BALANCE_H_INCLUDED
#define BALANCE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Balance Class
// command balance
// prints the current storage values, cash and the balance of the last round
//
class Balance : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructors
    Balance();
    Balance(std::string name);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Balance();


    //--------------------------------------------------------------------------
    // Executes the command.
    // Prints the current balances to the console.
    // @param game The game where action should be performed on
    // @param parameters Possible parameters needed for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);
    
    
};

#endif //BALANCE_H_INCLUDED
