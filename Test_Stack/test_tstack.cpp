#include "..\Stack\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack <int> s(10));
}

TEST(TStack, cant_create_stack_with_too_large_length)
{
  ASSERT_ANY_THROW(TStack <int> s(MAX_STACK_SIZE));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack <int> s(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack <int> s(10);

  ASSERT_NO_THROW(TStack <int> s1(s));
}
