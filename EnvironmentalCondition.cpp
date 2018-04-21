//------------------------------------------------------------------------------
// EnvironmentalCondition.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "EnvironmentalCondition.h"
//------------------------------------------------------------------------------
//Constructors
EnvironmentalCondition::EnvironmentalCondition()
{
}

//------------------------------------------------------------------------------
EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover, 
                                               Rank precipitation, 
                                               float temperature, 
                                               Rank wind)
  : sky_cover_(sky_cover), 
    precipitation_(precipitation), 
    temperature_(temperature), 
    wind_(wind)
{
}

//------------------------------------------------------------------------------
// Destructor
EnvironmentalCondition::~EnvironmentalCondition()
{
}


//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
EnvironmentalCondition::EnvironmentalCondition(const EnvironmentalCondition& original)
{
  sky_cover_ = original.sky_cover_;
  wind_ = original.wind_;
  temperature_ = original.temperature_;
  precipitation_ = original.precipitation_;
}

//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
EnvironmentalCondition EnvironmentalCondition::operator= (const EnvironmentalCondition& original)
{
  sky_cover_ = original.sky_cover_;
  wind_ = original.wind_;
  temperature_ = original.temperature_;
  precipitation_ = original.precipitation_;
  return *this;
}


//------------------------------------------------------------------------------
// Setter Methods
void EnvironmentalCondition::setSkyCover(Cover cover)
{
  sky_cover_ = cover;
}

//------------------------------------------------------------------------------
void EnvironmentalCondition::setPrecipitation(Rank rank)
{
  precipitation_ = rank;
}

//------------------------------------------------------------------------------
void EnvironmentalCondition::setTemperature(float temperature)
{
  if(temperature > 10 && temperature < 35)
  {
    temperature_ = temperature;
  }
}

//------------------------------------------------------------------------------
void EnvironmentalCondition::setWind(Rank rank)
{
  wind_ = rank;
}



//------------------------------------------------------------------------------
// Getter Methods
EnvironmentalCondition::Cover EnvironmentalCondition::getSkyCover()
{
  return sky_cover_;
}

//------------------------------------------------------------------------------
EnvironmentalCondition::Rank EnvironmentalCondition::getPrecipitation()
{
  return precipitation_;
}

//------------------------------------------------------------------------------
float EnvironmentalCondition::getTemperature()
{
  return temperature_;
}

//------------------------------------------------------------------------------
EnvironmentalCondition::Rank EnvironmentalCondition::getWind()
{
  return wind_;
}



//------------------------------------------------------------------------------
// Boolean Methods
bool EnvironmentalCondition::isItHot()
{
  bool output;
  
  if(this->getSkyCover() == SUNNY)
  {
    if(this->getTemperature() > 26.6f)
    {
      output = true;
    }
  }
  else
  {
    output = false;
  }

  return output;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItRainy()
{
  bool output = false;
  EnvironmentalCondition::Rank precipitation = this->getPrecipitation();
  EnvironmentalCondition::Cover sky_cover = this->getSkyCover();
  if(precipitation == MEDIUM || precipitation == HIGH)
  {
    if(sky_cover == OVERCAST || sky_cover == VERY_OVERCAST)
    {
      output = true;
    }
  }

  return output;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItStormy()
{
  bool output;
  EnvironmentalCondition::Rank wind = this->getWind();
  EnvironmentalCondition::Cover sky_cover = this->getSkyCover();
  if(wind == MEDIUM || wind == HIGH)
  {
    if(sky_cover == OVERCAST || sky_cover == VERY_OVERCAST)
    {
      output = true;
    }
  }
  else
  {
    output = false;
  }

  return output;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItCloudy()
{
  bool output;
  if(sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST)
  {
    output = true;
  }
  else
  {
    output = false;
  }
  
  return output;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItCold()
{
  bool output;
  if(temperature_ < 18.7f)
  {
    output = true;
  }
  else
  {
    output = false;
  }
  
  return output;
}
