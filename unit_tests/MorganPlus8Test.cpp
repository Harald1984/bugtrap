

///@file MorganPlus8Test.cpp Unit tests for MorganPlus8 class.

#include <MorganPlus8.h>
#include <V8Engine.h>

#include <gtest/gtest.h>

namespace BugTrap
{
  namespace Test
  {
	
    /// \addtogroup UnitTests
    /// @{
    
    /// Unit tests for class MorganPlus8.
    class MorganPlus8Test : public ::testing::Test
    {
    };
	
    ///@brief Checks the initialization.
    TEST(MorganPlus8Test, test_constructor)
    {
      MorganPlus8* morgan = new MorganPlus8;
      ICar& car = *morgan;
      ASSERT_FALSE(car.engine_is_running());
      delete morgan;
    }
	
	
    ///@brief Checks the initialization.
    TEST(MorganPlus8Test, test_number_of_cylinders)
    {
      MorganPlus8 morgan;
      ICar& car = morgan;
      ASSERT_EQ(8U, car.number_of_cylinders());
    }
	
	
    ///@brief Checks the drive function.
    TEST(MorganPlus8Test, test_drive)
    {
      MorganPlus8 morgan;
      ICar& car = morgan;
      car.drive();
      ASSERT_TRUE(car.engine_is_running());
    }
	
    ///@brief Checks the stop function.
    TEST(MorganPlus8Test, test_stop)
    {
      MorganPlus8 morgan;
      ICar& car = morgan;
      car.drive();
      car.stop();
      ASSERT_FALSE(car.engine_is_running());
    }
    ///@}
  }
}
