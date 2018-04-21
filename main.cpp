#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "HTMLWriter.h"
#include "HTMLWriterBalance.h"
#include "HTMLWriterEnvironment.h"
#include "EnvironmentalEngine.h"
#include "EnvironmentalCondition.h"
#include "GameHandler.h"
#include "Command.h"
#include "Quit.h"
#include "Save.h"
#include "Load.h"
#include "Echo.h"
#include "Recipe.h"
#include "Quote.h"
#include "Produce.h"
#include "Balance.h"
#include "Buy.h"
#include "Setweather.h"
#include "Forecast.h"
#include "Play.h"
#include "GameView.h"
#include "Satisfaction.h"


int main(int argc, char *argv[])
{
  std::string usage_error = "[ERR] Wrong usage: ";
  usage_error += "./basic <price_lemonade> <price_lemon> <price_sugar>\n";
  GameView output_engine;
  
  try
  {
  if(argc != 4)
  {
    output_engine.print(usage_error);
    return 2;
  }
  else
  {
    for(int i = 1; i < 4; ++i)
    {
      std::stringstream test_stream;
      int input_test;
      test_stream << argv[i];
      test_stream >> input_test;
      if(test_stream.eof() != 1)
      {
        output_engine.print(usage_error);
      }
    }

    
    Quit *quit_ptr = new Quit;
    quit_ptr->setName("quit");
    std::shared_ptr<Quit> command_quit (quit_ptr);

    Quote *quote_ptr = new Quote;
    quote_ptr->setName("quote");
    std::shared_ptr<Quote> command_quote (quote_ptr);
 
    Recipe *recipe_ptr = new Recipe;
    recipe_ptr->setName("recipe");
    std::shared_ptr<Recipe> command_recipe (recipe_ptr);

    Balance *balance_ptr = new Balance;
    balance_ptr->setName("balance");
    std::shared_ptr<Balance> command_balance (balance_ptr);

    Echo *echo_ptr = new Echo;
    echo_ptr->setName("echo");
    std::shared_ptr<Echo> command_echo (echo_ptr);
    
    Save *save_ptr = new Save;
    save_ptr->setName("save");
    std::shared_ptr<Save> command_save (save_ptr);
 
    Load *load_ptr = new Load;
    load_ptr->setName("load");
    std::shared_ptr<Load> command_load (load_ptr);
    
    Buy *buy_ptr = new Buy;
    buy_ptr->setName("buy");
    std::shared_ptr<Buy> command_buy (buy_ptr);
    
    Play *play_ptr = new Play;
    play_ptr->setName("play");
    std::shared_ptr<Play> command_play (play_ptr);
    
    Setweather *setweather_ptr = new Setweather;
    setweather_ptr->setName("setweather");
    std::shared_ptr<Setweather> command_setweather (setweather_ptr);
 
    Produce *produce_ptr = new Produce;
    produce_ptr->setName("produce");
    std::shared_ptr<Produce> command_produce (produce_ptr);
 
    Forecast *forecast_ptr = new Forecast;
    forecast_ptr->setName("forecast");
    std::shared_ptr<Forecast> command_forecast (forecast_ptr);

    std::vector<std::shared_ptr<Command>> commands = {command_quit, 
                                                      command_quote,
                                                      command_recipe, 
                                                      command_balance, 
                                                      command_echo,
                                                      command_load,
                                                      command_save,
                                                      command_buy,
                                                      command_play,
                                                      command_setweather,
                                                      command_produce,
                                                      command_forecast};
    EnvironmentalCondition* ec;
    EnvironmentalEngine test_engine = EnvironmentalEngine();
    Satisfaction satisfaction_engine;
    ec = test_engine.createCondition().get();
    GameHandler game(*ec, 
                     100, 
                     100, 
                     5000, 
                     6, 
                     6, 
                     88, 
                     0, 
                     0, 
                     std::stoi(argv[2]), 
                     std::stoi(argv[3]), 
                     std::stoi(argv[1]), 
                     satisfaction_engine,
                     commands);
    GameView view_engine;
    std::string prompt_input;
    
    while(game.getRunning())
    {
      view_engine.print_prompt();
      prompt_input = view_engine.read();
    
      // Leading whitespaces will be trimmed of the passed command
      prompt_input.erase(0, prompt_input.find_first_not_of(" "));
      game.command_execute(prompt_input, commands);

    }
    }
  }
  catch(const std::bad_alloc& e)
  {
    output_engine.print("[ERR] Out of memory.\n");
    throw std::bad_alloc(); //needed?
    return 1;
  }
  
  /*try
  {
    test_throw();
  }
    catch(const std::bad_alloc& e)
  {
    output_engine.print("[ERR] Out of memory.\n");
    throw std::bad_alloc();
    return 1;
  }*/
  
  //----------------------------------------------------------------------------
  
  
  return 0;
};
