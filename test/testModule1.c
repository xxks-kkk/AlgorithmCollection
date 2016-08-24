#include "unity.h"
#include "module1.h"

void test_MaxSubsequenceSum1(void)
{
  int test_array[6] = {-2,11,-4,13,-5,-2};
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum1(test_array, 6));
}


int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_MaxSubsequenceSum1);
  return UNITY_END();
}
