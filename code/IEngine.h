#ifndef IENGINE_H
#define IENGINE_H

/**
   @file IEngine.h 
   @brief Engine interface declaration.
 */

namespace BugTrap
{

  /// \addtogroup ExampleCode Example code
  /// @{
		
  /**
     @brief Interface for engines.
  */
  class IEngine
  {
  public:
    IEngine() = default;
    virtual ~IEngine() = default;
    /// Starts the engine.
    virtual void start() = 0;
    /// Stops the engine.
    virtual void stop() = 0;
    /// Status check.
    virtual bool is_running() const = 0;
    /// Number of cylinders.
    virtual unsigned int number_of_cylinders() const = 0;
  };

  ///@}
}

#endif // IENGINE_H
