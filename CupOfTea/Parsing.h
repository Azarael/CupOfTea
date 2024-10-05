#pragma once

#include "Constants.h"

std::string_view
	get_invalid_text_reply();

ResponseType
	parse_text_response();

std::string_view
	get_invalid_int_reply();

int
	get_integer();