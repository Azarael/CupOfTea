// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Constants.h"
#include "Pricing.h"
#include "Tea.h"

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;

int 
	main()
{
	ResponseType rsp{ ResponseType::Unknown };

	std::println(cout, "Cup of Tea-O-Matic v0.1.");

	if (!requires_tea())
		return EXIT_SUCCESS;

	std::println(cout, "The basic price of your tea will be {}{:.2f}.",
		static_cast<char>(156), BASE_PRICE * 0.01f);

	uint32_t price{ BASE_PRICE };

	price += get_sugar_price();

	if (price == BASE_PRICE) // sugar not requested
		price += get_sweetener_price();

	price += get_milk_price();
	price += get_cream_price();

	std::println(cout, "The final price of your tea will be {}{:.2f}.", 
		static_cast<char>(156), static_cast<float>(price) * 0.01f);

	make_tea();

	std::println(cout, "Exiting in 5 seconds...");

	std::this_thread::sleep_for(std::chrono::seconds{ 5 });

	return EXIT_SUCCESS;
}