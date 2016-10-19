#include "module1.h"
#include "utility.h"

/*
 * The variation (extension) of Maximum Subsequence Sum Problem
 *
 */

/*
 * Problem: Find the minimun subsequence sum
 */

/*
 * Idea    : Subsequence with minimum sum cannot start with a positive number
 * Big-O   : O(N)
 * Remarks : The solution mimics the algorithm4 in maximum subsequence sum
 *           problem. 
 */

int MinSubsequenceSum(const int A[], int N )
{
  int ThisSum, MinSum, j;

  ThisSum = MinSum = 0;

  for( j=0; j<N; j++ )
  {
    ThisSum += A[j];
    if (ThisSum < MinSum)
    {
      MinSum = ThisSum;
    }
    else if (ThisSum > 0)
    {
      ThisSum = 0;
    }
  }
  return MinSum;
}

/*
 * Problem: Find the minimum positive subsequence sum
 */
