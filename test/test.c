#include "unity.h"
#include "testModule1.h"
#include "testUtility.h"

int main(void)
{
  printf( "\n" );
  printf( "Test:: Utility\n" );
  UNITY_BEGIN();
  RUN_TEST(test_Max3);
  printf( "\n" );
  
  printf( "Test:: Module1\n" );
  RUN_TEST(test_MaxSubsequenceSum1);
  RUN_TEST(test_MaxSubsequenceSum2);
  RUN_TEST(test_MaxSubsequenceSum3);
  RUN_TEST(test_MaxSubsequenceSum4);
  RUN_TEST(test_BinarySearch);
  RUN_TEST(test_GCD);
  UNITY_END();
  printf( "\n" );

  return 0;
}
