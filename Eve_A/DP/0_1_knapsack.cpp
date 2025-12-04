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

int rec(int i, int W, vi &wt, vi &val)
{
    if (i == 0)
    {
        return (wt[0] <= W) ? val[0] : 0;
    }
    int notTake = rec(i - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[i] <= W)
    {
        take = rec(i - 1, W - wt[i], wt, val) + val[i];
    }
    return max(take, notTake);
}

int helper(int i, int W, vi &wt, vi &val, vvi &dp)
{
    if (i == 0)
    {
        return (wt[0] <= W) ? val[0] : 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    int notTake = rec(i - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[i] <= W)
    {
        take = rec(i - 1, W - wt[i], wt, val) + val[i];
    }
    return (dp[i][W] = max(take, notTake));
}

int memo(int W, vi &wt, vi &val)
{
    vvi dp(wt.size(), vi(W + 1, -1));
    return helper(wt.size() - 1, W, wt, val, dp);
}

int tabulation(int W, vi &wt, vi &val)
{
    vvi dp(wt.size(), vi(W + 1, -1));
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }
    for (int i = 1; i < wt.size(); i++)
    {
        forn(j, W + 1)
        {
            int take = (wt[i] > j) ? INT_MIN : dp[i - 1][j - wt[i]] + val[i];
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[val.size() - 1][W];
}

int space_optimisation(int W, vi &wt, vi &val)
{
    int n = wt.size();
    vi prev(W + 1, 0);
    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        vi curr(W + 1);
        forn(j, W + 1)
        {
            int take = (wt[i] > j) ? INT_MIN : prev[j - wt[i]] + val[i];
            int notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}

void solve()
{
    int n, W;
    cin >> n >> W;
    vi wt(n), val(n);
    forn(i, n)
    {
        cin >> wt[i];
    }
    forn(i, n)
    {
        cin >> val[i];
    }
    cout << memo(W, wt, val) << "\n";
}

int main()
{
    solve();
}