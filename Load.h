//------------------------------------------------------------------------------
// Load.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Load Class
// command load
// loads values from a savefile
//
class Load : public Command
{
  public:
    Load();
    Load(std::string name);
    ~Load();
    

    //--------------------------------------------------------------------------
    // Executes the command.
    // Loading functionality, values to be loaded stored in an xml like file
    // @param game The game where action should be performed on
    // @param parameters name of the savefile 
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& parameters);

};


#endif //LOAD_H_INCLUDED
