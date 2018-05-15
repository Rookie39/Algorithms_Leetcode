/*
 *Author: Rookie118
 *Title: Longest Substring Without Repeating Characters
 *Completion time: 2018-03-05
*/

//The first version
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag(256, -1);  //初始化ASCII所有字符的flag值为-1
        int start = 0;  //子字符串开始位置
        int longest = 0;
        int length = s.length();  //字符串长度
        for(int i = 0; i < length; ++i)
        {
            if(flag[s[i]] >= start) //表明第i个位置的字符已经在子串中出现
            {
                longest = max(longest, i - start);  //算出最长子串长度
                start = flag[s[i]] + 1;  //下一个子串开始的位置
            }
            flag[s[i]] = i;  //把i赋给第i个位置字符的标记值
        }
        return max(longest, length - start);  //跟最后一个子串长度比较大小
    }
};
