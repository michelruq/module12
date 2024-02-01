#pragma once

#include <cstdint>
#include "node.h"

class StackLinkedListTop
{
	private:
       Node* mRoot;
	
	public:
	   StackLinkedListTop();
	   
	   bool push (std::uint32_t data);
	   std::uint32_t pop ();
	   std::uint32_t peek ();
	   bool isEmpty();

       ~StackLinkedListTop();	   
	
};
