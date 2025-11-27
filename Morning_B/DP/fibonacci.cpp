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

int helper(vi &memo, int n)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

int fib_memoized(int n)
{
    vi memo(n + 1, -1);
    memo[0] = 0, memo[1] = 1;
    return helper(memo, n);
    // return 1;
}

int fib_tabulation(int n)
{
    vi dp(n + 1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_space_optimised(int n)
{
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = curr + prev;
        prev = curr;
        curr = temp;
    }
    return curr;
}

void solve()
{
    int n;
    cin >> n;
    cout << fib_space_optimised(n) << '\n';
}

int main()
{
    solve();
}