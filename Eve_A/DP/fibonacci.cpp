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

int fib_recursive(int n)
{
    if (n < 2)
    {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int helper(int i, vi &memo)
{
    if (memo[i] != -1)
    {
        return memo[i];
    }
    return (memo[i] = helper(i - 1, memo) + helper(i - 2, memo));
}

int fib_memo(int n)
{
    vi memo(n + 1, -1);
    memo[0] = 0, memo[1] = 1;
    return helper(n, memo);
}

int fib_tabulation(int n)
{
    vi dp(n + 1, -1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_space_optimised(int n)
{
    int prev2 = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    int n;
    cin >> n;
    cout << fib_tabulation(n) << "\n";
}

int main()
{
    solve();
}