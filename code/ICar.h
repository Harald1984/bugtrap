#ifndef ICAR_H
#define ICAR_H

/**
   @file ICar.h 
   @brief Declaration of car interface.
*/

namespace BugTrap
{

  /// \addtogroup ExampleCode Example code
  /// @{
  
  /**
     @brief Car interface class.
  */
  class ICar
  {
  public:
    ICar() = default;
    virtual ~ICar() = default;
    virtual void drive() = 0;
    virtual void stop() = 0;
    virtual bool engine_is_running() const = 0;
    virtual unsigned int number_of_cylinders() const = 0;
  };

  ///@}
}
#endif // ICAR_H
