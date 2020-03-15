#ifndef DBCMACROS_H
#define DBCMACROS_H


/**
   @file DbcMacros.h
   @brief Design by contract macros.
   @details This file defines design by contract macros active as long as the NDEBUG flag is not defined.
*/

#include <DbcException.h>

/// \addtogroup ExampleCode Example code
/// @{


#ifndef NDEBUG
#define PRECONDITION(value, msg) \
    if (!(value))                  \
       throw PRECONDITION_EXCEPTION(msg)

#define POSTCONDITION(value, msg) \
    if (!(value))                  \
       throw POSTCONDITION_EXCEPTION(msg)
#define INVARIANT(value, msg) \
    if (!(value))                  \
       throw INVARIANT_EXCEPTION(msg)
#else
#define PRECONDITION(value, msg) void()
#define POSTCONDITION(value, msg) void()
#define INVARIANT(value, msg) void()
#endif

///@}

#endif // DBCMACROS_H
