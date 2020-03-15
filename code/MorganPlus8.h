#ifndef MORGANPLUS8_H
#define MORGANPLUS8_H

#include <NeedsEngine.h>
#include <V8Engine.h>

/**
   @file MorganPlus8.h 
   @brief Declaration of Morgan Plus 8 class.
 */
 
 namespace BugTrap
 {
	
	/// A particular car instance.
	class MorganPlus8 : public NeedsEngine<V8Engine>
	{
	public:
	  MorganPlus8();
	  ~MorganPlus8() = default;
	private:
	  V8Engine engine_;
	};
}
#endif // MORGANPLUS8_H
