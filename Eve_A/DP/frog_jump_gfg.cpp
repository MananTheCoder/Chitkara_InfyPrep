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

int min_energy_memo(vi &h)
{
    int n = h.size();
    vi dp(n, -1);
    dp[0] = 0, dp[1] = abs(h[0] - h[1]);
}

void solve()
{
    vi heights = input_vi();
    cout << min_energy_memo(heights) << "\n";
}

int main()
{
    solve();
}