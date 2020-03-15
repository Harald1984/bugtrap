
///@file V8EngineTest.cpp Unit tests for V8Engine class

#include <V8Engine.h>

#include <gtest/gtest.h>



namespace BugTrap
{
  namespace Test
  {
	 
    /// \addtogroup UnitTests
    /// @{
    
    /// Unit tests for class V8Engine.
    class V8EngineTest : public ::testing::Test
    {
    };
	
    ///@brief Checks the initialization.
    TEST(V8EngineTest, test_constructor)
    {
      V8Engine* v8 = new V8Engine;
      IEngine& engine = *v8;
      ASSERT_FALSE(engine.is_running());
      delete v8;
    }
	
    ///@brief Checks the start function.
    TEST(V8EngineTest, test_start)
    {
      V8Engine v8;
      IEngine& engine = v8;
      engine.start();
      ASSERT_TRUE(engine.is_running());
    }
	
    ///@brief Checks the stop function.
    TEST(V8EngineTest, test_stop)
    {
      V8Engine v8;
      IEngine& engine = v8;
	
      engine.start();
      engine.stop();
      ASSERT_FALSE(engine.is_running());
    }
	
    ///@brief Checks the number of cylinders function.
    TEST(V8EngineTest, test_number_of_cylinders)
    {
      V8Engine v8;
      IEngine& engine = v8;
	
      ASSERT_EQ(8U, engine.number_of_cylinders());
    }
    ///@}
  }
}
