#include "module1.h"
#include "testModule1.h"
#include "utility.h"

void test_MaxSubsequenceSum1(void)
{
  int test_array[6] = {-2,11,-4,13,-5,-2};
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum1(test_array, 6));
}

void test_MaxSubsequenceSum2(void)
{
  int test_array[6] = {-2,11,-4,13,-5,-2};
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum2(test_array, 6));
}

void test_MaxSubsequenceSum3(void)
{
  int test_array[6] = {-2,11,-4,13,-5,-2};
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum3(test_array, 6));
}

void test_MaxSubsequenceSum4(void)
{
  int test_array[6] = {-2,11,-4,13,-5,-2};
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum3(test_array, 6));
}


