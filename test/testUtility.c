#include "testUtility.h"
#include "utility.h"

void test_Max3(void)
{
  TEST_ASSERT_EQUAL_INT(3, Max3(1,2,3));
  TEST_ASSERT_EQUAL_INT(3, Max3(3,1,2));
  TEST_ASSERT_EQUAL_INT(3, Max3(3,3,3));
}




