/**
  * Author: Rookie118
  * Title: Divide_Two_Integers
  * Completion time: 2018-09-22
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if((dividend == INT_MIN && divisor == -1) || divisor == 0)
            return INT_MAX;
        if(divisor == 1)
            return dividend;

        bool is_positive = ((dividend < 0) ^ (divisor < 0)) ? false : true;
        if(divisor == -1)
            return ((dividend < 0) ^ is_positive) ? dividend : -dividend;

        long long l_dividend = (dividend < 0) ? (0 - (long long)dividend) : (long long)dividend;
        long long l_divisor = (divisor < 0) ? (0 - (long long)divisor) : (long long)divisor;

        int result = 0;
        while(l_dividend >= l_divisor)
        {
            long long mul = 1;
            long long temp = l_divisor;
            while(l_dividend >= (temp << 1))
            {
                temp = temp << 1;
                mul = mul << 1;
            }
            l_dividend -= temp;
            result += mul;
        }
        return is_positive ? result : -result;
    }
};