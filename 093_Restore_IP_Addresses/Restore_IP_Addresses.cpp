/**
  * Author: Rookie118
  * Title: Restore_IP_Addresses
  * Completion time: 2018-09-15
 */

class Solution {
public:
    bool isVaild(string &ip)
    {
        if((ip.length() == 3 && ip > "255") || (ip.length() > 1 && ip.front() == '0') || ip.length() == 0 || ip.length() > 3)
            return false;
        return true;
    }

    void backtracking(int cn, int pos, string &s, string &temp, vector<string> &result)
    {
        if(cn == 3)
        {
            string rest = s.substr(pos);
            if(isVaild(rest))
            {
                temp.append(s.substr(pos));
                result.push_back(temp);
                temp.erase(temp.rfind("."));
                return;
            }
            return;
        }

        string lip;
        size_t len = s.length() - pos > 3 ? 3 : s.length() - pos;
        for(size_t j = pos; j < pos+len; ++j)
        {
            lip.clear();
            lip.assign(s, pos, j-pos+1);
            temp.append(lip);
            if(isVaild(lip))
            {
                temp.append(".");
                backtracking(++cn, j+1, s, temp, result);
                --cn;
            }
            temp.erase(temp.rfind(lip));
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.length() < 4)
            return result;

        string temp;
        backtracking(0, 0, s, temp, result);
        return result;
    }
};