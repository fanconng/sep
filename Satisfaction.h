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

#ifndef SATISFACTION_H_INCLUDED
#define SATISFACTION_H_INCLUDED


class GameHandler;

//------------------------------------------------------------------------------
// Satisfaction Class
// Used for another factor of customer count which will change depending on
// whether enough customers could be served in one gameround

class Satisfaction
{
  private:
    int satisfaction_;
    int max_satisfaction_;
    int min_satisfaction_;
    int satisfaction_change_value_;
    
  public:
    //--------------------------------------------------------------------------
    //Constructor & Destructor
    Satisfaction();
    ~Satisfaction();
    
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    Satisfaction(const Satisfaction& original);
    Satisfaction operator= (Satisfaction const& original);
    
    //--------------------------------------------------------------------------
    //Setter
    void setSatisfaction(int satisfaction);
    void setMaxSatisfaction(int max_satisfaction);
    void setMinSatisfaction(int min_satisfaction);
    void setSatisfaction_change_value(int satisfaction_change_value);
    
    //--------------------------------------------------------------------------
    //Getter
    int getSatisfaction();
    int getMaxSatisfaction();
    int getMinSatisfaction();
    int getSatisfactionChangeValue();
    
    //--------------------------------------------------------------------------
    void satisfactionChanging(GameHandler& current_round);
    

};

#endif
