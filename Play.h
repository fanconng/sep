//------------------------------------------------------------------------------
// Play.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include <string>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Play Class
// command play
// start one gameround, cash will be updated according to calculations,
// recipe_*, produced_lemonades will be reset.  
//
class Play : public Command
{
  private:
    std::string command_name_;
    
  public:
    //--------------------------------------------------------------------------
    // Constructor & Destructor
    Play();
    virtual ~Play();
  
  

    //--------------------------------------------------------------------------
    // Executes the command.
    // The player starts one gameround with this command
    // @param game The game where action should be performed on
    // @param params only one int should be passed here
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);
    

};

#endif
