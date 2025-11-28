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