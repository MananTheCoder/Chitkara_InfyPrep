#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007

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

int ways(int v, int n)
{
    if (n == 0)
    {
        return v == 0;
    }
    if (v == 0)
    {
        return 3 * ways(1, n - 1);
    }
    return 2 * ways(1, n - 1) + ways(0, n - 1);
}

int tabulation(int n)
{
    vvi dp(2, vi(n + 1));
    dp[0][0] = 1;
    dp[1][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = (3 * dp[1][i - 1]) % MOD;
        dp[1][i] = ((2 * dp[1][i - 1]) % MOD + dp[0][i - 1]) % MOD;
    }
    return dp[0][n];
}

int space_optimisation(int n)
{
    int home = 1, non = 0;

    for (int i = 1; i <= n; i++)
    {
        int curr1 = (3 * non) % MOD;
        int curr2 = ((2 * non) % MOD + home) % MOD;
        home = curr1, non = curr2;
    }
    return home;
}

void solve()
{
    int n;
    cin >> n;
    cout << space_optimisation(n) << "\n";
}

int main()
{
    solve();
}