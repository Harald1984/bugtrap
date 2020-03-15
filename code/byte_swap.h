#ifndef BYTE_SWAP_H
#define BYTE_SWAP_H

///@file byte_swap.h Declaration of the byte_swap function.

#include <type_traits>


namespace BugTrap
{
  /**
     Byte swapper.
     @param[in] value the input value.
     @return byte swapped value.
     @tparam T the type of input.
  */
  template <typename T>
  T
  byte_swap(T value );
}


template <typename T>
inline
T
BugTrap::byte_swap(T value )
{
  static_assert( std::is_integral< T >::value && sizeof( T ) >= 2,
		 "Cannot swap values of this type" );
  unsigned char* bytes = reinterpret_cast<unsigned char*>( &value );
  for (std::size_t i = 0U; i < sizeof( T ); i += 2U)
    {
      // Switch values frp, right and left
      unsigned char v = bytes[ i ];
      bytes[ i ] = bytes[ i + 1 ];
      bytes[ i + 1 ] = v;
    }
  return value;
}

#endif // BYTE_SWAP_H
