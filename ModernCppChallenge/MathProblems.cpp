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

// 2. Write a program that, given two positive integers, will calculate and print the greatest common divisor of the two.
int GreatestCommonDivisor(std::pair<int, int> numbers)
{
	int first = numbers.first;
	int second = numbers.second;
	if (first < second)
	{
		std::swap(first, second);
	}

	// Euclid's algorithm
	int remainder = 0;
	do
	{
		remainder = first % second;
		first = second;
		second = remainder;
	} while (remainder != 0);
	return first;
}