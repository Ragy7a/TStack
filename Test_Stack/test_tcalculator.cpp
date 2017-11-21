#pragma once
#include "../Stack/TCalculator.h"
#include "../Stack/TCalculator.cpp"
#include "gtest.h"

TEST(TCalculator, can_create_object_of_TCalculator) 
{
	ASSERT_NO_THROW(TCalculator("(2+2)*5"));
}
