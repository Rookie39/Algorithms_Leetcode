/*
 *Author: Rookie118
 *Title: Two Sum
 *Completion time: 2018-03-01
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for(int i = 0; i < nums.size() - 1; ++i)  //遍历前nums.size() - 1个数
        {
            for(int j = i + 1; j < nums.size(); ++j)  //遍历后nums.size() - i - 1个数
            {
                if(nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        if(indices.size() == 0)
            return indices;
    }
};

/*
 *Author: Rookie118
 *Title: Two Sum
 *Completion time: 2018-03-18
*/

//The second version
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  //存储nums值和对应的序号的键值对
        vector<int> result;
        
        for(int i = 0; i < nums.size(); ++i) 
        {
            if(mp.find(target - nums[i]) != mp.end())  //找到另外一个加数，则存储两个加数的对应序号
            {
                result.push_back(mp[target - nums[i]]);
                result.push_back(i);
                break;
            }
            mp[nums[i]] = i;  //对mp进行初始化
        }
        return result;
    }
};
