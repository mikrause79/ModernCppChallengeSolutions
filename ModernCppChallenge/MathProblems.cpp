#include <numeric>

// 1. Write a program that calculates and prints the sum of all the natural numbers divisible by either 3 or 5, up to a given limit entered by a user.
int SumOfNaturalsDivisibleBy3And5(int limit)
{
	// A for loop and if/else is definitely clearer; using std::accumulate to exercise more modern C++ knowldege.
	return std::accumulate(1, limit, 0, [](int currentSum, int naturalNumber)
	{
		return currentSum + ((((naturalNumber % 3) == 0) || ((naturalNumber % 5) == 0)) ? naturalNumber : 0);
	}
}