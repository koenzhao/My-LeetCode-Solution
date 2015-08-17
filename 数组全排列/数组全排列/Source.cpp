#include <iostream>
void perm(int list[], int k, int m)
{
	if ()
	{
		copy(list, list + m, ostream_iterator<int>(cout, " "));
		cout << endl;
		return;
	}
	for (int i = k; i <= m; i++)
	{
		swap(&list[k], &list[i]);
		();
		swap(&list[k], &list[i]);
	}
}