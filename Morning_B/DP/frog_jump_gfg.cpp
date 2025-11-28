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

// int min_energy_rec(vi &heights, int i)
// {
//     if (i == 0)
//     {
//         return 0;
//     }
//     if (i == 1 && heights.size() > 1)
//     {
//         return abs(heights[0] - heights[1]);
//     }
//     int one = abs(heights[i] - heights[i - 1]) + min_energy_rec(heights, i - 1);
//     int two = abs(heights[i] - heights[i - 2]) + min_energy_rec(heights, i - 2);
//     return min(one, two);
// }

// int helper(int i, vi &heights, vi &memo)
// {
//     if (heights[i] != -1)
//     {
//         return heights[i];
//     }
//     int one = abs(heights[i] - heights[i - 1]) + helper(i - 1, heights, memo);
//     int two = abs(heights[i] - heights[i - 2]) + helper(i - 2, heights, memo);
//     return (memo[i] = min(one, two));
// }

// int min_energy_memoization(vi &heights)
// {
//     if (heights.size() == 1)
//     {
//         return 0;
//     }
//     vi memo(heights.size(), -1);
//     memo[0] = 0, memo[1] = abs(heights[1] - heights[0]);
//     return helper(heights.size() - 1, heights, memo);
// }

int min_energy_rec(vi &h, int i) // i is the index of destination
{
    if (i == 0)
    {
        return 0;
    }
    if (i == 1)
    {
        return abs(h[0] - h[1]);
    }
    int first = abs(h[i] - h[i - 1]) + min_energy_rec(h, i - 1);
    int two = abs(h[i] - h[i - 2]) + min_energy_rec(h, i - 2);
    return min(first, two);
}

int helper(vi &h, vi &memo, int i)
{
    if (memo[i] != -1)
    {
        return memo[i];
    }
    int first = abs(h[i] - h[i - 1]) + min_energy_rec(h, i - 1);
    int two = abs(h[i] - h[i - 2]) + min_energy_rec(h, i - 2);
    return (memo[i] = min(first, two));
}

int min_energy_memo(vi &h)
{
    vi memo(h.size(), -1);
    memo[0] = 0, memo[1] = abs(h[0] - h[1]);
    return helper(h, memo, h.size() - 1);
}

int min_energy_tabulation(vi &h)
{
    int n = h.size();
    vi dp(n, -1);
    dp[0] = 0, dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int first = abs(h[i] - h[i - 1]) + dp[i - 1];
        int two = abs(h[i] - h[i - 2]) + dp[i - 2];
        dp[i] = min(first, two);
    }
    return dp[n - 1];
}

int min_energy_space_optimised(vi &h)
{
    int n = h.size();
    int prev2 = 0, prev1 = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int first = abs(h[i] - h[i - 1]) + prev1;
        int two = abs(h[i] - h[i - 2]) + prev2;
        int curr = min(first, two);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

void solve()
{
    vi heights = input_vi();
    cout << min_energy_space_optimised(heights) << "\n";
}

int main()
{
    solve();
}