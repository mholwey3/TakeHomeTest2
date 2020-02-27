//Michael Holwey

#include "my_list.cpp"

int main()
{
	my_list<int> list1;

	list1.push_back(1);
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(4);
	list1.push_back(2);

	list1.show_list_mirror();
	cout << endl;
	cout << endl;

	list1.reverse();

	list1.show_list();
	cout << endl;
	cout << endl;

	try
	{
		list1.pop_before_back();
	}
	catch(exception e)
	{
		cout << e.what() << endl;
	}

	list1.show_list();
	cout << endl;
	cout << endl;
}