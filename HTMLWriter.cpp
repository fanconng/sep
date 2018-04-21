//------------------------------------------------------------------------------
// HTMLWriter.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//
#include "HTMLWriter.h"
#include <string>
#include <iostream>
#include <fstream>

using std::endl;

//Constructors
HTMLWriter::HTMLWriter()
{
}

HTMLWriter::HTMLWriter(std::string file_name):filename_(file_name)
{
}

HTMLWriter::HTMLWriter(const HTMLWriter& original)
{
  filename_ = original.filename_;

}


HTMLWriter HTMLWriter::operator= (const HTMLWriter& original)
{
  filename_ = original.filename_;
  return *this;
}

//Destructor
HTMLWriter::~HTMLWriter()
{
}

//Setter and Getter
void HTMLWriter::setFileName(std::string file_name)
{
  filename_ = file_name;
}
/*
std::string HTMLWriter::getFileName()	
{
  return filename_;
}*/

//Methode
void HTMLWriter::writeFile(std::string including_string)
{
  std::string file_name = HTMLWriter::getFileName();
  std::ofstream html_file(file_name);
  
  //std::string background = "url(\"http://www.raisingedmonton.com/wp-content/";
  //background += "uploads/2016/08/Lemonade-Stand-Day-Simply-Supper.jpg\")";
  std::string background = "url(\"backgrnd_final.png\")";
  
  html_file << "<!DOCTYPE html>\n\n<html lang=\"en\">\n";
  html_file << "\t<head>\n<style>\nbody {\n";
  html_file << "background: " << background << ";\n";
  html_file << "background-size: cover;\n";
  html_file << "background-repeat: no-repeat;\n ";
  html_file << "background-position: center center;\n";
  html_file << "font: normal 18px Verdana, Arial, sans-serif;\n";
  html_file << "color: black; }\n";
  html_file << "</style>";
  html_file << "\t\t<meta charset=\"utf-8\">\n";
  html_file << "\t\t<meta http-equiv=\"refresh\" content=\"3\">\n";
  html_file << "\t\t<title>SEP 2017</title>\n";
  html_file << "\t\t<style>body{margin: 0px; padding: 0px;}</style>\n";
  html_file << "\t</head>\n\t<body>"<< including_string;
  html_file << "\n\t</body>\n</html>";
  
  html_file.close();
}
