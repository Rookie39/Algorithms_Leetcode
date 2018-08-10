/*
 *Author: Rookie118
 *Title: Longest Palindromic Substring
 *Completion time: 2018-03-09
*/   

//The first version
//Time complexity: O(n^3)
//Space complexity: O(1)
class Solution {
public:
    bool isPalindromic(string s, int length)  //判断字符串s是不是回文
    {
        for(int i = 0; i < length / 2; ++i)  //从字符串的前半段开始循环
        {
            if(s[i] != s[length - i - 1])  //如果两者不想等说明s不是回文
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string sub, max_str;
        int max_len = 0;
        
        if(s.size() < 2)  //s长度小于2，直接返回s
            return s;
        
        for(int i = 0; i < s.size(); ++i)  //从s第一个字符找到最后一个字符
            for(int j = s.size() - 1; j >= i; --j)  //从右往左遍历，直到找到s[i]等于s[j]
            {
                if(s[i] == s[j])  //说明第i个字符到第j个字符可能是回文子串
                {
                    sub = s.substr(i, j - i + 1);  //提取子串
                    if(isPalindromic(sub, j - i + 1))  //判断是否为回文子串
                    {
                        if(sub.size() == s.size())  //如果第一个子串长度和s长度相等，则直接返回s
                            return s;
                        if(max_len < j - i + 1)  //max_len小于子串长度，则max_len重新赋值
                        {
                            max_len = j - i + 1;
                            max_str = sub;  //max_str重新赋值
                        }   
                    }        
                }
            }
        return max_str;
    }
};

//The second version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    string getSubstr(string s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])  //扩展回文子串的长度
        {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
    
    string longestPalindrome(string s) {
        string max_sub, max_str, str1, str2;
        for(int start = 0; start < s.size(); ++start)
        {
            str1 = getSubstr(s, start, start);  //一位数查找
            str2 = getSubstr(s, start, start + 1);  //两位数查找
            max_str = (str1.size() > str2.size()) ? str1 : str2; 
            max_sub = (max_sub.size() < max_str.size()) ? max_str : max_sub;
        }
        return max_sub;
    }
};
