#ifndef CPUNIT_DBC_H
#define CPUNIT_DBC_H


/**
   @file cpunit_dbc.h 
   @brief cpunit extension. 
   @details This file contains a small extension to cpunit, 
   for handling design by contract exceptions.
   The Dbc checks are turned off with the NDEBUG flag, 
   just as the assert macro in <cassert>.
*/
#include <cpunit>

#ifndef NDEBUG

/**
   %Test case registrator for tests expecting a design by contract exception.
   The test will only succeed if an exception of type <tt>DbcException</tt> is thrown from the tested code.
   @param n The namespace (suite) where the test case resides
   @param f The name of the test case to register
*/
#define CPUNIT_TEST_DBC(n,f) CPUNIT_TEST_EX(n,f,DbcException)

#else
#define CPUNIT_TEST_DBC(n,f) void f(); void f()
#endif

#endif // CPUNIT_DBC_H
