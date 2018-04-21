//------------------------------------------------------------------------------
// Buy.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Buy.h"
#include "GameView.h"
#include <sstream>
#include "HTMLWriterBalance.h"

//------------------------------------------------------------------------------
Buy::Buy()
{
}

//------------------------------------------------------------------------------
Buy::Buy(std::string name) : Command(name)
{
}



//------------------------------------------------------------------------------
Buy::~Buy()
{
}

//------------------------------------------------------------------------------
int Buy::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  GameView output_engine;
  
  int lemon_bought, sugar_bought;
  std::string output_string;
  std::stringstream stream_lemon, stream_sugar;
  int lemonPrice, sugarPrice, cash;
  int totalLemons, totalSugar;
  std::string usage_error = "[ERR] Usage: buy [lemon] [sugar]\n";
  
  HTMLWriterBalance balance_html("Balance.html");
  
  lemonPrice = game.getPriceLemons();
  sugarPrice = game.getPriceSugar();
  cash = game.getCash();
  
  if(parameters.size() != 2)
  {
    output_engine.print(usage_error);
  }
  else
  {
    stream_lemon << parameters.at(0);
    stream_sugar << parameters.at(1);
    stream_lemon >> lemon_bought;
    stream_sugar >> sugar_bought;
    
    
    if(stream_lemon.eof() != 1 ||
            stream_sugar.eof() != 1)
     {
        output_engine.print("[ERR] Wrong parameter.\n");
        output_engine.print(usage_error);
      }
    else 
    {
      if(cash < ((lemon_bought * lemonPrice) + (sugar_bought * sugarPrice)))
      {
        output_engine.print("[WARN] Not enough money. I buy what I can.\n");
      }
      while(cash < ((lemon_bought * lemonPrice) + (sugar_bought * sugarPrice)))
        {
        if(lemon_bought > 0)
          {
          lemon_bought--;
          }
          if(sugar_bought > 0)
          {
          sugar_bought--;  
          }      
        }  
      output_string +="Bought:\n";
      output_string += "L: " + std::to_string(lemon_bought) + "\n";
      output_string += "S: " + std::to_string(sugar_bought) + "\n";
      output_engine.print(output_string);
      
      cash = cash - ((lemon_bought * lemonPrice) + (sugar_bought * sugarPrice));
      game.setCash(cash);
      totalLemons = game.getLemons() + lemon_bought;
      game.setLemons(totalLemons);
      totalSugar = game.getSugar() + sugar_bought;
      game.setSugar(totalSugar); 
      
      game.setExpense((lemon_bought * lemonPrice) + (sugar_bought * sugarPrice));
      
      balance_html.writeFile(game.getLemons(),
                             game.getSugar(),
                             game.getCash(),
                             game.getIncome() - game.getExpense());    
    }
  }
  return 0 ;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
