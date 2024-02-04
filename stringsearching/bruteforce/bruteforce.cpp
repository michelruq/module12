#include "bruteforce.h"

void BruteForce::Search(const std::string& pattern, const std::string& text)
{
	std::uint32_t m = pattern.size();
	std::uint32_t n = text.size();
	
	std::uint32_t j;
	for(std::uint32_t i {static_cast<std::uint32_t>(0)}; i < (n - m); )
	{
		std::cout << i << std::endl;
		for(j = static_cast<std::uint32_t>(0); j < m; ++j)
		{
			if(text[j+i] != pattern[j])
			{
				break;
			}
		}
		if(j == m)
		{
		   std::cout << "Pattern found at index" << i << std::endl;
		   i += m;
		}
		else if(j == 0)
		{
			++i;
		}
		else
		{
			i +=j;
		}
		
	}
}
