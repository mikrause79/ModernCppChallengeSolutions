#include <numeric>

// 1. Write a program that calculates and prints the sum of all the natural numbers divisible by either 3 or 5, up to a given limit entered by a user.
int SumOfNaturalsDivisibleBy3And5(int limit)
{
	int sum = 0;
	for (int naturalNumber = 1; naturalNumber <= limit; naturalNumber++)
	{
		if (((naturalNumber % 3) == 0) || ((naturalNumber % 5) == 0))
		{
			sum += naturalNumber;
		}
	}
	return sum;
}