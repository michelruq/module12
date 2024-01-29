#pragma once

#include <cstdint>

class Node
{
public:
	Node(std::uint32_t data) : mData{data}, mNextPtr{nullptr} {}
	std::uint32_t mData;
	Node* mNextPtr;
};