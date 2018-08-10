/*
 *Author: Rookie118
 *Title: Median of Two Sorted Arrays
 *Completion time: 2018-03-07
*/

//The first version
//Time complexity: O((m+n)log(m+n))
//Space complexity: O(log(m+n))
class Solution {
public:
    void quicksort(vector<int>& nums, int left, int right)  //快速排序
    {
        int temp = nums[left], record;  //temp存储基准数      
        int i = left, j = right;
        if(left > right)  //表明快速排序完成
            return;
        
        while(i != j)  
        {
            while(nums[j] >= temp && i < j)  //从右往左找比基准数小的数
                --j;
            while(nums[i] <= temp && i < j)  //从左往右找比基准数大的数
                ++i;
            
            if(i < j)  //i和j不相等则交换对应的值
            {
                record = nums[i];
                nums[i] = nums[j];
                nums[j] = record;
            }
        }
        nums[left] = nums[i];  //i和j相等则将对应的值和基准数交换
        nums[i] = temp;
        
        quicksort(nums, left, i - 1);  
        quicksort(nums, i + 1, right);
        return;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        vector<int> nums;
        if(nums1.size() == 0 && nums2.size() == 0)  //两个数组都没数
            return 0;
        else if(nums1.size() == 0)  //数组1没数
        {
            if(nums2.size() % 2 == 0)  //数组个数为偶数
                median = (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
            else
                median = nums2[nums2.size() / 2];
            return median;
        }
        else if(nums2.size() == 0)  //数组2没数
        {         
            if(nums1.size() % 2 == 0)
                median = (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
            else
                median = nums1[nums1.size() / 2];
            return median;
        }
        else  //两个数组都有数
        {
            nums = nums1;
            for(int i = 0; i < nums2.size(); ++i)
                nums.push_back(nums2[i]);  //两个数组都存进一个数组中
            
            quicksort(nums, 0, nums.size() - 1);  //开始排序
            
            if(nums.size() % 2 == 0)
                median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
            else
                median = nums[nums.size() / 2];
            
            return median;    
        }  
    }
};

//The second version
