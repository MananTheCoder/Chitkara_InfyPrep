#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// macros
#define forn(i, n) for (int i = 0; i < n; i++)

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void rotate_vec(vi &v)
{
    // take backup of last element
    int n = v.size();
    int temp = v[n - 1];

    // shift (n-1) elem ahead
    for (int i = n - 2; i >= 0; i--)
    {
        v[i + 1] = v[i];
    }

    // bring the last elem to first
    v[0] = temp;
}

void print_vi(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
}

// code to reverse vector
void solve()
{
    vi v = input_vector();
    rotate_vec(v);
    print_vi(v);
}

int main()
{
    solve();
}