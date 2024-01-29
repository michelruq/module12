#include <iostream>

#include "linkedlist.h"

LinkedList oLinkedList;

int main (int argc, char* argv[])
{
   std::uint32_t i{0};
   for(; i < 10; ++i)
   {
       oLinkedList.PushBack(i);
   }
   oLinkedList.Show();
   std::cout << std::endl;
   for(; i > 0; --i)
   {
       oLinkedList.PushFront(i);
   }
   oLinkedList.Show();
   std::cout << std::endl;
   for(; i < 38; ++i)
   {
	   if(i%2)
	   {
		   oLinkedList.Insert(i, i);
	   }
   }
   oLinkedList.Show();
   std::cout << std::endl;
   for(i = 0; i < 39; ++i)
   {
	   std::cout << "required remove " << i << std::endl;
	   oLinkedList.DeleteWithKey(i);
	   oLinkedList.Show();
       std::cout << std::endl;
   }
   for(i = 0; i < 7; ++i)
   {
	   std::cout << "required remove " << i << std::endl;
	   oLinkedList.DeleteInPosition(i);
	   oLinkedList.Show();
       std::cout << std::endl;
   }
   std::cout << "deletion " << std::endl;
   oLinkedList.DeleteInPosition(i);
   oLinkedList.Clear();
   std::cout << "complete " << std::endl;
   oLinkedList.Show();
   std::cout << std::endl;
   return 0;
}