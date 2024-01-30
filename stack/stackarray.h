#pragma once
#include <cstdint>

class StackArray
{
	private:
	    std::int32_t mTop;
		std::uint32_t mSize;
		std::uint32_t* pArray;
	
	public:
	   StackArray(std::uint32_t size);
	   
	   bool push (std::uint32_t data);
	   std::uint32_t pop ();
	   std::uint32_t peek ();
	   bool isFull();
	   bool isEmpty();

       ~StackArray();	   
	
};