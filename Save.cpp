//------------------------------------------------------------------------------
// Save.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "GameHandler.h"
#include "Save.h"
#include "GameView.h"

Save::Save()
{
}

//------------------------------------------------------------------------------
Save::Save(std::string name) : Command(name)
{
}


//------------------------------------------------------------------------------
Save::~Save()
{
}

//------------------------------------------------------------------------------
int Save::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  std::string file_name = parameters.at(0);
  std::ofstream save_file(file_name);
  GameView output_engine;
  
  if(parameters.size() != 1)
  {
    output_engine.print("Usage: save <save.xml>");
  }
  else
  {
    save_file << "<savefile>\n\t<weather>\n\t\t<wind>";
    save_file << game.getEnvironmentalCondition().getWind() << "</wind>\n\t\t<temperature>";
    save_file << game.getEnvironmentalCondition().getTemperature() << "</temperature>\n\t\t<precipitation>";
    save_file << game.getEnvironmentalCondition().getPrecipitation() << "</precipitation>\n\t\t<cover>";
    save_file << game.getEnvironmentalCondition().getSkyCover() << "</cover>\n\t</weather>\n\t<stats>\n\t\t<cash>";
    save_file << game.getCash() << "</cash>\n\t\t<balance>";
    save_file << game.getIncome() - game.getExpense() << "</balance>\n\t\t<income>"; 
    save_file << game.getIncome() << "</income>\n\t\t<expense>";
    save_file << game.getExpense() << "</expense>\n\t\t<lemons>";
    save_file << game.getLemons() << "</lemons>\n\t\t<sugar>";
    save_file << game.getSugar() << "</sugar>\n\t\t<pricesugar>";
    save_file << game.getPriceSugar() << "</pricesugar>\n\t\t<pricelemons>";
    save_file << game.getPriceLemons() << "</pricelemons>\n\t</stats>\n</savefile>";
  }
  save_file.close();
  
  return 0;
}
