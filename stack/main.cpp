#include <iostream>
#include "stackarray.h"

constexpr const std::uint32_t ArraySize = static_cast<std::uint32_t>(10);

int main(int argc, char* argv[])
{
	std::cout << "start completed" << std::endl;
	StackArray oStackArray(ArraySize);
	for (std::uint32_t i{0}; i < (ArraySize); ++i)
	{
		if(oStackArray.push(i))
		{
			std::cout << "element has been added succesfully" << std::endl;
			std::cout << oStackArray.peek() << std::endl;
		}
		else
		{
			std::cout << "element has been added unsuccesfully" << std::endl;
		}
	}
	std::string result = (oStackArray.isFull())?"complete":"incomplete";
	std::cout << result << std::endl;
	for (std::uint32_t i{0}; i < ArraySize; ++i)
	{
		oStackArray.pop();
		std::cout << oStackArray.peek() << std::endl;
	}
	result = oStackArray.isEmpty()?"complete":"incomplete";
	std::cout << result << std::endl;
	return 0;
}