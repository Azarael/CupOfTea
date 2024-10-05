#include "Parsing.h"
#include "RandomGen.h"

#include <limits>
#include <string>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

RandomGen g_rnd{};

std::string_view
	get_invalid_text_reply()
{
	return INVALID_TEXT_RESPONSES[g_rnd.GetNextRandom<size_t>(INVALID_TEXT_RESPONSES.size() - 1)];
}

ResponseType
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


std::string_view
	get_invalid_int_reply()
{
	return INVALID_INTEGER_RESPONSES[g_rnd.GetNextRandom<size_t>(INVALID_INTEGER_RESPONSES.size() - 1)];
}

int
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

		std::println(cout, "{}", get_invalid_int_reply());
	}

	std::unreachable();
}

