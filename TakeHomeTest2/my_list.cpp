//Michael Holwey

#include "my_list.h"

template<typename DataType>
my_list<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* prevPtr, ListNode* nextPtr)
{
	dataItem = nodeData;
	previous = prevPtr;
	next = nextPtr;
}

template<typename DataType>
my_list<DataType>::my_list()
{
	head = tail = NULL;
}

template<typename DataType>
my_list<DataType>::my_list(const my_list& other)
{
	head = tail = NULL;
	ListNode* temp = other.head;

	while(temp != NULL)
	{
		if(tail == NULL)
		{
			tail = new ListNode(temp->dataItem, NULL, NULL);
			head = tail;
		}
		else
		{
			ListNode* newNode = new ListNode(temp->dataItem, tail, NULL);
			tail->next = newNode;
			tail = newNode;
		}

		temp = temp->next;
	}
}

template<typename DataType>
my_list<DataType>& my_list<DataType>::operator=(const my_list& other)
{
	if(this != &other)
	{
		ListNode* temp = head;
		while(temp != NULL)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}

		temp = other.head;
		while(temp != NULL)
		{
			push_back(temp->dataItem);
			temp = temp->next;
		}
	}

	return *this;
}

template<typename DataType>
my_list<DataType>::~my_list()
{
	ListNode* temp = head;
	while(temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

template<typename DataType>
void my_list<DataType>::push_front(const DataType& newDataItem)
{
	if(head == NULL)
	{
		head = new ListNode(newDataItem, NULL, NULL);
		tail = head;
	}
	else
	{
		ListNode* newNode = new ListNode(newDataItem, NULL, head);
		head->previous = newNode;
		head = newNode;
	}
}

template<typename DataType>
DataType my_list<DataType>::pop_front() throw(logic_error)
{
	if(head == NULL)
		throw logic_error("LIST IS EMPTY.  CANNOT POP THE FRONT.");
	else if(head == tail)
	{
		ListNode* temp = head;
		delete head;
		head = tail = NULL;
		return temp->dataItem;
	}
	else
	{
		ListNode* temp = head->next;
		delete head;
		head = temp;
		head->previous = NULL;
		return temp->dataItem;
	}
}

template<typename DataType>
void my_list<DataType>::push_back(const DataType& newDataItem)
{
	if(tail == NULL)
	{
		tail = new ListNode(newDataItem, NULL, NULL);
		head = tail;
	}
	else
	{
		ListNode* newNode = new ListNode(newDataItem, tail, NULL);
		tail->next = newNode;
		tail = newNode;
	}
}

template<typename DataType>
DataType my_list<DataType>::pop_back() throw(logic_error)
{
	if(tail == NULL)
		throw logic_error("LIST IS EMPTY.  CANNOT POP BACK.");
	else if(tail == head)
	{
		ListNode* temp = tail;
		delete tail;
		tail = head = NULL;
		return temp->dataItem;
	}
	else
	{
		ListNode* temp = tail->previous;
		delete tail;
		tail = temp;
		tail->next = NULL;
		return temp->dataItem;
	}
}

template<typename DataType>
DataType my_list<DataType>::pop_before_back() throw(logic_error)
{
	if(tail == NULL)
		throw logic_error("LIST IS EMPTY.  CANNOT POP BEFORE BACK.");
	else if(head == tail)
		throw logic_error("ONLY ONE ELEMENT IN LIST.  CANNOT POP BEFORE BACK.");
	else if(head->next == tail)
	{
		delete head;
		head = tail;
	}
	else
	{
		ListNode* temp = tail->previous;
		DataType result = temp->dataItem;
		temp = temp->previous;
		temp->next = tail;
		tail->previous = temp;
		return result;
	}
}

template<typename DataType>
void my_list<DataType>::reverse()
{
	ListNode* temp = tail;
	ListNode* tempHead = NULL;
	ListNode* tempTail = NULL;

	while(temp != NULL)
	{
		if(tempTail == NULL)
		{
			tempTail = new ListNode(temp->dataItem, NULL, NULL);
			tempHead = tempTail;
		}
		else
		{
			ListNode* newNode = new ListNode(temp->dataItem, tempTail, NULL);
			tempTail->next = newNode;
			tempTail = newNode;
		}

		temp = temp->previous;
	}

	temp = head;
	while(temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}

	head = tempHead;
	tail = tempTail;
}

template<typename DataType>
void my_list<DataType>::show_list() const
{
	cout << "       List Structure" << endl;
	cout << "---------------------------" << endl;

	if(head == NULL)
		cout << "Empty List" << endl;
	else
	{
		ListNode* temp = head;
		while(temp != NULL)
		{
			cout << temp->dataItem << " ";
			temp = temp->next;
		}
	}
	cout << endl;
}

template<typename DataType>
void my_list<DataType>::show_list_mirror() const
{
	cout << "     List Structure (Mirror)" << endl;
	cout << "---------------------------------" << endl;

	if(head == NULL)
		cout << "Empty List" << endl;
	else
	{
		ListNode* temp = head;
		while(temp != NULL)
		{
			cout << temp->dataItem << " ";
			temp = temp->next;
		}

		temp = tail;
		while(temp != NULL)
		{
			cout << temp->dataItem << " ";
			temp = temp->previous;
		}
	}
	cout << endl;
}