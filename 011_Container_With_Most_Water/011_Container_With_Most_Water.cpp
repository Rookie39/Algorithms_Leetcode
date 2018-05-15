/*
 *Author: Rookie118
 *Title: Container With Most Water
 *Completion time: 2018-03-12
*/

//The first version
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int lower = 0, result = 0;
        
       while(left < right)
       {
           lower = (height[left] < height[right]) ? height[left] : height[right];  //找两条线中更矮的线
           result = (lower * (right - left) > result) ? lower * (right - left) : result;  //计算面积
           if(height[left] < height[right])  //两线之中更矮的线横坐标进行位移
               ++left;
           else
               --right;
       }
       
        return result;
    }
};
