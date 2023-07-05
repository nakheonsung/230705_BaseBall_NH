#include "pch.h"
#include "../230705_BaseBall/BaseBall.cpp"

using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), length_error);
}