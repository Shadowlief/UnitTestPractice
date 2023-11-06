/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

 //begin of count_leading_characters testing

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, rotating_case_password) //does it say there's only 1 case zZ?
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("zZ"));
	
}

TEST(PasswordTest, only_dupes_at_start) //does it get mad if there's a repeat ala "zoo?"
{
	Password word;
	ASSERT_EQ(1, word.count_leading_characters("Zoo"));
}

TEST(PasswordTest, empty_string) //does it get mad if there's nothing in the string?
{
	Password word;
	ASSERT_EQ(1, word.count_leading_characters(""));
}

//end of count_leading_characters tests
//begin has_mixed_case testing
TEST(PasswordTest, all_one_letter) //does it get mad if we have something like aAaA?
{
	Password word;
	ASSERT_TRUE();
}
Test(PasswordTest, ) //is it happy about