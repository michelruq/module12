#include <iostream>

#include "stacklinkedlist.h"

StackLinkedList::StackLinkedList(std::uint32_t size) : mHead(nullptr), mCount(static_cast<std::int32_t>(-1)), mSize(size)
{

}

bool StackLinkedList::push (std::uint32_t data)
{
   Node* ptrForNewNode = new Node(data);
   Node* ptrForCurrentMode = mHead;
   
   if(mCount >= static_cast<std::int32_t>(mSize) )
   {
	   return false;
   }
   else
   {
	   if(ptrForCurrentMode == nullptr)
	   {
		   mHead = ptrForNewNode;
		   ++mCount;
		   return true;
	   }
	   
	   while(ptrForCurrentMode->mNextPtr)
	   {
		   ptrForCurrentMode = ptrForCurrentMode->mNextPtr;
	   }
	   
	   ptrForCurrentMode->mNextPtr = ptrForNewNode;
	   ++mCount;
	   return true;
   }
}

std::uint32_t  StackLinkedList::pop ()
{
   Node* ptrForCurrentMode = mHead;
   Node* ptrForPrviousMode = nullptr;
   
   if(ptrForCurrentMode == nullptr)
   {
	   return 0;	
   }
   
   if(ptrForCurrentMode->mNextPtr == nullptr)
   {
	   std::uint32_t temp = ptrForCurrentMode->mData;
	   delete ptrForCurrentMode;
	   ptrForCurrentMode = nullptr;
       mHead = nullptr;
       --mCount;	   
       return temp;	   
   }
   
   while(ptrForCurrentMode->mNextPtr)
   {
	   ptrForPrviousMode = ptrForCurrentMode;
	   ptrForCurrentMode = ptrForCurrentMode->mNextPtr;
   }
   
   std::uint32_t temp = ptrForCurrentMode->mData;
   delete ptrForCurrentMode;
   ptrForPrviousMode->mNextPtr = nullptr;
   --mCount;
   return temp;
}

std::uint32_t  StackLinkedList::peek ()
{
   Node* ptrForCurrentMode = mHead;
   Node* ptrForPrviousMode = ptrForCurrentMode;
   
   if(ptrForCurrentMode == nullptr)
   {
	   return 0;
   }

   while(ptrForCurrentMode)
   {
	   ptrForPrviousMode = ptrForCurrentMode;
	   ptrForCurrentMode = ptrForPrviousMode->mNextPtr;
   }

   return ptrForPrviousMode->mData;
}

bool  StackLinkedList::isFull()
{
	return (mCount < mSize);
}

bool  StackLinkedList::isEmpty()
{
    return (mCount == static_cast<std::int32_t>(-1));
}

void StackLinkedList::clear()
{
	Node* ptrForCurrentMode = mHead;
	Node* ptrForDeletedMode = nullptr;
	
    while(ptrForCurrentMode)
	{
		ptrForDeletedMode = ptrForCurrentMode;
		ptrForCurrentMode = ptrForDeletedMode->mNextPtr;
		std::cout << ptrForDeletedMode << std::endl;
		delete ptrForDeletedMode;
		ptrForDeletedMode = nullptr;
		delete mHead;
		mHead = nullptr;
	}
		
}

StackLinkedList::~StackLinkedList()
{
   clear();
}	