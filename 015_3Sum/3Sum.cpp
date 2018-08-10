/*
 *Author: Rookie118
 *Title: 3Sum
 *Completion time: 2018-03-17
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)  //排除无效输入
            return result;

        std::sort(nums.begin(), nums.end());  //对数组进行从小到大排序
        if(nums.front() > 0)  //最小数大于0，则不存在3数相加为0
            return result;
        
        for(int i = 0; i < nums.size(); ++i)  //第一个数遍历数组
        {
            int left = i + 1;  //第二个数
            int right =  nums.size() - 1;  //第三个数
            
            while(left < right) 
            {
                if(nums[left] + nums[right] < -nums[i])  //第二个数、第三个数之和小于第一个数则说明第二个数小了
                    ++left;
                else if(nums[left] + nums[right] > -nums[i])  //大于第一个数则第三个数大了
                    --right;
                else
                {
                    vector<int> temp(3, 0);  //记录符合条件的三个数
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    result.push_back(temp);  
                
                    while(left < right && nums[left] == temp[1])  //跳过相同的第二个数
                        ++left;
                    while(left < right && nums[right] == temp[2])  //跳过相同的第三个数
                        --right;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i])  //跳过相同的第一个数
                ++i;
        }
        return result;   
    }
};
