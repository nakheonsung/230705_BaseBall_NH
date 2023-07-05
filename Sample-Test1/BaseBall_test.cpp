#include "pch.h"
#include "../230705_BaseBall/BaseBall.cpp"

using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
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