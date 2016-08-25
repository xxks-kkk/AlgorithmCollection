#include "module1.h"
#include "utility.h"

/*
 * the Maximum Subsequence Sum Problem
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
 * Idea    : 
 * Big-O   : 
 * Remarks :
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
