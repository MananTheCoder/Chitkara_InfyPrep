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

void solve()
{
    set<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(2);
    // set<int>::iterator itr;
    for (int x : s)
    {
        cout << x << "\t";
    }
    cout << "\n";
}

int main()
{
    solve();
}