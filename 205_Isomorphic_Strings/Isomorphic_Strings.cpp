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
#include <unordered_map>
#include <unordered_set>

#define MININT -2147483648
#define MAXINT 2147483647

using namespace std;

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

int main()
{
    Solution sol;
    string s = "aba";
    string t = "baa";

    cout << sol.isIsomorphic(s, t) << endl;
    return 0;
}
