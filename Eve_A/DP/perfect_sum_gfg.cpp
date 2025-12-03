#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

int rec(int i, vi &v, int target)
{
    if (i == -1)
    {
        return target == 0;
    }
    // int count = 0;
    // if (target==v[i]) {
    //     count++;
    // }
    int notTake = rec(i - 1, v, target);
    int take = (v[i] <= target) ? rec(i - 1, v, target - v[i]) : 0;
    return notTake + take;
}

int helper(int i, vi &v, int target, vvi &dp)
{
    if (dp[i + 1][target] != -1)
    {
        return dp[i + 1][target];
    }
    int notTake = helper(i - 1, v, target, dp);
    int take = (v[i] <= target) ? helper(i - 1, v, target - v[i], dp) : 0;
    return (dp[i + 1][target] = notTake + take);
}

int memo(vi &v, int target)
{
    int n = v.size();
    vvi dp(n + 1, vi(target + 1, -1));
    dp[0][0] = 1;
    forn(i, target)
    {
        dp[0][i + 1] = 0;
    }
    return helper(v.size() - 1, v, target, dp);
}

int tabulation(vi &v, int target)
{
    int n = v.size();
    vvi dp(n + 1, vi(target + 1, -1));
    dp[0][0] = 1;
    forn(i, target)
    {
        dp[0][i + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notTake = dp[i - 1][t];                               // not Take
            int take = (v[i - 1] <= t) ? dp[i - 1][t - v[i - 1]] : 0; // Take, if possible
            dp[i][t] = notTake + take;
        }
    }
    return dp[n][target];
}

int space_optimisation(vi &v, int target)
{
    int n = v.size();
    vi prev(target + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vi curr(target + 1, 0);
        for (int t = 0; t <= target; t++)
        {
            int notTake = prev[t];                               // not Take
            int take = (v[i - 1] <= t) ? prev[t - v[i - 1]] : 0; // Take, if possible
            curr[t] = notTake + take;
        }
        prev = curr;
    }
    return prev[target];
}

void solve()
{
    vi v = input_vi();
    int target;
    cin >> target;
    cout << tabulation(v, target) << "\n";
}

int main()
{
    solve();
}