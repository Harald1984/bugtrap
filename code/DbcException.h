#ifndef DBCEXCEPTION_H
#define DBCEXCEPTION_H

#include <stdexcept>
#include <string>

/**
   @file DbcException.h 
   @brief Declaration of design by contract exception.
*/

namespace BugTrap
{
	
	/**
	   @brief This type exception is thrown if there is a design by contract violation.
	 */
	class DbcException : public std::runtime_error
	{
	public:
	  /// Contracts supported.
	  enum ContractViolation
	  {
	      precondition,  ///< A condition on input to a function.
	      postcondition, ///< A guarantee on the output of a function.
	      invariant      ///< A property maintained by a class.
	  };
	
	  DbcException(const ContractViolation violation,
	               const std::string& msg,
	               const std::string& file,
	               const unsigned int line);
	
	  ~DbcException() = default;
	  
	private:
	  static
	  const
	  std::string message(const ContractViolation violation,
	                      const std::string& msg,
	                      const std::string& file,
	                      const unsigned int line);
	};
	
}
#define PRECONDITION_EXCEPTION(msg) BugTrap::DbcException(BugTrap::DbcException::precondition,msg,__FILE__,__LINE__)
	
#define POSTCONDITION_EXCEPTION(msg) BugTrap::DbcException(BugTrap::DbcException::postcondition,msg,__FILE__,__LINE__)
	
#define INVARIANT_EXCEPTION(msg) BugTrap::DbcException(BugTrap::DbcException::invariant,msg,__FILE__,__LINE__)


#endif // DBCEXCEPTION_H
