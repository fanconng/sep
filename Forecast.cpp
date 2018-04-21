//------------------------------------------------------------------------------
// Quit.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Forecast.h"
#include "GameView.h"


//------------------------------------------------------------------------------
Forecast::Forecast()
{
}

//------------------------------------------------------------------------------
Forecast::Forecast(std::string name) : Command(name)
{
}


//------------------------------------------------------------------------------
Forecast::~Forecast()
{
}

//------------------------------------------------------------------------------
int Forecast::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  EnvironmentalCondition::Cover sky_cover;
  EnvironmentalCondition::Rank  precipitation;
  EnvironmentalCondition::Rank  wind;
  float temperature;
  std::string cover_output, wind_output, precipitation_output;
  std::string string_low, string_high, temperature_output;
  
  if(parameters.size() != 0)
  {
    output_engine.print("[ERR] Usage: forecast\n");
  }
  else
  {
    sky_cover = game.getEnvironmentalCondition().getSkyCover();
    wind = game.getEnvironmentalCondition().getWind();
    precipitation = game.getEnvironmentalCondition().getPrecipitation();
    temperature = game.getEnvironmentalCondition().getTemperature();
    
    output_engine.print("weather forecast:\nSky Cover:\t");
  
    switch(sky_cover)
    {
      case EnvironmentalCondition::Cover::SUNNY : 
        output_engine.print("Sunny or cloudy\n");
        break;
      case EnvironmentalCondition::Cover::CLOUDY : 
        output_engine.print("Sunny, cloudy or overcast\n");
        break;
      case EnvironmentalCondition::Cover::OVERCAST : 
        output_engine.print("cloudy, overcast or very overcast\n");
        break;
      case EnvironmentalCondition::Cover::VERY_OVERCAST : 
        output_engine.print("overcast or very overcast\n");
        break;
  }
  
  output_engine.print("Precipitation:\t");
  switch(precipitation)
  {
    case EnvironmentalCondition::Rank::NONE : 
      output_engine.print("None or low\n");
      break;
    case EnvironmentalCondition::Rank::LOW : 
      output_engine.print("None, low or medium\n");
      break;
    case EnvironmentalCondition::Rank::MEDIUM : 
      output_engine.print("Low, medium or high\n");
      break;
    case EnvironmentalCondition::Rank::HIGH : 
      output_engine.print("Medium or high\n");
      break;
  }
  
  output_engine.print("Wind:\t\t");
  switch(wind)
  {
    case EnvironmentalCondition::Rank::NONE : 
      output_engine.print("None or low\n");
      break;
    case EnvironmentalCondition::Rank::LOW : 
      output_engine.print("None, low or medium\n");
      break;
    case EnvironmentalCondition::Rank::MEDIUM : 
      output_engine.print("Low, medium or high\n");
      break;
    case EnvironmentalCondition::Rank::HIGH : 
      output_engine.print("Medium or high\n");
      break;
  }
  output_engine.print("Temperature:\t");

  float temperature_low = temperature - 5;
  float temperature_high = temperature + 5;
  if(temperature_low < 10.0f)
  {
    temperature_low = 10.0f;
  }
  if(temperature_high > 35.0f)
  {
    temperature_high = 35.0f;
  }
  
  
  string_low = std::to_string(temperature_low);
  string_low.resize(5);
  string_high = std::to_string(temperature_high);
  string_high.resize(5);
  temperature_output += "Between " + string_low;
  temperature_output += " and " + string_high + "\n";
  output_engine.print(temperature_output);
  }
  return 0;
}
