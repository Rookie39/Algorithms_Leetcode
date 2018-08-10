/*
 *Author: Rookie118
 *Title: String to Integer
 *Completion time: 2018-03-12
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    int myAtoi(string str) {
        bool flag_neg = false, flag_num = false;  //负数标记，数字标记
        vector<int> nums;
        int result = 0, count = 0, temp, record, division = 1;

        if(str.size() == 0)
            return 0;

        for(int i = 0; i < str.size(); ++i)
        {
            if((str[i] > '9' || str[i] < '0') && str[i] != ' ' && str[i] != '-' && str[i] != '+')  //第一个非空字符不是数字也不是+-号，则返回0
                return 0;
            else if(str[i] == '-' && (str[i+1] > '9' || str[i+1] < '0'))  //第一个非空字符为-号，且下一个字符不为数字，则返回0
                return 0;
            else if(str[i] == '+' && (str[i+1] > '9' || str[i+1] < '0'))  //第一个非空字符为+号，且下一个字符不为数字，则返回0
                return 0;
            if(str[i] >= '0' && str[i] <= '9')
            {
                nums.push_back(str[i] - '0');  
                flag_num = true;  //数字标记为真
            }
            if(str[i-1] == '-' && flag_num)  //判断是否为负数
                flag_neg = true;
            if((str[i+1] > '9' || str[i+1] < '0') && flag_num)  //判断数字序列是否结束
                break;
        }

        for(int j = 0; j < nums.size(); ++j)
        {
            count = nums.size() - j - 1;  //计算位数
            division = 1;  //被除数重置
            if(flag_neg) 
                temp = record = -nums[j];
            else
                temp = record = nums[j];
            while(count)
            {
                temp *= 10;
                division *= 10;
                if(flag_neg && temp % 10 != 0)  //检测乘积过程中负数溢出
                {
                        return INT_MIN;
                }
                else if(temp % 10 != 0)  //检测乘积过程中正数溢出
                {
                        return INT_MAX;
                }
                --count;
            }
            result += temp;
            if(result / division % 10 != record)  //检测最终求和溢出
            {
                if(flag_neg)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        return result;
    }
};
