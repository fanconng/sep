//------------------------------------------------------------------------------
// Setweather.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Setweather.h"
#include "GameView.h"
#include "EnvironmentalCondition.h"
#include <sstream>
#include "HTMLWriterEnvironment.h"
#include <iostream>

//------------------------------------------------------------------------------
Setweather::Setweather()
{
}

//------------------------------------------------------------------------------
Setweather::Setweather(std::string name) : Command(name)
{
}



//------------------------------------------------------------------------------
Setweather::~Setweather()
{
}

//------------------------------------------------------------------------------
int Setweather::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  //setweather <cover> <precipitation> <temperature> <wind>
  
  GameView output_engine;
  
  int sky_cover, precipitation, wind;
  float temperature;
  std::stringstream stream_cover, stream_precipitation;
  std::stringstream stream_temperature, stream_wind;
  std::string error = "[ERR] Usage: setweather <cover> ";
  error += "<precipitation> <temperature> <wind>\n";
  
  HTMLWriterEnvironment environment_html("Environment.html");
 
 // EnvironmentalCondition ec(game.getEnvironmentalCondition());
  
  if(parameters.size() != 4)
  {
    output_engine.print(error);
  }
  else
  {
    stream_cover << parameters.at(0);
    stream_precipitation << parameters.at(1);
    stream_temperature << parameters.at(2);
    stream_wind << parameters.at(3);
    
    stream_cover >> sky_cover;
    stream_precipitation >> precipitation;
    stream_temperature >> temperature;
    stream_wind >> wind;
    
    if(stream_cover.eof() != 1 || stream_precipitation.eof() != 1
                               || stream_temperature.eof() != 1 
                               || stream_wind.eof() != 1)
    {
      output_engine.print("[ERR] Wrong parameter.\n");
      //output_engine.print(error);
    }
    else
    {
      if(temperature < 10 || temperature > 35)
      {
        output_engine.print("[ERR] Usage: temperature values 10 - 35\n");
      }
      else if( sky_cover < 0 || sky_cover > 3)
      {
        output_engine.print("[ERR] Usage: cover values 0-3\n");
      }
      else if( wind < 0 || wind > 3)
      {
        output_engine.print("[ERR] Usage: wind values 0-3\n");
      }
      else if( precipitation < 0 || precipitation > 3)
      {
        output_engine.print("[ERR] Usage: precipitation values 0-3\n");
      }
      else
      {
        game.getEnvironmentalCondition().setWind(static_cast<EnvironmentalCondition::Rank>(wind));
        game.getEnvironmentalCondition().setSkyCover(static_cast<EnvironmentalCondition::Cover>(sky_cover));
        game.getEnvironmentalCondition().setTemperature(temperature);
        game.getEnvironmentalCondition().setPrecipitation(static_cast<EnvironmentalCondition::Rank>(precipitation));
        game.setSetWeather(true);
        environment_html.writeFile(game.getEnvironmentalCondition());
      }   
    }
   
  }
  
  
  
  return 0;
}
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
