#pragma once

#include <string>
#include <cstdint>
#include <iostream>

class BoyerMoore
{
	private:
	   static constexpr std::uint32_t NumberOfChars = static_cast<std::uint32_t>(256);
	
       void BadCharHeuristic(std::string str, std::uint32_t size, std::uint32_t badchar[NumberOfChars]);
	
	public:
	   void Search(const std::string& pattern, const std::string& text);
	
};