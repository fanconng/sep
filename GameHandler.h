//------------------------------------------------------------------------------
// GameHandler.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef GAMEHANDLER_H_INCLUDED
#define GAMEHANDLER_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include "Command.h"
#include "EnvironmentalCondition.h"
#include "Satisfaction.h"

//------------------------------------------------------------------------------
// GameHandler Class 
// This class represents the controller of MVC
// The class also holds the model part of the MVC
class GameHandler
{
  //----------------------------------------------------------------------------
  // Model of MVC
  // The model part of the MVC is represented by this class' members.
  private:
    EnvironmentalCondition environmental_condition_;
    int lemons_;
    int sugar_;
    int cash_;
    int recipe_lemons_;
    int recipe_sugar_;
    int recipe_water_;
    int delta_;
    int income_;
    int expense_;
    float price_lemon_;
    float price_sugar_;
    int price_lemonade_;
    int customer_;
    int produced_lemonade_;
    bool running_;
    bool set_weather_;
    Satisfaction satisfaction_;
    
  public:
    //--------------------------------------------------------------------------
    // Constructors
    GameHandler();
    GameHandler(EnvironmentalCondition& environmental_condition,
                int lemons,
                int sugar,
                int cash,
                int recipe_lemons,
                int recipe_sugar,
                int recipe_water,
                int income,
                int expense,
                float price_lemon,
                float price_sugar,
                int price_lemonade,
                Satisfaction& satisfaction,
                std::vector<std::shared_ptr<Command>> commands);
    //--------------------------------------------------------------------------
    // Destructor
    ~GameHandler();
    
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    GameHandler(const GameHandler& original);
    GameHandler operator= (GameHandler const& original);
    
    
    //--------------------------------------------------------------------------
    // Setter
    void setLemons(int lemons);
    void setSugar(int sugar);
    void setCash(int cash);
    void setRecipeLemons(int recipe_lemons);
    void setRecipeSugar(int recipe_sugar);
    void setRecipeWater(int recipe_water);
    void setIncome(int income);
    void setExpense(int expense);
    void setPriceLemons(int price_lemon);
    void setPriceSugar(int price_sugar);
    void setRunning(bool running);
    void setCustomer(int customer);
    void setProducedLemonade(int produced_lemonade);
    void setPriceLemonade(int price_lemonade);
    void setSetWeather(bool setweather);
    void setSatisfaction(Satisfaction& satisfaction);
    
    //--------------------------------------------------------------------------
    // Getter
    int getLemons();
    int getSugar();
    int getCash();
    int getRecipeLemons();
    int getRecipeSugar();
    int getRecipeWater();
    int getIncome();
    int getExpense();
    int getPriceLemons();
    int getPriceSugar();
    bool getRunning();
    EnvironmentalCondition& getEnvironmentalCondition();
    int getCustomer();
    int getProducedLemonade();
    int getPriceLemonade();
    bool getSetWeather();
    Satisfaction& getSatisfaction();
    
    //--------------------------------------------------------------------------
    // Controller
    // This method will execute the typed in command if possible
    // Typed in string will be split into command and parameters, the command 
    // then gets compared to the vector of available commands
    // @param prompt_input the users typed in input
    // @param commands the list of all available commands
    void command_execute(std::string prompt_input, 
                         std::vector<std::shared_ptr<Command>> commands);
	
	
};

#endif //GAMEHANDLER_H_INCLUDED
