#ifndef CIRCLE_H
#define CIRCLE_H

#include <IGeometricObject.h>


///@file Circle.h Declaration of Circle class.


namespace BugTrap
{
  
  /// \addtogroup ExampleCode Example code
  /// @{
  
  /**
     @brief Planar circle in 2 dimensions.
  */
  class Circle : public IGeometricObject<2U>
  {
  public:
    /**
     * @brief Create a circle.
     * @param[in] r radius.
     */
    explicit Circle(const double r);
    
    ~Circle() = default;
    
    double area() const;

    double circumference() const;

    /**
     * @brief get the radius.
     * @return radius.
     */
    double radius() const;
    /**
     * @brief Reset the radius of the circle.
     * @param[in] r radius.
     */
    void set_radius(const double r);
  private:
    double radius_;
  };

  ///@}
}

#endif // CIRCLE_H
