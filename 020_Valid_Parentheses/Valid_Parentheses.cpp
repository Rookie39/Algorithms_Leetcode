/*
 *Author: Rookie118
 *Title: Valid Parentheses
 *Completion time: 2018-03-17
*/

//The first version
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;  //模拟栈
        char record;  //记录栈顶退出的元素
        
        if(s.length() < 2)  //排除无效输入
            return false;

        for(int i = s.length()-1; i >= 0; --i)  //从右往左遍历
        {
            if(s[i] != '(' && s[i] != '[' && s[i] != '{')  //是]，}，) 符号则压入栈中
                stack.push_back(s[i]);
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')  //是(，[，{符号则弹出栈
            {
                if(stack.size() == 0)  //栈中没有元素则表明是无效输入
                    return false;
                record = stack.back();
                stack.pop_back();
                if((s[i] == '(' && record != ')') || (s[i] == '[' && record != ']') || (s[i] == '{' && record != '}'))
                    return false;  //括号不匹配则表明是无效输入
            }   
        }
        if(stack.size() != 0)  //栈中还有元素则表明是无效输入
            return false;
        else
            return true; 
    }
};
