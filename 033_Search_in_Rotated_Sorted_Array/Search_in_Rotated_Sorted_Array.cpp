#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>

#define MININT -2147483648
#define MAXINT 2147483647

using namespace std;

class Solution {
public:
    int doSearch(int left, int right, vector<int>& nums, int target)
    {
        if(left < 0 || right > nums.size()-1 || left > right)
            return -1;
        if(left == right)
            return (nums[left] == target) ? left : -1;
        if(nums[left] == target)
            return left;
        if(nums[right] == target)
            return right;

        int mid = (left + right) / 2;
        int index = -1;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid+1] > nums[mid] && nums[mid-1] < nums[mid])
        {

            if(nums[mid+1] <= nums[right])
            {
                if(nums[mid+1] <= target && nums[right] >= target)
                    index = doSearch(mid+1, right, nums, target);
                else
                    index = doSearch(left, mid-1, nums, target);
            }
            else
            {
                if(nums[mid-1] >= target && nums[left] <= target)
                    index = doSearch(left, mid-1, nums, target);
                else
                    index = doSearch(mid+1, right, nums, target);
            }
        }
        else
        {
            if(target >= nums[left] && target <= nums[mid-1])
                index = doSearch(left, mid - 1, nums, target);
            if(target >= nums[mid+1] && target <= nums[right])
                index = doSearch(mid+1, right, nums, target);
        }
        return index;
    }

    int search(vector<int>& nums, int target) {
        if(!nums.size())
            return -1;
        if(nums.size() == 1)
            return (nums.front() == target) ? 0 : -1;
        if(nums.size() == 2)
        {
            if(nums.front() == target)
                return 0;
            else if(nums.back() == target)
                return 1;
            else
                return -1;
        }

        int result = doSearch(0, nums.size() - 1, nums, target);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7,9,1,4,6};
    int res = sol.search(nums, 8);

    cout << res << endl;
    return 0;
}
