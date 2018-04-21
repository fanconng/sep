//------------------------------------------------------------------------------
// Quit.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef QUIT_H_INCLUDED
#define QUIT_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Quit Class
// command quit
// quits the game and the running program.
//
class Quit : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Quit();
    Quit(std::string name);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Quit();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Quits the current session.
    // @param game The game where action should be performed on
    // @param params for this command the vector should be empty
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);
    
    
};

#endif //QUIT_H_INCLUDED
