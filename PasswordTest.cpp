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
	ASSERT_TRUE(word.has_mixed_case("aAaAaA"));
}
TEST(PasswordTest, space_between_stuff) //is it happy about spaces within the password?
{
	Password word;
	ASSERT_TRUE(word.has_mixed_case("a     b    C   d"));
}

TEST(PasswordTest, only_weird_characters) //does it evaluate weird characters as false?
{
	Password word;
	ASSERT_FALSE(word.has_mixed_case("!@#*^_)+/<."));
}

TEST(PasswordTest, leet_Speek_True) //Is it happy with nums mixed in with chars?
{
	Password word;
	ASSERT_TRUE(word.has_mixed_case("4ppleP13"));
}
TEST(PasswordTest, leet_Speek_False)
{
	Password word;
	ASSERT_FALSE(word.has_mixed_case("4ppl3p13"));
}

TEST(PasswordTest, only_spaces) //Is it not happy with the password with the contents being only spaces?
{
	Password word;
	ASSERT_FALSE(word.has_mixed_case("            "));
} 
TEST(PasswordTest, newLine_broke_in_BUT_its_true) //if a new line somehow snuck into a correct passcode but it's still true, is it true?
{
	Password word;
	ASSERT_TRUE(word.has_mixed_case("dum '\n' IE")); //double check with prof about this line
}
TEST(PasswordTest, newLine_broke_in_AND_its_FALSE) //new line is in, and it's false
{
	Password word;
	ASSERT_FALSE(word.has_mixed_case("dum '\n' ie"));
}
TEST(PasswordTest, long_ass_password) //is it able to handle THE ENTIRE FUCKING KEYBOARD being used as a password?
{
	Password word;
	ASSERT_TRUE(word.has_mixed_case("QqWwEeRrTtYyUuIiOoPp{[}]|\\AaSsDdFfGgHhJjKkLl:;\"'ZzXxCcVvBbNnMm<,>./?`~!1@2#3$4%5^6&7*8(9)0_-+="));
}


/*TEST(PasswordTest, set_a_new_passcode_true) //can set put in a correct new passcode?
{
	Password word;
	//there has to be a better way to test if a string is correct!
	word.set("Ch40$_D3m0n");
	ASSERT_EQ("Ch40$_D3mon", );
}

TEST(PasswordTest, set_a_new_passcode_false) //can set realize that a passcode is false and therefore not set it?
{
	Password word;
	word.set("F00kM3S3r10usly");
	//fec how do I test this?!
}
*/

TEST(PasswordTest, psscode_less_than_eight) //can authenticate find a password whose length is less than eight?
{
	Password word;
	ASSERT_FALSE(word.authenticate("Dummy"));
}

TEST(PasswordTest, psscode_rep_bigger_than_three) //can authenticate find a passcode whose length is > 8 but also has 3 of the leading character
{
	Password word;
	ASSERT_FALSE(word.authenticate("CraCClingCreatures"));
}

TEST(PasswordTest, psscode_no_mixed_case) //can authenticate find a passcode whose length is > 8, has <3 of the leading character, BUT doesn't have mixed case?
{
	Password word;
	ASSERT_FALSE(word.authenticate("crackling"));
}

TEST(PasswordTest, psscode_original_passcode) //can authenticate find a passcode who is currently in the passcode history?
{
	Password word;
	ASSERT_FALSE(word.authenticate("ChicoCA-95929"));
}