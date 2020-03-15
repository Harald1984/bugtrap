#include "Circle.h"
#include "Constant.h"
#include "DbcMacros.h"

///@file Circle.cpp Implementation of the Circle class.


BugTrap::Circle::Circle(const double r)
    : IGeometricObject<2U>(),
      radius_(r)
{
    PRECONDITION(r>=0, "A negative radius was given to a Circle constructor.");
}

void
BugTrap::Circle::set_radius(const double r)
{
    PRECONDITION(r>=0, "A negative radius was given to a Circle::set_radius.");
    radius_ = r;
}


double
BugTrap::Circle::radius() const
{
    return radius_;
}


double
BugTrap::Circle::circumference() const
{
    return 2.0*Constant<double>::pi() * radius_;
}


double
BugTrap::Circle::area() const
{
    return Constant<double>::pi() * radius_ * radius_;
}

