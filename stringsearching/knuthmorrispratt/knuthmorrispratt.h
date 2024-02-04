#pragma once

#include <string>
#include <cstdint>
#include <iostream>

class KnuthMorrisPratt
{
	private:
	   void ComputeLPC(std::string pat, std::uint32_t* lps);
	
	public:
	   void Search(const std::string& pattern, const std::string& text);
	
};