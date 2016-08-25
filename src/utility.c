#include "utility.h"

int Max3( int A, int B, int C )
{
  int m = A;
  ( m < B ) && ( m = B );
  ( m < C ) && ( m = C );
  return m;
}
