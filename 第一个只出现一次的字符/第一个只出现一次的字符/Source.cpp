#include <iostream>
//#include <stdlib.h>
using namespace std;

char FindFirstOne(char* input)
{
	if (input == NULL)
		return NULL;
	char *check = (char*)calloc(128,sizeof(char));
	int i = 0;
	while (*input != '\0')
	{
		i = *input;
		check[i]++;
		input++;
	}
	for (int j = 0; j < 128; ++j)
	{
		if (check[j] == 1)
			return j;
	}
	return NULL;
}

int main()
{
	char* c = "ttbbccjjrkkppss";
	char res = FindFirstOne(c);
	cout << res << endl;
	return 0;
}