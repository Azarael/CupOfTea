#include "Constants.h"
#include "Parsing.h"

#include <iostream>
#include <algorithm>

using std::cout;

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

	ResponseType rsp{};

	do
	{
		rsp = parse_text_response();

		switch (rsp)
		{
		case ResponseType::Yes:
			std::println(cout, "One pot of milk, then, at {}p.", MILK_UNIT_PRICE);
			return MILK_UNIT_PRICE;
		case ResponseType::No:
			std::println(cout, "Okay, no milk.");
			return 0;
		default:
			std::println(cout, "{}", get_invalid_text_reply());
		}
	} while (rsp == ResponseType::Unknown);

	std::unreachable();
}

uint32_t
	get_cream_price()
{
	std::println(cout, "Any cream to be added?");

	ResponseType rsp{};

	do
	{
		rsp = parse_text_response();

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
			std::println(cout, "{}", get_invalid_text_reply());
		}
	} while (rsp == ResponseType::Unknown);

	std::unreachable();
}
