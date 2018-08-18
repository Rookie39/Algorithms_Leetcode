#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return nums.size();
		}

		for (int i = 0, j = 1; i < nums.size() && j < nums.size();)
		{
			if (nums[i] == nums[j])
			{
				nums.erase(nums.begin() + j);
				continue;
			}
			else
			{
				++i;
				++j;
			}
		}
		return nums.size();
	}
};

int main()
{
	vector<int> test = { 0,0,1,1,1,2,2,3,3,4 };
	//vector<int> test = { 1,1,2 };
	Solution sol;
	sol.removeDuplicates(test);

	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}