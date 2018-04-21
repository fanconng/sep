//------------------------------------------------------------------------------
// EnvironmentalEngine.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Satisfaction.h"
#include "GameHandler.h"

//------------------------------------------------------------------------------
Satisfaction::Satisfaction() : satisfaction_(100),
                               max_satisfaction_(110),
                               min_satisfaction_(10),
                               satisfaction_change_value_(10)
{
}

//------------------------------------------------------------------------------
Satisfaction::~Satisfaction()
{
}

//------------------------------------------------------------------------------
Satisfaction::Satisfaction(const Satisfaction& original)
{
  satisfaction_ = original.satisfaction_;
  max_satisfaction_ = original.max_satisfaction_;
  min_satisfaction_ = original.min_satisfaction_;
  satisfaction_change_value_ = original.satisfaction_change_value_;
}

//------------------------------------------------------------------------------
Satisfaction Satisfaction::operator= (const Satisfaction& original)
{
  satisfaction_ = original.satisfaction_;
  max_satisfaction_ = original.max_satisfaction_;
  min_satisfaction_ = original.min_satisfaction_;
  satisfaction_change_value_ = original.satisfaction_change_value_;
  return *this;
}

//------------------------------------------------------------------------------
void Satisfaction::setSatisfaction(int satisfaction)
{
  satisfaction_ = satisfaction;
}
void Satisfaction::setMaxSatisfaction(int max_satisfaction)
{
  max_satisfaction_ = max_satisfaction;
}
void Satisfaction::setMinSatisfaction(int min_satisfaction)
{
  min_satisfaction_ = min_satisfaction;
}
void Satisfaction::setSatisfaction_change_value(int satisfaction_change_value)
{
  satisfaction_change_value_ = satisfaction_change_value;
}

//------------------------------------------------------------------------------
int Satisfaction::getSatisfaction()
{
  return satisfaction_;
}
int Satisfaction::getMaxSatisfaction()
{
  return max_satisfaction_;
}
int Satisfaction::getMinSatisfaction()
{
  return min_satisfaction_;
}
int Satisfaction::getSatisfactionChangeValue()
{
  return satisfaction_change_value_;
}

//------------------------------------------------------------------------------
void Satisfaction::satisfactionChanging(GameHandler& current_round)
{
  if(current_round.getCustomer() <= current_round.getProducedLemonade())
  {
    if(satisfaction_ < max_satisfaction_)
    {
      satisfaction_ =+ satisfaction_change_value_;
    }
  }
  else
  {
    if(satisfaction_ > min_satisfaction_)
    {
      satisfaction_ =- satisfaction_change_value_;
    }
  }
}









