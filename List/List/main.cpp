#include <iostream>
#include "SingleList.h"
int main()
{
	Single_List<int> slist;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	slist.push_back(arr,(sizeof(arr)/sizeof(int)));
	slist.print();
	cout << "The 5 Node is: " << slist.GetNNode(5)->val << endl;
	return 0;
}