//------------------------------------------------------------------------------
// Balance.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include <iostream>
#include "GameView.h"

//------------------------------------------------------------------------------
GameView::GameView()
{
}

//------------------------------------------------------------------------------
GameView::~GameView()
{
}


GameView::GameView(const GameView& original)
{
}

//------------------------------------------------------------------------------
GameView GameView::operator= (const GameView& original)
{
  return *this;
}

//------------------------------------------------------------------------------
void GameView::print(std::string argument)
{
  std::cout << argument;
}

//------------------------------------------------------------------------------
void GameView::print_prompt()
{
  std::cout << "sep> ";
}




//------------------------------------------------------------------------------

std::string GameView::read()
{
  std::string return_string;
  
  getline(std::cin, return_string);
  
  return return_string;
}

