//------------------------------------------------------------------------------
// Forecast.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef FORECAST_H_INCLUDED
#define FORECAST_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "GameHandler.h"
#include "Command.h"


//----------------------------------------------------------------------------
// Forecast Class
// command forecast
// prints the weather forecast for the next game round
//
class Forecast : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Forecast();
    Forecast(std::string name);

    
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Forecast();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Prints the forecast for the next gameround
    // @param game The game where action should be performed on
    // @param params should be empty for this command
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);
    
    
};

#endif //FORECAST_H_INCLUDED
