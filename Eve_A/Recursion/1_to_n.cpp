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

void print_1_n(int n)
{
    if (n == 0)
    {
        return;
    }
    print_1_n(n - 1);
    cout << n << " ";
}

void solve()
{
    int n;
    cin >> n;
    print_1_n(n);
}

int main()
{
    solve();
}