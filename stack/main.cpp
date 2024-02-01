#include <iostream>
#include "stackarray.h"
#include "stacklinkedlist.h"
#include "stacklinkedlisttop.h"

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
		std::cout << oStackArray.pop() << "    ";
		std::cout << oStackArray.peek() << std::endl;
	}
	result = oStackArray.isEmpty()?"complete":"incomplete";
	std::cout << result << std::endl;
	
	StackLinkedList oStackLinkedList(ArraySize);
	for (std::uint32_t i{0}; i < (ArraySize); ++i)
	{
		if(oStackLinkedList.push(i))
		{
			std::cout << "element has been added succesfully" << std::endl;
			std::cout << oStackLinkedList.peek() << std::endl;
		}
		else
		{
			std::cout << "element has been added unsuccesfully" << std::endl;
		}
	}
	result = (oStackLinkedList.isFull())?"complete":"incomplete";
	std::cout << result << std::endl;
	oStackLinkedList.show();
	result = (oStackLinkedList.find(5))?"found":"not found";
	std::cout << result << std::endl;
	result = (oStackLinkedList.find(15))?"found":"not found";
	std::cout << result << std::endl;
	for (std::uint32_t i{0}; i < (ArraySize); ++i)
	{
		std::cout << oStackLinkedList.pop() << "    ";
		std::cout << oStackLinkedList.peek() << std::endl;
	}
	result = oStackLinkedList.isEmpty()?"complete":"incomplete";
	std::cout << result << std::endl;
	
	StackLinkedListTop oStackLinkedListTop;
	for (std::uint32_t i{0}; i < (ArraySize); ++i)
	{
		if(oStackLinkedListTop.push(i))
		{
			std::cout << "element has been added succesfully" << std::endl;
			std::cout << oStackLinkedListTop.peek() << std::endl;
		}
		else
		{
			std::cout << "element has been added unsuccesfully" << std::endl;
		}
	}
	result = "complete";
	std::cout << result << std::endl;
	for (std::uint32_t i{0}; i < (ArraySize); ++i)
	{
		std::cout << oStackLinkedListTop.pop() << "    ";
		std::cout << oStackLinkedListTop.peek() << std::endl;
	}
	result = oStackLinkedListTop.isEmpty()?"complete":"incomplete";
	std::cout << result << std::endl;
	
	return 0;
}