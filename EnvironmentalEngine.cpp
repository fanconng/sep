//------------------------------------------------------------------------------
// EnvironmentalEngine.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include <cstdlib>
#include <ctime>
#include <memory>


//------------------------------------------------------------------------------
EnvironmentalEngine::EnvironmentalEngine()
{
  // getting a seed for rand()
  srand(time(NULL));
}

//------------------------------------------------------------------------------
EnvironmentalEngine::~EnvironmentalEngine()
{
}


EnvironmentalEngine::EnvironmentalEngine(const EnvironmentalEngine& original)
{
}

//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
EnvironmentalEngine EnvironmentalEngine::operator= (const EnvironmentalEngine& original)
{
  return *this;
}

//------------------------------------------------------------------------------
std::shared_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition()
{

  // variable allocation
  EnvironmentalCondition::Cover sky_cover;
  EnvironmentalCondition::Rank precipitation;
  float temperature;
  EnvironmentalCondition::Rank wind;

  // getting random values
  sky_cover = static_cast<EnvironmentalCondition::Cover>(rand() % 4);
  precipitation = static_cast<EnvironmentalCondition::Rank>(rand() % 4);
  temperature = ((rand() % 2500) + 1000);
  temperature = static_cast<float> (temperature / 100);
  wind = static_cast<EnvironmentalCondition::Rank>(rand() % 4);
  
  
  // creating pointer for return value
  std::shared_ptr<EnvironmentalCondition> output(new EnvironmentalCondition
                                                (sky_cover, 
                                                 precipitation, 
                                                 temperature, 
                                                 wind));
  
  return output;
}

//------------------------------------------------------------------------------
void EnvironmentalEngine::changeCondition(EnvironmentalCondition& current_condition)
{
  EnvironmentalCondition::Rank current_wind = current_condition.getWind();
  EnvironmentalCondition::Rank current_precipitation = current_condition.getPrecipitation();
  EnvironmentalCondition::Cover current_sky_cover = current_condition.getSkyCover();
  float current_temperature = current_condition.getTemperature();
  
  //----------------------------------------------------------------------------
  if(current_wind == EnvironmentalCondition::NONE)
  {
    int wind;
    int wind_change;
    
    wind_change = rand() % 2;
    wind = static_cast<int>(current_wind) + wind_change;
    current_wind = static_cast<EnvironmentalCondition::Rank>(wind);
    
  }
  else if(current_wind == EnvironmentalCondition::HIGH)
  {
    int wind;
    int wind_change;
    
    wind_change = rand() % 2;
    wind = static_cast<int>(current_wind) - wind_change;
    current_wind = static_cast<EnvironmentalCondition::Rank>(wind);
    
  }
  else
  {
    int wind;
    int wind_change;
    
    wind_change = (rand() % 3) - 1;
    wind = static_cast<int>(current_wind) + wind_change;
    current_wind = static_cast<EnvironmentalCondition::Rank>(wind);
  }
  
  //----------------------------------------------------------------------------
  if(current_precipitation == EnvironmentalCondition::NONE)
  {
    int precipitation;
    int precipitation_change;
    
    precipitation_change = rand() % 2;
    precipitation = static_cast<int>(current_precipitation) + precipitation_change;
    current_precipitation = static_cast<EnvironmentalCondition::Rank>(precipitation);
    
    
  }
  else if(current_precipitation == EnvironmentalCondition::HIGH)
  {
    int precipitation;
    int precipitation_change;
    
    precipitation_change = rand() % 2;
    precipitation = static_cast<int>(current_precipitation) - precipitation_change;
    current_precipitation = static_cast<EnvironmentalCondition::Rank>(precipitation);
    
    
  }
  else
  {
    int precipitation;
    int precipitation_change;
    
    precipitation_change = (rand() % 3) - 1;
    precipitation = static_cast<int>(current_precipitation) + precipitation_change;
    current_precipitation = static_cast<EnvironmentalCondition::Rank>(precipitation);
    
    
  }
  
  //----------------------------------------------------------------------------
  if(current_sky_cover == EnvironmentalCondition::SUNNY)
  {
    int sky_cover;
    int sky_cover_change;
    
    sky_cover_change = rand() % 2;
    sky_cover = static_cast<int>(current_sky_cover) + sky_cover_change;
    current_sky_cover = static_cast<EnvironmentalCondition::Cover>(sky_cover);
    
  }
  else if(current_sky_cover == EnvironmentalCondition::VERY_OVERCAST)
  {
    int sky_cover;
    int sky_cover_change;
    
    sky_cover_change = rand() % 2;
    sky_cover = static_cast<int>(current_sky_cover) - sky_cover_change;
    current_sky_cover = static_cast<EnvironmentalCondition::Cover>(sky_cover);
  }
  else
  {
    int sky_cover;
    int sky_cover_change;
    
    sky_cover_change = (rand() % 3) - 1;
    sky_cover = static_cast<int>(current_sky_cover) + sky_cover_change;
    current_sky_cover = static_cast<EnvironmentalCondition::Cover>(sky_cover);
    
  }
  
  //----------------------------------------------------------------------------
  float temperature_change;
  
  temperature_change = ((rand() % 1000) - 500) / 100;
  current_temperature =+ temperature_change;
  
  if(current_temperature <= 10.0f)
  {
    current_temperature = 10.0f;
    
  }
  else if(current_temperature >= 35.0f)
  {
    current_temperature = 35.0f;
    
  }
  
  
  current_condition.setWind(current_wind);
  current_condition.setPrecipitation(current_precipitation);
  current_condition.setSkyCover(current_sky_cover);
  current_condition.setTemperature(current_temperature);
  
}














