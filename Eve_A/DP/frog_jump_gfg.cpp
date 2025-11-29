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

int min_energy_rec(vi &h, int i)
{ // i is dest
    // fn will return min total energy to reach i from 0 index
    if (i == 0)
    {
        return 0;
    }
    if (i == 1)
    {
        return abs(h[0] - h[1]);
    }
    int one = abs(h[i] - h[i - 1]) + min_energy_rec(h, i - 1);
    int two = abs(h[i] - h[i - 2]) + min_energy_rec(h, i - 2);
    return min(one, two);
}

int helper(vi &h, vi &dp, int i)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int one = abs(h[i] - h[i - 1]) + helper(h, dp, i - 1);
    int two = abs(h[i] - h[i - 2]) + helper(h, dp, i - 2);
    return (dp[i] = min(one, two));
}

int min_energy_memo(vi &h)
{
    int n = h.size();
    vi dp(n, -1);
    dp[0] = 0, dp[1] = abs(h[0] - h[1]);
    return helper(h, dp, n - 1);
}

int min_energy_tabulation(vi &h)
{
    int n = h.size();
    vi dp(n, -1);
    dp[0] = 0, dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int one = abs(h[i] - h[i - 1]) + dp[i - 1];
        int two = abs(h[i] - h[i - 2]) + dp[i - 2];
        dp[i] = min(one, two);
    }
    return dp[n - 1];
}

int min_energy_space_optimised(vi &h)
{
    int n = h.size();
    int prev2 = 0, prev = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int one = abs(h[i] - h[i - 1]) + prev;
        int two = abs(h[i] - h[i - 2]) + prev2;
        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    vi heights = input_vi();
    cout << min_energy_tabulation(heights) << "\n";
}

int main()
{
    solve();
}