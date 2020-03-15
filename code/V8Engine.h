#ifndef V8ENGINE_H
#define V8ENGINE_H

#include <IEngine.h>

/**
   @file V8Engine.h 
   @brief Declaration of V8 class.
*/

namespace BugTrap
{
    
  /// \addtogroup ExampleCode Example code
  /// @{
	
  /// A V8 engine type.
  class V8Engine : public IEngine
  {
  public:
    V8Engine();
    ~V8Engine() = default;
    void start();
    void stop();
    bool is_running() const;
    unsigned int number_of_cylinders() const;
  private:
    bool running_;
	
  };
  ///@}
}
#endif // V8ENGINE_H
