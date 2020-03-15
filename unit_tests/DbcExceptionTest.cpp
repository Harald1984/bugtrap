

///@file NeedsEngineTest.cpp Unit tests for NeedsEngine class

#include <DbcException.h>
#include <DbcMacros.h>

#include <gtest/gtest.h>

namespace BugTrap
{
  namespace Test 
  {
	 
    /// \addtogroup UnitTests
    /// @{

    ///  Unit tests for class DbCException.
    class DbcExceptionTest  : public ::testing::Test
    {
    };
    
    
    ///@brief Checks the constructor.
    TEST(DbcExceptionTest, test_constructor)
    {
      const std::string message("test");
      DbcException* exception = new DbcException(DbcException::precondition,
						 message,
						 __FILE__,
						 __LINE__);
      const std::string what =std::string(exception->what());
      std::size_t found = what.find(message);
      ASSERT_TRUE(found != std::string::npos);
      delete exception;
    }
	
    ///@brief Checks the precondition macro.
    TEST(DbcExceptionTest, test_precondition)
    {
      ASSERT_THROW(PRECONDITION(false,"Just testing."),
		   DbcException);
    }
    ///@brief Checks the postcondition macro.
    TEST(DbcExceptionTest, test_postcondition)
    {
      ASSERT_THROW(POSTCONDITION(false,"Just testing."),
		   DbcException);
    }
    ///@brief Checks the invariant macro.
    TEST(DbcExceptionTest, test_invariant)
    {
      ASSERT_THROW(INVARIANT(false,"Just testing."),
		   DbcException);
    }
    /// @}
  }
}
