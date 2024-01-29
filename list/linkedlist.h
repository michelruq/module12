#pragma once

#include "node.h"

class LinkedList
{
private:
    Node* mHead;

public:	
	LinkedList();
	void PushBack(std::uint32_t data);
	void PushFront(std::uint32_t data);
	void Insert(std::uint32_t position, std::uint32_t data);
	void Show();
	void DeleteWithKey(std::uint32_t data);
	void DeleteInPosition(std::uint32_t position);
	void Clear();
	
	~LinkedList();
};
