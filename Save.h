//------------------------------------------------------------------------------
// Save.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"


//----------------------------------------------------------------------------
// Save Class
// command save
// saves values to a savefile
//
class Save : public Command
{
  public:
    Save();
    Save(std::string name);
    ~Save();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Saving functionality, values to be saved stored in an xml like file
    // @param game The game where action should be performed on
    // @param parameters name of the savefile 
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);

};


#endif //SAVE_H_INCLUDED
