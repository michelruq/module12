#pragma once

#include <cstdint>
#include "node.h"

class StackLinkedList
{
	private:
       Node* mHead;
	   std::int32_t mCount;
	   std::uint32_t mSize;
	   
	   void clear();
	
	public:
	   StackLinkedList(std::uint32_t size);
	   
	   bool push (std::uint32_t data);
	   std::uint32_t pop ();
	   std::uint32_t peek ();
	   bool isFull();
	   bool isEmpty();

       ~StackLinkedList();	   
	
};