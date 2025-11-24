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

void print_vi(vi &v) // O(n)
{
    forn(i, v.size())
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
}

void rotate_vec(vi &v) // O(n)
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

void rotate_k_times(vi &v, int k)
{
    while (k--)
    {
        rotate_vec(v);
    }
}

void rotate_k_times_faster(vi &v, int k) // O(n+k)
{
    // take backup of last k elem
    int n = v.size(); // 1
    k %= n;
    vi backup(k);                   // 1
    for (int i = n - k; i < n; i++) // k * 1 = k
    {
        backup[i - (n - k)] = v[i];
    }

    // shift (n-k) elem right
    for (int i = n - k - 1; i >= 0; i--) // (n-k)
    {
        v[i + k] = v[i];
    }

    // insert k elem at beginning
    for (int i = 0; i < k; i++) // O(k)
    {
        v[i] = backup[i];
    }
}

// juggling algo
// TC: O(N), SC: O(1)

void solve()
{
    vi v = input_vector();
    int k;
    cin >> k;
    rotate_k_times_faster(v, k);
    print_vi(v);
}

int main()
{
    solve();
}