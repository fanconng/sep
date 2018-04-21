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
#include "HTMLWriterBalance.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//Constructors
HTMLWriterBalance::HTMLWriterBalance()
{
}

HTMLWriterBalance::HTMLWriterBalance(std::string file_name)
  : HTMLWriter(file_name)
{
}

//Destructor
HTMLWriterBalance::~HTMLWriterBalance()
{
}


HTMLWriterBalance::HTMLWriterBalance(const HTMLWriterBalance& original)
{
}

//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
HTMLWriterBalance HTMLWriterBalance::operator= (const HTMLWriterBalance& original)
{
  return *this;
}

//Methode
void HTMLWriterBalance::writeFile(int lemon, int sugar, int cash, int delta)
{

  std::stringstream output_stream;
  std::string output_string;
  std::string http = "<img src=\"https://palme.iicm.tugraz.at/wiki/images/";
  output_stream <<"\t<table>\n\t\t<tbody>\n";
  output_stream <<"\t\t\t<tr>\n\t\t\t";
  output_stream <<"\t<td>" << http << "3/35/Lemon.png\"";
  output_stream <<" alt=\"\" width=\"64\" height=\"64\" /></td>\n";
  output_stream <<"\t\t\t\t<td><strong>Lemons: </strong>";
  output_stream << std::to_string(lemon) << "</td>\n";
  output_stream <<"\t\t\t</tr>\n\t\t\t<tr>\n\t\t\t\t<td>";
  output_stream << http << "a/a9/Sugar.png\" ";
  output_stream <<"alt=\"\" width=\"64\" height=\"64\" /></td>\n\t\t\t\t<td>";
  output_stream <<"<strong>Sugar: </strong>" << std::to_string(sugar);
  output_stream << "</td>\n\t\t\t</tr>\n\t\t\t";
  output_stream <<"<tr>\n\t\t\t\t<td>" << http ;
  output_stream <<"f/f0/Coins.png\" alt=\"\" width=\"64\" height=\"64\" ";
  output_stream <<"/></td>\n\t\t\t\t<td>\n\t\t\t\t\t<p><strong>Cash: </strong>";
  output_stream << std::to_string(cash) << "</p>\n\t\t\t\t\t<p>";
  output_stream << "<strong>Delta: </strong>";
  output_stream << std::to_string(delta) << "</p>\n\t\t\t\t</td>\n\t\t\t</tr>";
  output_stream <<"\n\t\t</tbody>\n\t</table>";

  output_string = output_stream.str();

  HTMLWriter::writeFile(output_string);

}
