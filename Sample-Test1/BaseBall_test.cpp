#include "pch.h"
#include "../230705_BaseBall/BaseBall.cpp"

using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game {"123"};
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalid)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, Solved3Strike)
{
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, 2Strike0Ball)
{
	GuessResult result = game.guess("124");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, 1Strike2Ball)
{
	GuessResult result = game.guess("321");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, 1Strike1Ball)
{
	GuessResult result = game.guess("325");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(1, result.balls);
}

TEST_F(BaseballFixture, 0Strike3Ball)
{
	GuessResult result = game.guess("231");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(3, result.balls);
}