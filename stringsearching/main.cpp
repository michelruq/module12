#include <iostream>
#include <string>
#include <cstdint>

#include "bruteforce.h"
#include "knuthmorrispratt.h"
#include "boyermoore.h"

int main(int argc, char* argv[])
{
	std::string txt = "abcabcabcabc";
	std::string pat = "abc";
	
	BruteForce oBruteForce;
	KnuthMorrisPratt oKnuthMorrisPratt;
	BoyerMoore oBoyerMoore;
	
	oBruteForce.Search(pat, txt);
    oKnuthMorrisPratt.Search(pat, txt);
	oBoyerMoore.Search(pat, txt);
	
	return 0;
}