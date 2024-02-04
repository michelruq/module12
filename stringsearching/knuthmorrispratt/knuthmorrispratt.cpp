#include "knuthmorrispratt.h"

void KnuthMorrisPratt::ComputeLPC(std::string pattern, std::uint32_t* lps)
{
	std::uint32_t j = 0;
	
	lps[0] = 0;
	
	std::uint32_t i = 1;
	
	while(i < pattern.size())
	{
		if(pattern[i] == pattern[j])
		{
			++j;
			lps[i] = j;
			++i;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				++i;
			}
		}
	}
}

void KnuthMorrisPratt::Search(const std::string& pattern, const std::string& text) 
{ 
    std::uint32_t * lps = new std::uint32_t[pattern.size()];

    ComputeLPC(pattern, lps); 
  
    int i = 0;  
    int j = 0; 
    while (i < text.size()) { 
        if (pattern[j] == text[i])
        { 
            j++; 
            i++; 
        } 
        if (j == pattern.size()) { 
            std::cout << "Found pattern at index" << i - j << std::endl; 
            j = lps[j - 1]; 
        } 
        else if (i < text.size() && pattern[j] != text[i]) { 
            if (j != 0)
            {
                j = lps[j - 1]; 
            }
            else
            {
                i = i + 1;
            }
        } 
    } 
	delete[] lps;
} 