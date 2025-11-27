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

int min_energy_rec(vi &heights, int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (i == 1 && heights.size() > 1)
    {
        return abs(heights[0] - heights[1]);
    }
    int one = abs(heights[i] - heights[i - 1]) + min_energy_rec(heights, i - 1);
    int two = abs(heights[i] - heights[i - 2]) + min_energy_rec(heights, i - 2);
    return min(one, two);
}

int helper(int i, vi &heights, vi &memo)
{
    if (heights[i] != -1)
    {
        return heights[i];
    }
    int one = abs(heights[i] - heights[i - 1]) + helper(i - 1, heights, memo);
    int two = abs(heights[i] - heights[i - 2]) + helper(i - 2, heights, memo);
    return (memo[i] = min(one, two));
}

int min_energy_memoization(vi &heights)
{
    if (heights.size() == 1)
    {
        return 0;
    }
    vi memo(heights.size(), -1);
    memo[0] = 0, memo[1] = abs(heights[1] - heights[0]);
    return helper(heights.size() - 1, heights, memo);
}

void solve()
{
    vi heights = input_vi();
    cout << min_energy_memoization(heights) << "\n";
}

int main()
{
    solve();
}