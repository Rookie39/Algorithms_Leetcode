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