#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		for (it_vec = nums.begin(); it_vec != nums.end(); ++it_vec)
		{
			if ((it_map = nums_map.find(*it_vec)) == nums_map.end())
			{
				nums_map[*it_vec] = 1;
			}
			else
			{
				++it_map->second;
			}
		}
		for (it_map = nums_map.begin();it_map!=nums_map.end();++it_map)
		{
			if (it_map->second == 1)
				return it_map->first;
		}
		return NULL;
	}

private:
	vector<int>::iterator it_vec;
	map<int, int> nums_map;
	map<int, int>::iterator it_map;
};


int main()
{
	int arr[] = { 3, 5, 5, 6, 6, 2, 2, 4 ,4};
	int result = 0;
	vector<int> nums(arr,arr+9);
	vector<int>::iterator it_nums;
	Solution sol;
	result = sol.singleNumber(nums);
	cout << result<< endl;
	return 0;
}