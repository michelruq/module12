#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList() : mHead{nullptr}
{
	
}

void LinkedList::Clear()
{
	Node* ptrForCurrentNode = mHead;
	Node* ptrForNextNode = ptrForCurrentNode;
	
	while(ptrForNextNode)
	{
		ptrForNextNode = ptrForCurrentNode->mNextPtr;
		delete ptrForCurrentNode;
		ptrForCurrentNode = ptrForNextNode;
	}
	
	mHead = nullptr;
}

LinkedList::~LinkedList()
{
	
}

void LinkedList::PushBack(std::uint32_t data)
{
	Node* ptrForNewNode = new Node(data);
	
	if(mHead == nullptr)
	{
		mHead = ptrForNewNode;
		return;
	}
		
	Node* last = mHead;
	while(last->mNextPtr != nullptr)
	{
		last = last->mNextPtr;  
	}
	
	last->mNextPtr = ptrForNewNode;
	return;
}

void LinkedList::PushFront(std::uint32_t data)
{
	Node* ptrForNewNode = new Node(data);
	
	ptrForNewNode->mNextPtr = mHead;
	
	mHead = ptrForNewNode;
}

void LinkedList::Insert(std::uint32_t position, std::uint32_t data)
{
	Node* ptrForNewNode = new Node(data);
	
	if(mHead == nullptr)
	{
		mHead = ptrForNewNode;
		
        return;
	}
	
	
	if(position == std::uint32_t{0})
	{
        ptrForNewNode->mNextPtr = mHead;
	
	    mHead = ptrForNewNode;
		
		return;
	}
	
	std::uint32_t currentPosition = std::uint32_t{0};
	
	Node* ptrForCurrentNode = mHead;

    while ((currentPosition < (position - std::uint32_t{1})) && (ptrForCurrentNode->mNextPtr != nullptr))	
	{
		currentPosition++;
		ptrForCurrentNode = ptrForCurrentNode->mNextPtr;
	}
	
	Node* ptrForNextNode = ptrForCurrentNode->mNextPtr;
	ptrForCurrentNode->mNextPtr = ptrForNewNode;
	ptrForNewNode->mNextPtr = ptrForNextNode;
	
}

void LinkedList::Show()
{
	Node* ptrForCurrentNode = mHead;
	while(ptrForCurrentNode != nullptr)
	{
		std::cout << ptrForCurrentNode->mData << " ";
		ptrForCurrentNode = ptrForCurrentNode->mNextPtr;
	}
}

void LinkedList::DeleteWithKey(std::uint32_t data)
{
    Node* ptrForCurrentNode = mHead;
	Node* ptrForPreviousNode = nullptr;
	
	if(ptrForCurrentNode && ptrForCurrentNode->mData == data)
	{
		mHead = ptrForCurrentNode->mNextPtr;
		delete ptrForCurrentNode;
		return;
	}
	
	while(ptrForCurrentNode && (ptrForCurrentNode->mData != data))
	{
		ptrForPreviousNode = ptrForCurrentNode;
		ptrForCurrentNode = ptrForCurrentNode->mNextPtr;
	};
	
	if(!ptrForCurrentNode)
	{
		return;
	}
	
	ptrForPreviousNode->mNextPtr = ptrForCurrentNode->mNextPtr;
	delete ptrForCurrentNode;
}

void LinkedList::DeleteInPosition(std::uint32_t position)
{
    Node* ptrForCurrentNode = mHead;
	Node* ptrForPreviousNode = nullptr;
	
	if(ptrForCurrentNode && (position == std::uint32_t{0}))
	{
		mHead = ptrForCurrentNode->mNextPtr;
		delete ptrForCurrentNode;
		return;
	}
	
	std::uint32_t currentPosition = std::uint32_t{0};
	
	while(ptrForCurrentNode && (position != currentPosition))
	{
		ptrForPreviousNode = ptrForCurrentNode;
		ptrForCurrentNode = ptrForCurrentNode->mNextPtr;
		currentPosition++;
	};
	
	if(!ptrForCurrentNode)
	{
		return;
	}
	
	ptrForPreviousNode->mNextPtr = ptrForCurrentNode->mNextPtr;
	delete ptrForCurrentNode;
}

