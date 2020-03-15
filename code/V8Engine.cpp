#include "V8Engine.h"

/**
   @file V8Engine.cpp 
   @brief Implementation of V8 class.
*/

BugTrap::V8Engine::V8Engine()
    : IEngine(),
      running_(false)
{
}

void
BugTrap::V8Engine::start()
{
    running_ = true;
}

void
BugTrap::V8Engine::stop()
{
    running_ = false;
}

bool
BugTrap::V8Engine::is_running() const
{
    return running_;
}

unsigned int
BugTrap::V8Engine::number_of_cylinders() const
{
    return 8U;
}
