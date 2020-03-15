
///@file ByteSwapTest.cpp Unit tests for byte swap function.

#include <byte_swap.h>
#include <gtest/gtest.h>

namespace BugTrap
{
  namespace Test  
  {
    
    /// \addtogroup UnitTests
    /// @{
    
    /// Unit test for the byte_swap function.
    class ByteSwapTest : public ::testing::Test
    {
    };


    ///@brief Checks the byte swap by a round trip test.
    TEST(ByteSwapTest, test_byte_swap)
    {
      const int input = 3;
      const int output = byte_swap(input);
      ASSERT_EQ(768, output );
      ASSERT_EQ(input, byte_swap(output) );
    }

    ///@}
  }
}
