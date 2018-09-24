/**
  * Author: Rookie118
  * Title: Isomorphic_Strings
  * Completion time: 2018-09-24
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, char> mp1, mp2;
        string temp;
        for(size_t i = 0; i < s.length(); ++i)
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        for(size_t i = 0; i < t.length(); ++i)
        {
            temp.push_back(mp1[s[i]]);
        }

        if(mp1.size() == mp2.size() && temp == t)
            return true;
        else
            return false;
    }
};