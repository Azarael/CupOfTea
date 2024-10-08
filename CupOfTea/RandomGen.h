//===============================================================
// RandomGen.h
//===============================================================
#pragma once

#include <random>
#include <concepts>

class RandomGen
{
public:
	RandomGen() :
		m_mersenne(m_rand_dev())
	{
	}

	template<std::integral T>
	T
		GetNextRandom(T max) noexcept
	{
		std::uniform_int_distribution<T> dist(0, max);

		return dist(m_mersenne);
	}

private:
	std::random_device m_rand_dev;
	std::mt19937 m_mersenne;
};