//------------------------------------------------------------------------------
// Recipe.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef RECIPE_H_INCLUDED
#define RECIPE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Recipe Class
// command recipe
// Command used for setting the recipe of printing the current
//
class Recipe : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Recipe();
    Recipe(std::string name);

    //-------------------------------------------------------------------------
    // Destructor

    virtual ~Recipe();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Sets the recipe for the lemonade, arguments passed must be ints.
    // If no arguments are passed it prints the current recipe
    // Errorhandling is done via GameView messages.
    // @param game The game where action should be performed on
    // @param parameters Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);
    
    
};

#endif //RECIPE_H_INCLUDED
