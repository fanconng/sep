//------------------------------------------------------------------------------
// Command.cpp
//
// Group: Group 15631, study assistant Philip Loibl
//
// Authors: Pranger Stefan 1530389
// Bernhard Köpfle 0911531
// Endrit Sadriu 1432246
//------------------------------------------------------------------------------
//

#include "Command.h"
#include <memory>

//------------------------------------------------------------------------------
Command::Command()
{
}

//------------------------------------------------------------------------------
Command::Command(std::string name) : command_name_(name)
{
}

//------------------------------------------------------------------------------
Command::~Command()
{
}

//------------------------------------------------------------------------------
const std::string &Command::getName() const
{
  return command_name_;
}