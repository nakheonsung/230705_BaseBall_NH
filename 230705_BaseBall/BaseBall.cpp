#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{

	}

	bool isDuplicateNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw length_error("Must be Number.");
		}

		if (isDuplicateNumber(guessNumber))
		{
			throw length_error("Must not have the same number.");
		}
	}

	GuessResult CheckBall(const string& guessNumber)
	{
		int nStrike = 0;
		int nBall = 0;
		for (int i=0; i<=2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (guessNumber[i] == question[j])
				{
					if (i == j)
					{
						nStrike++;
						break;
					}
					nBall++;
					break;
				}
			}
		}
		return {false, nStrike, nBall };
	}

	GuessResult guess (const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}
		else
		{
			return CheckBall(guessNumber);
		}		
	}

private:
	string question;
};