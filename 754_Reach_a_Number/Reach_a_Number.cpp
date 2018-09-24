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

int main()
{
    Solution sol;

    cout << sol.reachNumber(7) << endl;
    return 0;
}
