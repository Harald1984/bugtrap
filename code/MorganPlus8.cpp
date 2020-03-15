#include "MorganPlus8.h"

/**
   @file MorganPlus8.cpp 
   @brief Implementation of Morgan Plus 8 class.
 */

BugTrap::MorganPlus8::MorganPlus8()
    : NeedsEngine<V8Engine>(engine_),
      engine_()
{
}
