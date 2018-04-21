//------------------------------------------------------------------------------
// Setweather.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef SETWEATHER_H_INCLUDED
#define SETWEATHER_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"


//----------------------------------------------------------------------------
// Setweather Class
// command setweather
// used for debugging, sets the weather for the next round
//
class Setweather : public Command
{
  private:
    //--------------------------------------------------------------------------
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Setweather();
    Setweather(std::string name);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Setweather();


    //--------------------------------------------------------------------------
    // Executes the command.
    // Wrapper around the setters of EnvironmentalCondition
    // a setWeather flag will be set for the next use of play 
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);
    
    
};

#endif //SETWEATHER_H_INCLUDED
