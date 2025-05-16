/*******************************Precomputed Constant Example*************************************/

#include <stdint.h>
/*
We want to multiply 5.75 * 0.3125
But the microcontroller doesn't have Floating Point Unit ( FPU )
so we do all math using integers ( fixed point math )

Step 1: Scale the numbers to keep decimal precision
        For example, 5.75 -> 5750 ( scaled by 1000 )

Step 2: Precompute 0.3125 as an integer
        0.3125 * 10000 = 3125 ( we scale by 10000 for better precision ) 
*/  
#define SCALE_FACTOR 3125
/*
  This function performs (input × 0.3125) using only integers.
  Assumes: 
    - input is scaled by 1000 (e.g., 5.75 → 5750)
    - SCALE_FACTOR is scaled by 10000
*/
int16_t multiply_scaled( int16_t input_scaled)    //Used int16_t to safely store values like 5750
{
 // Multiply input and factor, then scale back down
  return ( ( input_scaled * SCALE_FACTOR) / 1000 ) ;
}

int main()
{
  int16_t input = 5750 ;  //5.75 scaled as 5750
  int16_t result = multiply_scaled( input ) ;    //Used Call By Value

  //result = 1796 ( = 1.796 in real terms if scaled by 10000 )
  //This avoids using floats and runs faster on tiny microcontrollers.
  
  return 0 ;
}
