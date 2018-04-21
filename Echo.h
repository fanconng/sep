//------------------------------------------------------------------------------
// Echo.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef ECHO_H_INCLUDED
#define ECHO_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Echo Class
// command echo
// Echos the passed parameters
//
class Echo : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Echo();
    Echo(std::string name);


    
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Echo();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Works exactly as a unix-bash echo. Echos the passed arguments.
    // @param game The game where action should be performed on
    // @param parameters Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);
    
    
};

#endif //ECHO_H_INCLUDED
