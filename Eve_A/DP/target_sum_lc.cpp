#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution
{
private:
    int helper(vi &nums, int target)
    {
        vi prev(target + 1, 0);
        prev[0] = 1;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            vi curr(target + 1);
            for (int t = 0; t <= target; t++)
            {
                int notTake = prev[t];
                int take = (nums[i - 1] <= t) ? prev[t - nums[i - 1]] : 0;
                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        if (target > sum || (sum - target) % 2 == 1)
        {
            return 0;
        }
        int diff = (sum - target) / 2;
        return helper(nums, diff);
    }
};