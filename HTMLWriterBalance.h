#ifndef HTMLWRITERBALANCE_H_INCLUDED
#define HTMLWRITERBALANCE_H_INCLUDED
#include <string>
#include "HTMLWriter.h"



//------------------------------------------------------------------------------
// HTMLWriterBalance Class 
// Subclass of HTMLWriter
// This class is used for creating html files which show the storage and cash
// values
class HTMLWriterBalance : public HTMLWriter
{
  public:
    //----------------------------------------------------------------------------
    // Constructors
    HTMLWriterBalance();
    HTMLWriterBalance(std::string file_name);
  
    //----------------------------------------------------------------------------
    // Destructor
    ~HTMLWriterBalance();
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    HTMLWriterBalance(const HTMLWriterBalance& original);
    HTMLWriterBalance operator= (HTMLWriterBalance const& original);
    
    
    //----------------------------------------------------------------------------
    // Setter and Getter
    // void setFileName(std::string file_name);

    //----------------------------------------------------------------------------
    // Methode which creates an html file 
    // This method will create an html file for the current balances
    // @param lemon
    // @param sugar
    // @param cash
    // @param delta
    void writeFile(int lemon, int sugar, int cash, int delta);

};


#endif // HTMLWRITERBALANCE_H_INCLUDED
