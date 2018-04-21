//------------------------------------------------------------------------------
// Load.cpp
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
#include <algorithm>
#include "GameHandler.h"
#include "EnvironmentalCondition.h"
#include "Load.h"
#include "GameView.h"



//------------------------------------------------------------------------------
// Bei einigen Zeilen würde ein Umbruch in der Parameterliste leider 
//  die Grenze bzgl 80 Character nicht lösen
void updateGameStats(GameHandler& game, 
                     std::vector<std::string> tags, 
                     std::vector<std::string> value)
{
  for(unsigned int i = 0; i < tags.size(); ++i)
  {
    std::transform(tags.at(i).begin(), tags.at(i).end(), tags.at(i).begin(), ::tolower);
    EnvironmentalCondition ec = game.getEnvironmentalCondition();
  if(tags.at(i) == "wind")
  {
    game.getEnvironmentalCondition().setWind(static_cast<EnvironmentalCondition::Rank>(std::stoi(value.at(i))));
    ec.setWind(static_cast<EnvironmentalCondition::Rank>(std::stoi(value.at(i))));
  }
  else if(tags.at(i) == "temperature")
  {
    game.getEnvironmentalCondition().setTemperature(std::stof(value.at(i)));
  }
  else if(tags.at(i) == "precipitation")
  {
    game.getEnvironmentalCondition().setPrecipitation(static_cast<EnvironmentalCondition::Rank>(std::stoi(value.at(i))));
  }
  else if(tags.at(i) == "cover")
  {
    game.getEnvironmentalCondition().setSkyCover(static_cast<EnvironmentalCondition::Cover>(std::stoi(value.at(i))));
  }
  else if(tags.at(i) == "cash")
  {
    game.setCash(std::stoi(value.at(i)));
  }
  else if(tags.at(i) == "income")
  {
    game.setIncome(std::stoi(value.at(i)));
  }  
  else if(tags.at(i) == "expense")
  {
    game.setExpense(std::stoi(value.at(i)));
  }
  else if(tags.at(i) == "lemons")
  {
    game.setLemons(std::stoi(value.at(i)));
  }
  else if(tags.at(i) == "sugar")
  {
    game.setSugar(std::stoi(value.at(i)));
  }
  else if(tags.at(i) == "pricesugar")
  {
    game.setPriceSugar(std::stoi(value.at(i)));
  }
  else if(tags.at(i) == "pricelemons")
  {
    game.setPriceLemons(std::stoi(value.at(i)));
  }
  }
}

Load::Load()
{
}

//------------------------------------------------------------------------------
Load::Load(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
Load::~Load()
{
}

//------------------------------------------------------------------------------
int Load::execute(GameHandler& game, std::vector<std::string>& parameters)
{
  std::string file_error = "[ERR] Could not open file.\n";
  std::string file_invalid_error = "[ERR] Invalid file.\n";
 
  std::string file_name = parameters.at(0);
  std::ifstream save_file(file_name);
  std::vector<std::string> opened_tags;
  std::vector<std::string> tags;
  std::vector<std::string> values;
  std::string buffer;
  std::string tag_open;
  std::string tag_close;
  std::string line;
  std::size_t closing_tag_finder;
  
  GameView output_engine;
  
  bool unmatched_tags = false;
  
  if(parameters.size() != 1)
  {
    output_engine.print("Usage: load <save.xml>");
  }
  else
  {
    if(!save_file)
    {
    std::cout << file_error;
    }

    while(getline(save_file, line))
    {
    auto first_tag_opened = line.find_first_of("<");
    auto first_tag_closed = line.find_first_of(">");
    auto last_tag_opened = line.find_last_of("<");
    auto last_tag_closed = line.find_last_of(">");
    tag_open = line.substr(first_tag_opened + 1, first_tag_closed - first_tag_opened - 1);
    tag_close = line.substr(last_tag_opened + 1, last_tag_closed - last_tag_opened - 1);
    closing_tag_finder = tag_close.find("/");
    if(tag_open == tag_close)
    {
      if(closing_tag_finder == std::string::npos)
      {
      opened_tags.push_back(tag_open);
      }
      else
      {
      tag_close.erase(closing_tag_finder, 1);
      auto remove_tag = std::find(opened_tags.begin(), opened_tags.end(), tag_close);
      opened_tags.erase(remove_tag);
      }
    }
    else
    {
      tag_close.erase(closing_tag_finder, 1);
      
      if(tag_close != tag_open)
      {
      unmatched_tags = true;
      }
      else
      {
      tags.push_back(tag_open);
      buffer = line.substr(first_tag_closed + 1, last_tag_opened - first_tag_closed - 1);
      values.push_back(buffer);
      }
    }
    }
    if(opened_tags.size() != 0 || unmatched_tags)
    {
    std::cout << file_invalid_error;
    }
    else
    {
    updateGameStats(game, tags, values);
    }
  }
  return 0;
}
