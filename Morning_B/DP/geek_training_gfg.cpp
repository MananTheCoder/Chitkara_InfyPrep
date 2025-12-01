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

int rec_helper(int day, int a, vvi &arr)
{
    if (day == 0)
    {
        return arr[0][a];
    }

    int ans = 0;
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (i == a)
        {
            continue;
        }
        ans = max(ans, rec_helper(day - 1, i, arr));
    }
    return arr[day][a] + ans;
}

int rec(vvi &arr)
{
    // Code here
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, rec_helper(arr.size() - 1, i, arr));
    }
    return ans;
}

int helper(int d, int a, vvi &arr, vvi &dp)
{
    if (dp[d][a] != -1)
    {
        return dp[d][a];
    }
    int ans = 0;
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (i == a)
        {
            continue;
        }
        ans = max(ans, rec_helper(d - 1, i, arr));
    }
    return (dp[d][a] = arr[d][a] + ans);
}

int memo(vvi &arr)
{
    int m = arr.size(), n = arr[0].size();
    vvi dp(m, vi(n, -1));
    forn(i, 3)
    {
        dp[0][i] = arr[0][i];
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, helper(arr.size() - 1, i, arr, dp));
    }
    return ans;
}

int tabulation(vvi &arr)
{
    int m = arr.size(), n = arr[0].size();
    vvi dp(m, vi(n, -1));
    forn(i, 3)
    {
        dp[0][i] = arr[0][i];
    }
    for (int d = 1; d < m; d++)
    {
        for (int a = 0; a < n; a++)
        {
            int temp = 0;
            forn(i, n)
            {
                if (i == a)
                {
                    continue;
                }
                temp = max(temp, dp[d - 1][i]);
            }
            dp[d][a] = arr[d][a] + temp;
        }
    }
    return *max_element(dp[m - 1].begin(), dp[m - 1].end());
}

int space_opt(vvi &arr)
{
    int m = arr.size(), A = arr[0].size();
    vi prev(A, -1);
    forn(i, 3)
    {
        prev[i] = arr[0][i];
    }
    for (int d = 1; d < m; d++)
    {
        vi curr(A);
        for (int a = 0; a < A; a++)
        {
            int temp = 0;
            forn(i, A)
            {
                if (i == a)
                {
                    continue;
                }
                temp = max(temp, prev[i]);
            }
            curr[a] = arr[d][a] + temp;
        }
        prev = curr;
    }
    return *max_element(prev.begin(), prev.end());
}

void solve()
{
    int d, a;
    cin >> d >> a;
    vvi matrix(d, vi(a));
    forn(i, d)
    {
        forn(j, a)
        {
            cin >> matrix[i][j];
        }
    }
    cout << memo(matrix) << "\n";
}

int main()
{
    solve();
}