/**
  * Author: Rookie118
  * Title: Reach_a_Number
  * Completion time: 2018-09-24
 */

class Solution {
public:
    int reachNumber(int target) {
        int sum = 0;
        int step_cn = 0;
        int steps = 1;
        target = target > 0 ? target : -target;

        while(sum != target)
        {
            sum += steps;
            ++step_cn;
            if(sum > target)
            {
                int dis = sum - target;
                if(dis % 2 == 0)
                    break;
            }
            ++steps;
        }
        return step_cn;
    }
};