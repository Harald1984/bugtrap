#ifndef NEEDSENGINE_H
#define NEEDSENGINE_H

#include <ICar.h>
#include <DbcMacros.h>

/**
   @file NeedsEngine.h
   @brief Declaration of car engine dependency injector.
 */

namespace BugTrap
{
  /// \addtogroup ExampleCode Example code
  /// @{
	
  /**
     @brief Engine dependency injector.
     @details This class was adapted from Torgny's blogg @cite BeautifulInjection.
  */
  template <class TEngine>
  class NeedsEngine : public ICar
  {
  public:
    explicit NeedsEngine(TEngine& engine);
    ~NeedsEngine() = default;
    void drive();
    void stop();
    bool engine_is_running() const;
    unsigned int number_of_cylinders() const;
	
  private:
    TEngine& engine_;
  };
  ///@}
}

 
/**
   Parametric constructor for injecting the engine dependency.
 */
template <class TEngine>
BugTrap::NeedsEngine<TEngine>::NeedsEngine(TEngine& engine)
    : engine_(engine)
{
}

/**
   Drive.
 */
template <class TEngine>
void
BugTrap::NeedsEngine<TEngine>::drive()
{
   if (!engine_.is_running())
   {
      engine_.start();
   }
   POSTCONDITION(engine_.is_running(),"Drive postcondition failed.");
}


/**
    Stop and switch off the engine.
 */
template <class TEngine>
void
BugTrap::NeedsEngine<TEngine>::stop()
{
    engine_.stop();
}

/**
   Get the number of cylinders.
   @return number of cylinders.
 */
template <class TEngine>
unsigned int
BugTrap::NeedsEngine<TEngine>::number_of_cylinders() const
{
   return engine_.number_of_cylinders();
}


/**
   Check engine status.
   @return true if engine is running.
 */
template <class TEngine>
inline
bool
BugTrap::NeedsEngine<TEngine>::engine_is_running() const
{
    return engine_.is_running();
}



#endif // NEEDSENGINE_H
