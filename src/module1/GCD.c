#include "module1.h"

/*
 * Euclid's Algorithm
 */

/*
 * Idea    : The algorithm works by continually computing remainders until 0 is reached. 
 *           The last nonzero remainder is the answer.
 * Big-O   : O(logN)
 * Remarks : 1. the implementation assumes M >= N (if N > M, the first iteration of the loop swaps them)
 *           2. O(logN) derives from a theorem: if M > N, then M mod N < M/2 
 *              (after two iteration, the remainder is at most half of its original value)                   
 */           

unsigned int
GCD( unsigned int N, unsigned int M)
{
  unsigned int Rem;

  while( N > 0 )
  {
    Rem = M % N;
    M = N;
    N = Rem;
  }
  return M;
}
