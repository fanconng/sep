//------------------------------------------------------------------------------
// GameHandler.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//


#include "Command.h"
#include "Quit.h"
#include "GameView.h"
#include "GameHandler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//------------------------------------------------------------------------------
GameHandler::GameHandler()
{
}


GameHandler::GameHandler(EnvironmentalCondition& environmental_condition,
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
                         std::vector<std::shared_ptr<Command>> commands)
  : environmental_condition_(environmental_condition), lemons_(lemons), 
    sugar_(sugar), cash_(cash), recipe_lemons_(recipe_lemons),
    recipe_sugar_(recipe_sugar), recipe_water_(recipe_water),
    income_(income), expense_(expense),
    price_lemon_(price_lemon), price_sugar_(price_sugar), 
    price_lemonade_(price_lemonade),
    set_weather_(0),
    satisfaction_(satisfaction)
{
  
}

//------------------------------------------------------------------------------
GameHandler::~GameHandler()
{
}


GameHandler::GameHandler(const GameHandler& original)
{
  lemons_ = original.lemons_;
  sugar_ = original.sugar_;
  cash_ = original.cash_;
  recipe_lemons_ = original.recipe_lemons_;
  recipe_sugar_ = original.recipe_sugar_;
  recipe_water_ = original.recipe_water_;
  delta_ = original.delta_;
  income_ = original.income_;
  expense_ = original.expense_;
  price_lemon_ = original.price_lemon_;
  price_sugar_ = original.price_sugar_;
  price_lemonade_ = original.price_lemonade_;
  customer_ = original.customer_;
  produced_lemonade_ = original.produced_lemonade_;
  running_ = original.running_;
  set_weather_ = original.set_weather_;
  satisfaction_ = original.satisfaction_;
}

//------------------------------------------------------------------------------
GameHandler GameHandler::operator= (const GameHandler& original)
{
  lemons_ = original.lemons_;
  sugar_ = original.sugar_;
  cash_ = original.cash_;
  recipe_lemons_ = original.recipe_lemons_;
  recipe_sugar_ = original.recipe_sugar_;
  recipe_water_ = original.recipe_water_;
  delta_ = original.delta_;
  income_ = original.income_;
  expense_ = original.expense_;
  price_lemon_ = original.price_lemon_;
  price_sugar_ = original.price_sugar_;
  price_lemonade_ = original.price_lemonade_;
  customer_ = original.customer_;
  produced_lemonade_ = original.produced_lemonade_;
  running_ = original.running_;
  set_weather_ = original.set_weather_;
  satisfaction_ = original.satisfaction_;
  return *this;
}


void GameHandler::command_execute(std::string prompt_input, 
                                  std::vector<std::shared_ptr<Command>> commands)
{
  GameView output_engine;
  
  std::string command_input, temp;
  std::vector<std::string> args;
  std::stringstream input(prompt_input);
  
  bool unknown_command = true;
  
  int first_argument = 0;
  
  // Users input will be split into command and parameters
  while(input >> temp)
  {
    if(first_argument == 0)
    {
      command_input = temp;
      first_argument = 1;
    }
    else
    {
      args.push_back(temp);
    }
  }
  
  std::transform(command_input.begin(), 
                 command_input.end(), 
                 command_input.begin(),
                 ::tolower);
  // The command gets compared to the vector of available commands
  // If there is a match the command will then be executed
  for(auto const& command : commands)
  {
    if(command.get()->getName().compare(command_input) == 0)
    {
      command.get()->execute(*this, args);
      unknown_command = false;
      break;
    }
  }
  if(unknown_command && prompt_input != "")
  {
    output_engine.print("[ERR] Unknown command.\n");
  }
  


}

void GameHandler::setLemons(int lemons)
{
  this->lemons_ = lemons;
}
void GameHandler::setSugar(int sugar)
{
  this->sugar_ = sugar;
}
void GameHandler::setCash(int cash)
{
  this->cash_ = cash;
}
void GameHandler::setRecipeLemons(int recipe_lemons)
{
  this->recipe_lemons_ = recipe_lemons;
}
void GameHandler::setRecipeSugar(int recipe_sugar)
{
  this->recipe_sugar_ = recipe_sugar;
}
void GameHandler::setRecipeWater(int recipe_water)
{
  this->recipe_water_ = recipe_water;
}
void GameHandler::setIncome(int income)
{
  this->income_ = income;
}
void GameHandler::setExpense(int expense)
{
  this->expense_ = expense;
}
void GameHandler::setPriceLemons(int price_lemon)
{
  this->price_lemon_ = price_lemon;
}
void GameHandler::setPriceSugar(int price_sugar)
{
  this->price_sugar_ = price_sugar;
}
void GameHandler::setRunning(bool running)
{
  this->running_ = running;
}
void GameHandler::setCustomer(int customer)
{
  customer_ = customer;
}
void GameHandler::setProducedLemonade(int produced_lemonade)
{
  produced_lemonade_ = produced_lemonade;
}
void GameHandler::setPriceLemonade(int price_lemonade)
{
  price_lemonade_ = price_lemonade;
}
void GameHandler::setSetWeather(bool set_weather)
{
  set_weather_ = set_weather;
}
void GameHandler::setSatisfaction(Satisfaction& satisfaction)
{
  //satisfaction_ = satisfaction;
}


int GameHandler::getLemons()
{
  return lemons_;
}
int GameHandler::getSugar()
{
  return sugar_;
}
int GameHandler::getCash()
{
  return cash_;
}
int GameHandler::getRecipeLemons()
{
  return recipe_lemons_;
}
int GameHandler::getRecipeSugar()
{
  return recipe_sugar_;
}
int GameHandler::getRecipeWater()
{
  return recipe_water_;
}
int GameHandler::getIncome()
{
  return income_;
}
int GameHandler::getExpense()
{
  return expense_;
}
int GameHandler::getPriceLemons()
{
  return price_lemon_;
}
int GameHandler::getPriceSugar()
{
  return price_sugar_;
}
bool GameHandler::getRunning()
{
  return running_;
}
EnvironmentalCondition& GameHandler::getEnvironmentalCondition()
{
  return environmental_condition_;
}
int GameHandler::getCustomer()
{
  return customer_;
}
int GameHandler::getProducedLemonade()
{
  return produced_lemonade_;
}
int GameHandler::getPriceLemonade()
{
  return price_lemonade_;
}
bool GameHandler::getSetWeather()
{
  return set_weather_;
}
Satisfaction& GameHandler::getSatisfaction()
{
  return satisfaction_;
}
