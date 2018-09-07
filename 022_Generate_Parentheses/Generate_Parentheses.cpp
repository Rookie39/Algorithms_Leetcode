#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string p = "()";

    bool isVaild(int &n1, int &n2)
    {
        if(n1 >= 0 && n2 >= 0 && n1 <= n2)
            return true;
        else
            return false;
    }

    void backtracking(string &temp, const int &n, int &n1, int &n2, vector<string> &result)
    {
        if(temp.length() == 2*n)
        {
            result.push_back(temp);
            return;
        }
        else
        {
            for(int i = 0; i < 2; ++i)
            {
                temp += p[i];
                if(!i)
                    --n1;
                else
                    --n2;
                if(isVaild(n1, n2))
                    backtracking(temp, n, n1, n2, result);
                if(!i)
                    ++n1;
                else
                    ++n2;
                temp.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        int n1 = n, n2 = n;

        if(n <= 0)
            return result;

        backtracking(temp, n, n1, n2, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> result;
    int n = 5;

    result = sol.generateParenthesis(n);
    for(size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}
