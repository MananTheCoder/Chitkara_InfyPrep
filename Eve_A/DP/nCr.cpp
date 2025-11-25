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

int fac(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return n * fac(n - 1);
}

int nCr_full_factorial(int n, int r)
{
    int val1 = fac(n), val2 = fac(r), val3 = fac(n - 3);
    cout << val1 << "\t" << val2 << '\t' << val3 << "\n";
    return val1 / (val2 * val3);
}

int ncr_faster(int n, int r)
{
    int ans = 1;
    if (r > n - r)
    {
        r = n - r;
    }
    forn(i, r)
    {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

void solve()
{
    // int n, r;
    // cin >> n >> r;
    // cout << ncr_faster(n, r) << "\n";
    int n = 42684200;
    cout << n << "\n";
    // cout << sizeof(int) << "\n";
}

int main()
{
    solve();
}