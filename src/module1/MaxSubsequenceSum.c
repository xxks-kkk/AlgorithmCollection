#include "module1.h"
#include "utility.h"

/*
 * the Maximum Subsequence Sum Problem
 * 
 * .. seealso::
 *  
 *     https://en.wikipedia.org/wiki/Maximum_subarray_problem
 */

/*
 * Idea    : exhaustively tries all possibilities
 * Big-O   : O(N^3)
 * Remarks :
 */

int MaxSubsequenceSum1( const int A[], int N )
{
  int ThisSum, MaxSum, i, j, k;

  MaxSum = 0;
  for( i = 0; i < N; i++ )
  {
    for ( j = i; j < N; j++ )
    {
      ThisSum = 0;
      for( k = i; k <= j; k++ )
      {
        ThisSum += A[ k ];
      }

      if (ThisSum > MaxSum)
      {
        MaxSum = ThisSum;
      }
    }
  }
  return MaxSum;
}

/*
 * Idea    : exhaustively tries all possibilities
 * Big-O   : O(N^3)
 * Remarks : We calculate in a smarter way than algo 1. The key observation
 *           is that \sum\limits_{k=i}^j A_k = A_j + \sum\limits_{k=i}^{j-1} A_k
 */

int MaxSubsequenceSum2( const int A[], int N )
{
  int ThisSum, MaxSum, i, j;

  MaxSum = 0;
  for( i = 0; i < N; i++ )
  {
    ThisSum = 0;
    for( j = i; j < N; j++ )
    {
      ThisSum += A[ j ];

      if ( ThisSum > MaxSum )
      {
        MaxSum = ThisSum;
      }
    }
  }
  return MaxSum;
}

/*
 * Idea    : the maximum subsequence sum can be in one of three places. Either
 *           it occurs entirely in the left half of the input, or entirely in the
 *           right half, or it crosses the middle and is in both halves.
 * Big-O   : O(NlogN)
 * Remarks : a "divide-and-conquer" strategy
 */

static int MaxSubSum( const int A[], int Left, int Right )
{
  int MaxLeftSum, MaxRightSum;
  int MaxLeftBorderSum, MaxRightBorderSum;
  int LeftBorderSum, RightBorderSum;
  int Center, i;

  if( Left == Right ) /* Base Case */
  {
    if( A[ Left ] > 0 )
    {
      return A[ Left ];
    }
    else
    {
      return 0;
    }
  }

  Center = ( Left + Right ) / 2;
  MaxLeftSum = MaxSubSum( A, Left, Center );
  MaxRightSum = MaxSubSum( A, Center + 1, Right );

  MaxLeftBorderSum = 0; LeftBorderSum = 0;
  for( i = Center; i >= Left; i-- )
  {
    LeftBorderSum += A[ i ];
    if( LeftBorderSum > MaxLeftBorderSum )
    {
      MaxLeftBorderSum = LeftBorderSum;
    }
  }

  MaxRightBorderSum = 0; RightBorderSum = 0;
  for( i = Center + 1; i <= Right; i++ )
  {
    RightBorderSum += A[ i ];
    if( RightBorderSum > MaxRightBorderSum )
    {
      MaxRightBorderSum = RightBorderSum;
    }
  }

  return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubsequenceSum3( const int A[], int N )
{
  return MaxSubSum( A, 0, N - 1 );
}

/*
 * Idea    : ?
 * Big-O   : O(N)
 * Remarks : 1. the algorithm only one pass through the data, and once A[i] is
 *              read and processed, it does not need to be remembered. Thus, if 
 *              the array is on a disk or tape, it can be read sequentially, and 
 *              there is no need to store any part of it in main memory.
 *           2. at any point in time, the algorithm can correctly give an answer
 *              to the subsequence problem for the data it has already read.
 *           3. known as "Kadane's algorithm"
 */

int MaxSubsequenceSum4( const int A[], int N )
{
  int ThisSum, MaxSum, j;

  ThisSum = MaxSum = 0;
  for( j = 0; j < N; j++ )
  {
    ThisSum += A[ j ];

    if( ThisSum > MaxSum )
    {
      MaxSum = ThisSum;
    }
    else if( ThisSum < 0 )
    {
      ThisSum = 0;
    }
  }
  return MaxSum;
}
