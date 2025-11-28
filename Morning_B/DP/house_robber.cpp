#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

vector<int> input_vi()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vi(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
    v[0] = 10;
}

int max_profit_rec(vi &v, int i)
{
    if (i == 0)
    {
        return v[0];
    }
    if (i == 1)
    {
        return max(v[0], v[1]);
    }
    int take = v[i] + max_profit_rec(v, i - 2);
    int notTake = max_profit_rec(v, i - 1);
    return max(take, notTake);
}

int helper(vi &v, vi &memo, int i)
{
    if (memo[i] != -1)
    {
        return memo[i];
    }
    int take = v[i] + max_profit_rec(v, i - 2);
    int notTake = max_profit_rec(v, i - 1);
    return (memo[i] = max(take, notTake));
}

int max_profit_memo(vi &v)
{
    int n = v.size();
    vi memo(n, -1);
    memo[0] = v[0];
    memo[1] = max(v[0], v[1]);
    return helper(v, memo, n - 1);
}

int max_profit_tabulation(vi &v)
{
    int n = v.size();
    vi dp(n, -1);
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);
    for (int i = 2; i < n; i++)
    {
        int take = v[i] + dp[i - 2];
        int notTake = dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}

int max_profit_most_optimised(vi &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int n = nums.size();
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

void solve()
{
    vi nums = input_vi();
    cout << max_profit_tabulation(nums) << '\n';
}

int main()
{
    solve();
};