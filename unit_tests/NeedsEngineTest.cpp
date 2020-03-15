

///@file NeedsEngineTest.cpp Unit tests for NeedsEngine class

#include <NeedsEngine.h>
#include <IEngine.h>

#include <gtest/gtest.h>


namespace BugTrap
{
  namespace Test
  {
    /// \addtogroup UnitTests
    /// @{

    /// Unit test for template class NeedsEngine.
    class NeedsEngineTest : public ::testing::Test
    {
    };

    /// @brief Engine mockup for test purposes.
    class EngineMock : public IEngine
    {
    public:
      /// Creates non-running engine.
      EngineMock()
	: IEngine(),
	  running_(false) {}

      /// Destroys the engine.
      ~EngineMock() {}

      /// Staret engine.
      void start() { running_ = true; }

      /// Stop engine.
      void stop() { running_ = false; }

      /// Running indicator.
      bool is_running() const { return running_; }

      /// Number of cylinders
      unsigned int number_of_cylinders() const { return 3U; }
    private:
      bool running_;
    };

    ///@brief Checks the initialization.
    TEST(NeedsEngineTest, test_constructor)
    {
      EngineMock mock;
      NeedsEngine<EngineMock> ne(mock);
      ASSERT_FALSE(ne.engine_is_running());
    }

    ///@brief Checks the drive function.
    TEST(NeedsEngineTest, test_drive)
    {
      EngineMock mock;
      NeedsEngine<EngineMock> ne(mock);
      ne.drive();
      ASSERT_TRUE(ne.engine_is_running());
    }

    ///@brief Checks the stop function.
    TEST(NeedsEngineTest, test_stop)
    {
      EngineMock mock;
      NeedsEngine<EngineMock> ne(mock);
      ICar* car = &ne;
      car->drive();
      car->stop();
      ASSERT_FALSE(car->engine_is_running());
    }

    ///@brief Checks the number of cylinders function.
    TEST(NeedsEngineTest, test_number_of_cylinders)
    {
      EngineMock mock;
      NeedsEngine<EngineMock> ne(mock);
      ASSERT_EQ(3U, ne.number_of_cylinders());
    }
    ///@}
  }
}
