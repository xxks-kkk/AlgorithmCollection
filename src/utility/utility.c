#include "utility.h"

/*
 * Idea    : In boolean `AND` operation such as `x && y`, `y` is 
 *           evaluated iff `x` is true. If `x` is false, then 
 *           `y` is not evaluated because the whole expression would
 *           be false which can be deduced without even evaluating `y`.
 *           This is called short-circuiting when the value of a boolean
 *           expression can be deduced without evaluating all operands in it.
 * Big-O   :
 * Remarks : http://stackoverflow.com/questions/7074010/find-maximum-of-three-number-in-c-without-using-conditional-statement-and-ternar
 */

int Max3( int A, int B, int C )
{
  int m = A;
  ( void )( ( m < B ) && ( m = B ) ); // set `m` to `B` iff `m` is less than `B`
  ( void )( ( m < C ) && ( m = C ) );
  return m;
}

/*
 * Idea    : 
 * Big-O   : O(logN)
 * Remarks : We count the number of multiplications as the measurement of running time
 */
long int Pow( long int X, unsigned int N )
{
  if ( N == 0 )
    return 1;
  if ( N % 2 == 0 )
    return Pow( X * X, N/2);
  else
    return Pow( X * X, N/2) * X;
}
