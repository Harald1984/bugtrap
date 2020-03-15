

///@file CircleTest.cpp Unit tests for Circle class.

#include <Circle.h>
#include <DbcException.h>

#include <cmath>
#include <gtest/gtest.h>

namespace BugTrap
{
	
  namespace Test
  {
    /// \addtogroup UnitTests
    /// @{
	
    /// Unit tests for class Circle.
    class CircleTest : public ::testing::Test
    {
    public:
      /// \f$\pi\f$.
      static
      const
      double pi;
	
	    
      /// Tolerance to allow for numerical inaccuracies in the tests.
      static
      const
      double tolerance;
    };
	
    const double
    CircleTest::pi = ::std::atan(1) * 4.0; 
	
    const double
    CircleTest::tolerance = 1.0E-6;
	

    /// @brief Checks the circle area function.    
    TEST_F(CircleTest, test_area)
    {
      Circle circle(1.0);
      IGeometricObject<2U>& object = circle;
      ASSERT_NEAR(CircleTest::pi,object.area(),tolerance);
	
      circle.set_radius(2.0);
      ASSERT_NEAR(4.0 * pi,object.area(), tolerance);
    }
	
    ///@brief Checks the circumference function.
    TEST_F(CircleTest, test_circumference)
    {
      Circle circle(1.0);
      IGeometricObject<2U>& object = circle;
      ASSERT_NEAR(pi * 2.0,object.circumference(), tolerance);
	
      circle.set_radius(3.0);
      ASSERT_NEAR(6.0 * pi,object.circumference(), tolerance);
    }
	
    ///@brief Checks the radius function.
    TEST_F(CircleTest, test_radius)
    {
      double r = 0.0;
      Circle nullCircle(r);
      ASSERT_EQ(r, nullCircle.radius());
	
      r = 1.0;
      Circle circle(r);
      ASSERT_EQ(r, circle.radius());
	
      r = 3.0;
      circle.set_radius(r);
      ASSERT_EQ(r, circle.radius());
    }
	  
    /// @brief Check that a megative radius is caught by a precondition.
    TEST_F(CircleTest, test_radius_dbc)
    {
      ASSERT_THROW(Circle circle(-1.0), DbcException);
    }
	
    /// @brief Check that a megative radius is caught by a precondition.
    TEST_F(CircleTest, test_set_radius_dbc)
    {
      Circle circle(0.0);
      ASSERT_THROW(circle.set_radius(-1.0), DbcException);
    }	  
    ///@}
  }
}

