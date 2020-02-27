//Michael Holwey

#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdexcept> 
#include <iostream>

using namespace std;

template<typename DataType>
class my_list
{
	public:

		my_list();
		my_list(const my_list& other);
		my_list& operator=(const my_list& other);
		~my_list();

		void push_front(const DataType& newDataItem);
		DataType pop_front() throw(logic_error);
		void push_back(const DataType& newDataItem);
		DataType pop_back() throw(logic_error);

		DataType pop_before_back() throw(logic_error);
		void reverse();
		void show_list_mirror() const;
		
		void show_list() const;

	private:

		class ListNode
		{
			public:

				ListNode(const DataType& nodeData, ListNode* prevPtr, ListNode* nextPtr);

				DataType dataItem;
				ListNode* next;
				ListNode* previous;
		};

		ListNode* head;
		ListNode* tail;
};
#endif