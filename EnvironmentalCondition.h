//------------------------------------------------------------------------------
// EnvironmentalCondition.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef ENVIRONMENTALCONDITION_H_INCLUDED
#define ENVIRONMENTALCONDITION_H_INCLUDED



//----------------------------------------------------------------------------
// EnvironmentalCondition Class
// class for description of the environment
// contains enums for description, getter, setter and boolean methods
//
class EnvironmentalCondition
{
    
  public:
    //------------------------------------------------------------------------
    // enum Cover
    // contains enums for describing the weather 
    //
    enum Cover {SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST};
    //------------------------------------------------------------------------
    // enum Rank
    // contains enums for different ranks
    //
    enum Rank  {NONE, LOW, MEDIUM, HIGH};
    
    //------------------------------------------------------------------------
    // Constructors
    //
    EnvironmentalCondition();
    EnvironmentalCondition(Cover sky_cover,
                           Rank precipitation, 
                           float temperature, 
                           Rank wind);
    //------------------------------------------------------------------------
    // Destructor
    //    
    ~EnvironmentalCondition();
 
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    EnvironmentalCondition(const EnvironmentalCondition& original);
    EnvironmentalCondition operator= (EnvironmentalCondition const& original);
    
    
    //------------------------------------------------------------------------
    // isItHot - boolean method
    // checks if sky_cover_ is SUNNY and temperature_
    // if temperature_ is above 26.6
    // @return Returns boolean value depending on whether above criteria is met
    //
    bool isItHot();
	
	EnvironmentalCondition object1 = new EnvironmentalCondition(2,
	
	object1->isItHot();
    //------------------------------------------------------------------------
    // isItRainy - boolean method
    // checks if sky_cover_ is OVERCAST or VERY_OVERCAST and 
    // if precipitation_ is MEDIUM or HIGH
    // @return Returns boolean value depending on whether above criteria is met
    //
    bool isItRainy();
    //------------------------------------------------------------------------
    // isItStormy - boolean method
    // checks if sky_cover_ is OVERCAST or VERY_OVERCAST and 
    // if wind_ is MEDIUM or HIGH
    // @return Returns boolean value depending on whether above criteria is met
    //
    bool isItStormy();
    //------------------------------------------------------------------------
    // isItCloudy - boolean method
    // checks if sky_cover_ is OVERCAST or VERY_OVERCAST 
    // @return Returns boolean value depending on whether above criteria is met
    //
    bool isItCloudy();
    //------------------------------------------------------------------------
    // isItCold - boolean method
    // checks if temperature_ is less than 18.7 (lower third from temperature
    // range)
    // @return Returns boolean value depending on whether above criteria is met
    //
    bool isItCold();
    
    //------------------------------------------------------------------------
    // Setter Methods
    //
    void setSkyCover(Cover cover);
    void setPrecipitation(Rank rank);
    void setTemperature(float temperature);
    void setWind(Rank rank);
    
    //------------------------------------------------------------------------
    // Getter Methods
    //
    Cover getSkyCover();
    Rank  getPrecipitation();
    float getTemperature();
    Rank getWind();
  
  
  private:
    //------------------------------------------------------------------------
    // enum Variable presenting the sky_cover
    //
    Cover sky_cover_;
    //------------------------------------------------------------------------
    // enum Variable for level of precipitation
    //
    Rank precipitation_;
    //------------------------------------------------------------------------
    // Variable for temperature
    //
    float temperature_;
    //------------------------------------------------------------------------
    // enum Variable presenting wind speed
    //
    Rank wind_;    
};

#endif // ENVIRONMENTALCONDITION_H_INCLUDED

