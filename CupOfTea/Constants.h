#pragma once

#include <array>
#include <string_view>

inline constexpr uint32_t BASE_PRICE{ 150 };

inline constexpr uint32_t SUGAR_UNIT_PRICE{ 20 };
inline constexpr uint32_t MAX_SUGAR = { 4 };

inline constexpr uint32_t SWEETENER_UNIT_PRICE{ 20 };
inline constexpr uint32_t MAX_SWEETENER{ 4 };

inline constexpr uint32_t MILK_UNIT_PRICE{ 90 };

inline constexpr uint32_t CREAM_UNIT_PRICE{ 120 };

inline constexpr std::array<std::string_view, 5> AFFIRMATIVE_RESPONSES
{
	"yes",
	"yeah",
	"alright",
	"sure",
	"y"
};

inline constexpr std::array<std::string_view, 4> NEGATIVE_RESPONSES
{
	"no",
	"nah",
	"nope",
	"n"
};

enum class ResponseType : uint8_t
{
	Yes,
	No,
	Unknown
};