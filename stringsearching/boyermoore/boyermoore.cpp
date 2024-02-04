#include <algorithm>

#include "boyermoore.h"

void BoyerMoore::BadCharHeuristic(std::string str, std::uint32_t size, std::uint32_t badchar[NumberOfChars])
{
    std::uint32_t i;
 
    for (i = 0; i < NumberOfChars; i++)
	{
        badchar[i] = -1;
	}

    for (i = 0; i < size; i++)
	{
        badchar[static_cast<std::uint32_t>(str[i])] = i;
	}
}

void BoyerMoore::Search(const std::string& pattern, const std::string& text)
{
	std::uint32_t m = pattern.size();
	std::uint32_t n = text.size();
	
	std::uint32_t badchar[NumberOfChars];
	
	BadCharHeuristic(pattern, m, badchar);
	
	std::uint32_t s = static_cast<std::uint32_t>(0);
	while(s <= (n - m))
	{
		int j = m - static_cast<std::uint32_t>(1);
		
		while (j >= 0 && pattern[j] == text[s + j])
		{
            --j;
		}
		
		if (j < 0)
        {
            std::cout << "pattern occurs at shift = " << s << std::endl;

            s += (s + m < n) ? m - badchar[text[s + m]] : 1;

        }
        else
        {
            int bc = badchar[text[s + j]];
            s += std::max(1, j - bc);
        }
	}
	
}