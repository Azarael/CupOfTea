// CupOfTea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Constants.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;

static ResponseType
	parse_text_response()
{
	std::string text{};
	
	cin >> text;

	if (cin && !text.empty())
	{
		std::transform(text.begin(), text.end(), text.begin(),
			[](const char c) { return tolower(c); });

		for (auto aff_rsp : AFFIRMATIVE_RESPONSES)
		{
			if (text == aff_rsp)
				return ResponseType::Yes;
		}

		for (auto neg_rsp : NEGATIVE_RESPONSES)
		{
			if (text == neg_rsp)
				return ResponseType::No;
		}
	}

	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return ResponseType::Unknown;
}

static int
	get_integer()
{
	while (true)
	{
		int ret{};

		// receive input for age
		cin >> ret;

		bool valid = cin.good();

		// clear any failure bits to allow ignore to work
		cin.clear();
		// clear stream in case of any bad characters following the ones we extracted
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// check validity of input
		if (valid)
			return ret;

		std::println(cout, "Bad input. Please try again.");
	}

	std::unreachable();
}

uint32_t
	get_sugar_price()
{
	std::println(cout, "How many spoons of sugar?");
	std::println(cout, "(Up to {} spoons are allowed.)", MAX_SUGAR);

	int32_t sugar_count = get_integer();

	sugar_count = std::clamp(sugar_count, int32_t{}, static_cast<int32_t>(MAX_SUGAR));

	if (sugar_count > 0)
	{
		std::println(cout, "{} spoons of sugar at {}p each: {}p",
			sugar_count, SUGAR_UNIT_PRICE, sugar_count * SUGAR_UNIT_PRICE);
	}
	else
	{
		std::println(cout, "No sugars, then.");
	}

	return sugar_count * SUGAR_UNIT_PRICE;
}

// DRY violation but I don't have time
uint32_t
	get_sweetener_price()
{
	std::println(cout, "How many spoons of sweetener?");
	std::println(cout, "(Up to {} spoons are allowed.)", MAX_SWEETENER);

	int32_t sweet_count = get_integer();

	sweet_count = std::clamp(sweet_count, int32_t{}, static_cast<int32_t>(MAX_SWEETENER));

	if (sweet_count > 0)
	{
		std::println(cout, "{} spoons of sweetener at {}p each: {}p",
			sweet_count, SWEETENER_UNIT_PRICE, sweet_count * SWEETENER_UNIT_PRICE);
	}
	else
	{
		std::println(cout, "No sweetener either? Fine.");
	}

	return sweet_count * SWEETENER_UNIT_PRICE;
}

uint32_t
	get_milk_price()
{
	std::println(cout, "Any milk to be added?");

	auto rsp = parse_text_response();

	switch (rsp)
	{
	case ResponseType::Yes:
		std::println(cout, "One pot of milk, then, at {}p.", MILK_UNIT_PRICE);
		return MILK_UNIT_PRICE;
	case ResponseType::No:
		std::println(cout, "Okay, no milk.");
		return 0;
	default:
		std::println(cout, "Didn't quite get that. I'll assume it meant no.");
		return 0;
	}
}

uint32_t
	get_cream_price()
{
	std::println(cout, "Any cream to be added?");

	auto rsp = parse_text_response();

	switch (rsp)
	{
	case ResponseType::Yes:
		std::println(cout, "One pot of cream. {}{:.2f}.", 
			static_cast<char>(156), static_cast<float>(CREAM_UNIT_PRICE) * 0.01f);
		return CREAM_UNIT_PRICE;
	case ResponseType::No:
		std::println(cout, "Okay, no cream.");
		return 0;
	default:
		std::println(cout, "Didn't quite get that. I'll assume it meant no.");
		return 0;
	}
}

int main()
{
	ResponseType rsp{ ResponseType::Unknown };

	std::println(cout, "Cup of Tea-O-Matic v0.1.");

	std::println(cout, "Is tea required?");
	
	rsp = parse_text_response();

	switch (rsp)
	{
	case ResponseType::Yes:
		std::println(cout, "Great!");
		break;
	case ResponseType::No:
		std::println(cout, "Sure. Have a nice day.");
		return EXIT_SUCCESS;
	case ResponseType::Unknown:
		std::println(cout, "I didn't understand that response. Have a nice day.");
		return EXIT_SUCCESS;
	}
	
	std::println(cout, "The basic price of your tea will be {}{:.2f}.",
		static_cast<char>(156), BASE_PRICE * 0.01f);

	uint32_t price{ BASE_PRICE };

	auto sugar_price = get_sugar_price();

	price += sugar_price;

	if (sugar_price == 0) // sugar not requested
	{
		auto sweetener_price = get_sweetener_price();
		price += sweetener_price;
	}

	auto milk_price = get_milk_price();

	price += milk_price;

	auto cream_price = get_cream_price();

	price += cream_price;

	std::println(cout, "The final price of your tea will be {}{:.2f}.", 
		static_cast<char>(156), static_cast<float>(price) * 0.01f);

	std::println(cout, "Exiting in 5 seconds...");

	std::this_thread::sleep_for(std::chrono::seconds{ 5 });

	return EXIT_SUCCESS;
}