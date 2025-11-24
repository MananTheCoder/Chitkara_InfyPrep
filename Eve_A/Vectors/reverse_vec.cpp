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

void reverse_vec(vector<int> &v)
{
    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        swap(v[++l], v[--r]);
    }
}

void solve()
{
    vector<int> v = input_vec();
    reverse_vec(v);
    print_vec(v);
}

int main()
{
    solve();
}