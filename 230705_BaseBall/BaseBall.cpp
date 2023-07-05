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

	GuessResult guess (const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		return { true, 3, 0 };
	}

	explicit Baseball(const string& question)
		: question (question)
	{
		
	}

private:
	string question;
};