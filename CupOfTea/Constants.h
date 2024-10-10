#pragma once

#include <array>
#include <string_view>

inline constexpr uint32_t BASE_PRICE{ 100 };

inline constexpr uint32_t SUGAR_UNIT_PRICE{ 20 };
inline constexpr uint32_t MAX_SUGAR = { 4 };

inline constexpr uint32_t SWEETENER_UNIT_PRICE{ 20 };
inline constexpr uint32_t MAX_SWEETENER{ 4 };

inline constexpr uint32_t MILK_UNIT_PRICE{ 90 };

inline constexpr uint32_t CREAM_UNIT_PRICE{ 120 };

inline constexpr std::array<std::string_view, 6> AFFIRMATIVE_RESPONSES
{
	"yes",
	"yeah",
	"yup",
	"alright",
	"sure",
	"y"
};

inline constexpr std::array<std::string_view, 5> NEGATIVE_RESPONSES
{
	"no",
	"nah",
	"nope",
	"never",
	"n"
};

inline constexpr std::array<std::string_view, 6> INVALID_INTEGER_RESPONSES
{
	"Going to need a number there, champ.",
	"Want to try an integer, maybe?",
	"I think you might want to try a number here?",
	"Yeah no, gonna need an integer here. Try that again?",
	"I don't know what that means. Try again?",
	"Was I supposed to understand that? A number, please."
};

inline constexpr std::array<std::string_view, 6> INVALID_TEXT_RESPONSES
{
	"What? Was that a yes or a no?",
	"Didn't get that, chief. Yes or no, please.",
	"Say again? Yes? No?",
	"Huh? Yes? No?",
	"I don't know what that means. Yes or no?",
	"It's a yes or no question, mate. Want to try it again?"
};

enum class ResponseType : uint8_t
{
	Yes,
	No,
	Unknown
};