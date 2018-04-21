//------------------------------------------------------------------------------
// GameView.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef GAMEVIEW_H_INCLUDED
#define GAMEVIEW_H_INCLUDED

#include <string>


//------------------------------------------------------------------------------
// GameView Class 
// This class represents the view part of the MVC
class GameView
{
  private:
    
  public:
    //--------------------------------------------------------------------------
    // Constructor and Destructor
    GameView();
    ~GameView();
  
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    GameView(const GameView& original);
    GameView operator= (GameView const& original);
    
     
    //--------------------------------------------------------------------------
    // Sends messages to the console and handles possible Messages from commands
    // @param argument Possible Messages which will be sent to the console
  
    void print(std::string argument = std::string());

    //--------------------------------------------------------------------------
    // Sends the 'sep> '-prompt to the console
    void print_prompt();

  
    //----------------------------------------------------------------------------
    // Reads from an Input-Stream and returns a string 
    // @return String which was entered at the console
    std::string read();

};

#endif //GAMEVIEW_H_INCLUDED
