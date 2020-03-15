#include "DbcException.h"

#include <sstream>

/// @file DbcException.cpp Implementation of design by contract exception.

BugTrap::DbcException::DbcException(const ContractViolation violation,
                           const std::string& msg,
                           const std::string& file,
                           const unsigned int line)
    : std::runtime_error(message(violation,msg,file,line))
{
}

const
std::string
BugTrap::DbcException::message(const ContractViolation violation,
                      const std::string& msg,
                      const std::string& file,
                      const unsigned int line)
{
    std::stringstream error;
    switch(violation)
    {
      case precondition:
      {
         error << "Precondition violation: ";
         break;
      }
      case postcondition:
      {
         error << "Postcondition violation: ";
         break;
      }
      case invariant:
      {
         error << "Invariant violation: ";
         break;
      }
    }
    error << msg << " File: " << file << "(line " << line << ").";
    return error.str();
}
