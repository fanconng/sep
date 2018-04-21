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

#ifndef ENVIRONMENTALENGINE_H_INCLUDED
#define ENVIRONMENTALENGINE_H_INCLUDED
#include "EnvironmentalCondition.h"
#include <memory>


//------------------------------------------------------------------------------
// EnvironmentalEngine Class
// Engine class for random creation of weather conditions
//
class EnvironmentalEngine 
{

  public: 
    //--------------------------------------------------------------------------
    // Constructor
    EnvironmentalEngine();
    
    //--------------------------------------------------------------------------
    // Destructor   
    ~EnvironmentalEngine();
    
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    EnvironmentalEngine(const EnvironmentalEngine& original);
    EnvironmentalEngine operator= (EnvironmentalEngine const& original);
    
    
    //--------------------------------------------------------------------------
    // createCondition
    // allocates the different parameters and randomly assignes them
    // creates pointer of EnvironmentalCondition for return value
    // @return Returns a smart pointer for random weather conditions
    //
    std::shared_ptr<EnvironmentalCondition> createCondition();
    
    //--------------------------------------------------------------------------
    // changeCondition
    // changes the current weather in a realistic way
    // wind, precipitation and sky_cover can only change by 1 level
    // temperature has to be in a range of +- 5 degree
    // @input current_condition This represents the current weather, which may 
    //                          be changed
    //
    void changeCondition(EnvironmentalCondition& current_condition);


};

#endif // ENVIRONMENTALENGINE_H_INCLUDED
