#include "Constants.h"
#include "Parsing.h"
#include "Tea.h"

#include <iostream>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;

bool
	requires_tea()
{
	ResponseType rsp{ ResponseType::Unknown };

	std::println(cout, "Is tea required?");

	rsp = parse_text_response();

	switch (rsp)
	{
	case ResponseType::Yes:
		std::println(cout, "Great!");
		return true;
	case ResponseType::No:
		std::println(cout, "Sure. Have a nice day.");
		return false;
	default:
		std::println(cout, "I didn't understand that response.\nCome back again when you know what you'd like.\nHave a great day!");
		return false;
	}
}

void
	make_tea()
{
	std::println(cout, "Just making your tea, please wait a few seconds...");

	std::this_thread::sleep_for(std::chrono::seconds{ 3 });

	std::print(cout, "Here you go:\n\n");

	// tea by Elissa Potier: ASCII Art Archive.

	std::print(cout,
		"    (  )   (   )  )\n"
		"     ) (   )  (  (\n"
		"     ( )  (    ) )\n"
		"     _____________\n"
		"    <_____________> ___\n"
		"    |             |/ _ \\\n"
		"    |               | | |\n"
		"    |               |_| |\n"
		" ___|             |\\___/\n"
		"/    \\___________/    \\\n"
		"\\_____________________/\n"
	);
}