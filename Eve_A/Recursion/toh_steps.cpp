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

int toh_steps(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return 2 * toh_steps(n - 1) + 1;
}

void solve()
{
    int n;
    cin >> n;
    cout << toh_steps(n) << "\n";
}

int main()
{
    solve();
}