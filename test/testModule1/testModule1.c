#include "testModule1.h"

int test_array[6] = {-2,11,-4,13,-5,-2};
int test_array_sorted[6] = {-5,-4,-2,11,13};

void test_MaxSubsequenceSum1(void)
{ 
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum1(test_array, 6));
}

void test_MaxSubsequenceSum2(void)
{
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum2(test_array, 6));
}

void test_MaxSubsequenceSum3(void)
{
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum3(test_array, 6));
}

void test_MaxSubsequenceSum4(void)
{
  TEST_ASSERT_EQUAL_INT(20, MaxSubsequenceSum3(test_array, 6));
}

void test_BinarySearch(void)
{
  TEST_ASSERT_EQUAL_INT(2, BinarySearch(test_array_sorted, -2, 5));
  TEST_ASSERT_EQUAL_INT(-1, BinarySearch(test_array, 0, 6));
}

void test_GCD(void)
{
  TEST_ASSERT_EQUAL_INT(5, GCD(50,15));
  TEST_ASSERT_EQUAL_INT(3, GCD(1989,1590));
}
