//------------------------------------------------------------------------------
// Produce.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef PRODUCE_H_INCLUDED
#define PRODUCE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"

//----------------------------------------------------------------------------
// Produce Class
// command produce
// used for producing lemonades
//
class Produce : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Produce();
    Produce(std::string name);


    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Produce();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Wrapper for setProducedLemonades, which also calculates the new values of
    // the storage
    // @param game The game where action should be performed on
    // @param params only one int should be passed here
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);
    
    
};

#endif //PRODUCE_H_INCLUDED
