/*
 *Author: Rookie118
 *Title: Longest Common Prefix
 *Completion time: 2018-03-12
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "", record = "";
        
        if(strs.size() == 0)  
            return "";
        if(strs.size() == 1)
            return strs[0];
        for(int i = 0; i < strs.size(); ++i)  //一组字符串中有一个字符串长度为0，则表明无公共前缀
        {
            if(strs[i].size() == 0)
                return "";
        }
        
        for(int i = 0; i < strs[0].size(); ++i)
        {
            prefix = strs[0].substr(0, i+1);
            for(int j = 1; j < strs.size(); ++j)
            {
                if(prefix.size() > strs[j].size())  //大于某个字符串长度则表明已找到最长公共前缀
                    return record;
                if(prefix != strs[j].substr(0, i+1))  //不想等则表明已找到最长公共前缀
                    return record;
            }
            record = prefix;
        }
        return record;       
    }
};
