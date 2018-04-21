//------------------------------------------------------------------------------
// HTMLWriterEnvironment.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include <string>
//#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>


//Constructors
HTMLWriterEnvironment::HTMLWriterEnvironment()
{
}

HTMLWriterEnvironment::HTMLWriterEnvironment(std::string file_name)
  : HTMLWriter(file_name)
{
}

//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
HTMLWriterEnvironment::HTMLWriterEnvironment(const HTMLWriterEnvironment& original)
{
}

//------------------------------------------------------------------------------
// Hier würde ein Umbruch in der Parameterliste leider auch die Grenze bzgl 
// 80 Character nicht lösen
HTMLWriterEnvironment HTMLWriterEnvironment::operator= (const HTMLWriterEnvironment& original)
{
  return *this;
}
//Destructor
HTMLWriterEnvironment::~HTMLWriterEnvironment()
{
}

//Methode
void HTMLWriterEnvironment::writeFile(EnvironmentalCondition ec)
{
  
  std::stringstream output_stream;
  std::string output_string;
  
  std::string cover_jpg, rank_precipitation, rank_wind;
  EnvironmentalCondition::Cover sky_cover = ec.getSkyCover();
  EnvironmentalCondition::Rank  precipitation = ec.getPrecipitation();
  EnvironmentalCondition::Rank  wind = ec.getWind();
  float temperature = ec.getTemperature();
  std::string temperature_string = std::to_string(temperature);
  temperature_string.resize(5);
  

  
  output_stream << "<table>\n\t<tbody>\n\t\t<tr>";
  output_stream << "\n\t\t\t<td><strong>Sky cover</strong></td>";
  output_stream << "\n\t\t\t<td></td>";
  output_stream << "\n\t\t</tr>\n\t\t<tr>\n\t\t<td><img src=\"";
  output_stream << "https://palme.iicm.tugraz.at/wiki/images/";
  
  switch(sky_cover)
  {
    case EnvironmentalCondition::Cover::SUNNY : 
      cover_jpg = "9/9a/Sunny.png";
      break;
    case EnvironmentalCondition::Cover::CLOUDY : 
      cover_jpg = "3/33/Cloudy.png";
      break;
    case EnvironmentalCondition::Cover::OVERCAST : 
      cover_jpg = "6/6f/Overcast.png";
      break;
    case EnvironmentalCondition::Cover::VERY_OVERCAST : 
      cover_jpg = "3/30/Very_overcast.png";
      break;
  }
  
  output_stream << cover_jpg;
  output_stream << "\" alt=\"\" width=\"128\" height=\"128\"></td>\n\t\t<td>\n";
  output_stream << "\t\t<p><strong>Precipitation: </strong>";
  
  switch(precipitation)
  {
    case EnvironmentalCondition::Rank::NONE : 
      output_stream << "none</p>\n";
      break;
    case EnvironmentalCondition::Rank::LOW : 
      output_stream << "low</p>\n";
      break;
    case EnvironmentalCondition::Rank::MEDIUM : 
      output_stream << "medium</p>\n";
      break;
    case EnvironmentalCondition::Rank::HIGH : 
      output_stream << "strong</p>\n";
      break;
  }
  
 
  output_stream << "\t\t<p><strong>Temperature: </strong>";
  output_stream << temperature_string + "</p>\n";
  output_stream << "\t\t<p><strong>Wind: </strong>";
  
  switch(wind)
  {
    case EnvironmentalCondition::Rank::NONE : 
      output_stream << "none</p>\n";
      break;
    case EnvironmentalCondition::Rank::LOW : 
      output_stream << "low</p>\n";
      break;
    case EnvironmentalCondition::Rank::MEDIUM : 
      output_stream << "medium</p>\n";
      break;
    case EnvironmentalCondition::Rank::HIGH : 
      output_stream << "strong</p>\n\t\t";
      break;
  }        
  
  output_stream << std::boolalpha;
  
  output_stream << "<p><strong>Hot: </strong>" + boolToString(ec.isItHot());
  output_stream << "</p>\n\t\t";
  output_stream << "<p><strong>Rainy: </strong>" + boolToString(ec.isItRainy());
  output_stream << "</p>\n\t\t";
  output_stream << "<p><strong>Stormy: </strong>" + boolToString(ec.isItStormy());
  output_stream << "</p>\n\t\t";
  output_stream << "\n\t\t\t</td>\n\t\t</tr>\n\t</tbody>\n\t</table>";
  
  output_string = output_stream.str();
  std::string output_filename = this->getFileName();
  
  HTMLWriter::writeFile(output_string);
  
 
 
}

std::string boolToString(const bool input)
{
  std::string output = "false";
  if(input)
  {
    output = "true";
  }
  return output;
}
      
