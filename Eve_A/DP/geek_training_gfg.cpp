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

int rec(int d, int a, vvi &arr)
{
    if (d == 0)
    {
        return arr[d][a];
    }
    int max_score = 0;
    forn(i, arr[0].size())
    {
        if (i == a)
        {
            continue;
        }
        max_score = max(max_score, rec(d - 1, i, arr));
    }
    return (a == -1) ? max_score : max_score + arr[d][a];
}

int helper(int d, int a, vvi &arr, vvi &dp)
{
    if (dp[d][a] != -1)
    {
        return dp[d][a];
    }
    int max_score = 0;
    forn(i, arr[0].size())
    {
        if (i == a)
        {
            continue;
        }
        max_score = max(max_score, helper(d - 1, i, arr, dp));
    }
    dp[d][a] = (a == -1) ? max_score : max_score + arr[d][a];
    return dp[d][a];
}

int memo(vvi &arr)
{
    int D = arr.size(), A = arr[0].size();
    vvi dp(D, vi(A, -1));
    forn(i, A)
    {
        dp[0][i] = arr[0][i];
    }
    return helper(D, -1, arr, dp);
}

int tabulation(vvi &arr)
{
    int D = arr.size(), A = arr[0].size();
    vvi dp(D, vi(A, -1));
    forn(i, A)
    {
        dp[0][i] = arr[0][i];
    }
    for (int d = 1; d < D; d++)
    {
        forn(a, A)
        {
            int max_score = 0;
            forn(i, arr[0].size())
            {
                if (i == a)
                {
                    continue;
                }
                max_score = max(max_score, dp[d - 1][i]);
            }
            dp[d][a] = (a == -1) ? max_score : max_score + arr[d][a];
        }
    }
    return dp[D][-1];
}

int space_optimised(vvi &arr)
{
    int D = arr.size(), A = arr[0].size();
    vi prev(A, -1);
    forn(i, A)
    {
        prev[i] = arr[0][i];
    }
    for (int d = 1; d < D; d++)
    {
        vi curr(A);
        forn(a, A)
        {
            int max_score = 0;
            forn(i, arr[0].size())
            {
                if (i == a)
                {
                    continue;
                }
                max_score = max(max_score, prev[i]);
            }
            curr[a] = (a == -1) ? max_score : max_score + arr[d][a];
        }
        prev = curr;
    }
    return *max_element(prev.begin(), prev.end());
}

void solve()
{
    int D, A;
    cin >> D >> A;
    vvi v(D, vi(A));
    forn(i, D)
    {
        forn(j, A)
        {
            cin >> v[i][j];
        }
    }
    cout << space_optimised(v) << "\n";
}

int main()
{
    solve();
}