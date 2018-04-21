//------------------------------------------------------------------------------
// HTMLWriter.h
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITER_H_INCLUDED
#define HTMLWRITER_H_INCLUDED
#include <string>

//------------------------------------------------------------------------------
// HTMLWriter Class 
// This class is used for creating html files 
class HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Constructors
    HTMLWriter();
    HTMLWriter(std::string file_name);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~HTMLWriter();
 
    //--------------------------------------------------------------------------
    //Copy-Constructor & Assignment Operator
    HTMLWriter(const HTMLWriter& original);
    HTMLWriter operator= (HTMLWriter const& original);
    
    //--------------------------------------------------------------------------
    // Setter and Getter
    void setFileName(std::string file_name);

    std::string getFileName() const {return filename_;};

    //----------------------------------------------------------------------------
    // Methode which creates a html file and adds the given string between
    // the body tags
    void writeFile(std::string including_string);

  private:
    //----------------------------------------------------------------------------
    //string Variable presenting the name of the html file
    std::string filename_;


};


#endif
