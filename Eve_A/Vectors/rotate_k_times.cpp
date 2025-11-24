#include <bits/stdc++.h>
using namespace std;

vector<int> input_vec()
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

void print_vec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
}

void rotate_vec(vector<int> &v)
{
    int n = v.size();
    int temp = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        v[i + 1] = v[i];
    }
    v[0] = temp;
}

void rotate_k_times_acw(vector<int> &v, int k)
{
    //
}

void rotate_k_times_cw(vector<int> &v, int k) // O(n+k)
{
    int n = v.size();
    vector<int> backup(k);
    for (int i = 0; i < k; i++) // k
    {
        backup[i] = v[n - k + i];
    }

    // shift (n-k)elem to right
    for (int i = n - k - 1; i >= 0; i--) // (n-k)
    {
        v[i + k] = v[i];
    }

    // insert k elem at beginning
    for (int i = 0; i < k; i++) // k
    {
        v[i] = backup[i];
    }
}

void rotate_k_times_faster(vector<int> &v, int k)
{
    if (k < v.size() / 2)
    {
        rotate_k_times_cw(v, k);
        return;
    }
    rotate_k_times_acw(v, v.size() - k);
}

void solve()
{
    vector<int> v = input_vec();
    int k;
    cin >> k;
    rotate_k_times(v, k);
    print_vec(v);
}

int main()
{
    solve();
}