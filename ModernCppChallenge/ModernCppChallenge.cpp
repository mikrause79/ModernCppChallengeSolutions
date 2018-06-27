#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <cstdlib>

using namespace std::literals;

// Problems
int SumOfNaturalsDivisibleBy3And5(int limit);
int GreatestCommonDivisor(std::pair<int,int> numbers);

int PromptForInteger(std::string_view promptText)
{
	for (;;)
	{
		std::cout << promptText << ": ";
		int userInput;
		if (std::cin >> userInput)
		{
			std::cout << std::endl;
			return userInput;
		}
		else
		{
			// Discard if bad data.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

auto PromptForIntegers(std::pair<std::string_view, std::string_view> prompts)
{
	auto first = PromptForInteger(prompts.first);
	auto second = PromptForInteger(prompts.second);
	return std::make_pair(first, second);
}

struct MenuItem
{
	std::string_view description;
	std::function<void()> invoke;
};

MenuItem mainMenu[] =
{
	{ "Sum of naturals divisible by 3 and 5"sv, []() { std::cout << SumOfNaturalsDivisibleBy3And5(PromptForInteger("Limit"sv)) << std::endl; } },
	{ "Greatest common divisor"sv, []() { std::cout << GreatestCommonDivisor(PromptForIntegers({"First"sv, "Second"sv})) << std::endl; } },
	{ "Quit"sv, [](){}}
};

void PrintMenu()
{
	std::cout << std::endl;
	std::cout << "Problems" << std::endl;
	std::cout << "--------" << std::endl;
	int index = 1;
	for (auto const& menuItem : mainMenu)
	{
		std::cout << index << ". " << menuItem.description << std::endl;
		index++;
	}
}

int main()
{
	int selection = 0;
	do
	{
		PrintMenu();
		selection = PromptForInteger("Selection"sv) - 1;
		if ((selection >= 0) && (selection < (_countof(mainMenu))))
		{
			mainMenu[selection].invoke();
		}
	} while (selection != (_countof(mainMenu) - 1));
    return 0;
}

