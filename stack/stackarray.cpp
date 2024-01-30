#include "stackarray.h"

StackArray::StackArray(std::uint32_t size) : mTop(static_cast<std::int32_t>(-1)), mSize(size)
{
	pArray = new std::uint32_t[mSize];
}

bool StackArray::push (std::uint32_t data)
{
	if(!isFull())
	{
		++mTop;
		pArray[mTop] = data;
		return true;
	}
	else
	{
		return false;
	}
}

std::uint32_t  StackArray::pop ()
{
	if(!isEmpty())
	{
		std::uint32_t temp = pArray[mTop];
		--mTop;
		return temp;
	}
	else
	{
		return static_cast<std::uint32_t>(0);
	}
}

std::uint32_t  StackArray::peek ()
{
    if(!isEmpty())
	{
		std::uint32_t temp = pArray[mTop];
		return temp;
	}
	else
	{
		return static_cast<std::uint32_t>(0);
	}
}

bool  StackArray::isFull()
{
	return (mTop >= static_cast<std::int32_t>(mSize - static_cast<std::uint32_t>(1)));
}

bool  StackArray::isEmpty()
{
	return (mTop < static_cast<std::int32_t>(0));
}

StackArray::~StackArray()
{
    delete[] pArray;
}	