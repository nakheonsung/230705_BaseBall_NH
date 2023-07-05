#include <stdexcept>

using namespace std;
class Baseball
{
public:
	void guess (const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch < '0' || ch > '9')
			{
				throw length_error("Must be Number.");
			}
		}

		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2])
		{
			throw length_error("Must not have the same number.");
		}
	}
};