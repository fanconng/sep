//------------------------------------------------------------------------------
// HTMLWriterEnvironment.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITERENVIRONMENT_H_INCLUDED
#define HTMLWRITERENVIRONMENT_H_INCLUDED
#include <string>
#include "HTMLWriter.h"
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
// HTMLWriterEnvironment Class 
// Subclass of HTMLWriter
// This class is used for creating html files which show the environmental
// conditions
class HTMLWriterEnvironment : public HTMLWriter
{
  public:
    //----------------------------------------------------------------------------
    // Constructors
    HTMLWriterEnvironment();
    HTMLWriterEnvironment(std::string file_name);

    //----------------------------------------------------------------------------
    // Destructor
    ~HTMLWriterEnvironment();

    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    HTMLWriterEnvironment(const HTMLWriterEnvironment& original);
    HTMLWriterEnvironment operator= (HTMLWriterEnvironment const& original);
    
    //----------------------------------------------------------------------------
    // Setter and Getter
    // void setFileName(std::string file_name);


    //----------------------------------------------------------------------------
    // Methode which creates an html file 
    // This method will create an html file for the environmental conditions
    // @param ec Contains all the needed data to be printed
    void writeFile(EnvironmentalCondition ec);

  
};

std::string boolToString(const bool input);





#endif // HTMLWRITERENVIRONMENT_H_INCLUDED
