#ifndef IGEOMETRICOBJECT_H
#define IGEOMETRICOBJECT_H

///@file IGeometricObject.h Declaration of GeometricObject interface.


namespace BugTrap
{  
  /// \addtogroup ExampleCode Example code
  /// @{
  
  /**
     @brief General geometrical object.
     @tparam D number of dimensions.
  */
  template <unsigned int D>
  class IGeometricObject
  {
  };
	
  /// Three-dimensional geometrical object.
  template <>
  class IGeometricObject<3U>
  {
  public:
    /// Trivial constructor.
    IGeometricObject() = default;
	
    /// Destroy.
    virtual ~IGeometricObject() = default;
	
    /// Compute the area of the object.
    /// @return area.
    virtual double area() const = 0;
	
    /// Compute the volume of the object.
    /// @return volume.
    virtual double volume() const = 0;
  };
	
  /// Two-dimensional geometrical object.
  template <>
  class IGeometricObject<2U>
  {
  public:
    /// Trivial constructor.
    IGeometricObject() = default;
	
    /// Destroy.
    virtual ~IGeometricObject() = default;
	
    /// Compute the area of the object.
    /// @return area.
    virtual double area() const= 0;
	
    /// Compute the circumference of the object.
    /// @return circumference.
    virtual double circumference() const = 0;
	
  };
	
  /// One-dimensional geometrical object.
  template <>
  class IGeometricObject<1U>
  {
  public:
    /// Trivial constructor.
    IGeometricObject() = default;
	
    /// Destroy.
    virtual ~IGeometricObject() = default;
	
    /// Compute the length of the object.
    /// @return length.
    virtual double length() const = 0;
	
  };

  ///@}
}
#endif // IGEOMETRICOBJECT_H
