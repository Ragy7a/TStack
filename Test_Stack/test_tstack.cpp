#include "..\Stack\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack <int> bf);
}
