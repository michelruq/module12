#include <iostream>
#include "stacklinkedlisttop.h"

StackLinkedListTop::StackLinkedListTop() : mRoot(nullptr)
{
	
}

bool StackLinkedListTop::push(std::uint32_t x)
{
	Node* newObject = new Node(x);
    newObject->mNextPtr = mRoot;
    mRoot = newObject;
    return true;
}

std::uint32_t StackLinkedListTop::pop()
{
	std::uint32_t temp = mRoot->mData;
    Node* pointerForDeletion = mRoot;
    mRoot = pointerForDeletion->mNextPtr;
    delete pointerForDeletion;
    pointerForDeletion = nullptr;
    return temp;
}

std::uint32_t StackLinkedListTop::peek()
{
	if(mRoot)
	   return mRoot->mData; 
    else
	   return 0;
}

bool StackLinkedListTop::isEmpty()
{
	return (mRoot == nullptr);
}

StackLinkedListTop::~StackLinkedListTop()
{
	Node* temp = mRoot;
	Node* pointerForDeletion = mRoot;
	
	while(temp)
	{
		pointerForDeletion = temp;
		temp = temp->mNextPtr;
		delete pointerForDeletion;
		pointerForDeletion = nullptr;
		std::cout << temp << std::endl;
	}
}