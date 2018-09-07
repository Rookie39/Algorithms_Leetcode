class Solution {
public:
    string countAndSay(int n) {
        string str_result;
        string temp;

        if(n < 1)
            return str_result;
        if(n == 1)
        {
            str_result = "1";
            return str_result;
        }

        str_result = countAndSay(--n);
        int count = 1;
        size_t i;
        for(i = 0; i < str_result.length() - 1; ++i)
        {
            if(str_result[i] == str_result[i+1])
            {
                ++count;
            }
            else
            {
                temp.push_back('0'+count);
                temp.push_back(str_result[i]);
                count = 1;
            }
        }
        temp.push_back('0'+count);
        temp.push_back(str_result[i]);
        return temp;
    }
};