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
    vi v = input_vi();
    vector<int> modes;

    unordered_map<int, int> freq_map;
    for (int &ele : v)
    {
        freq_map[ele]++;
    }
    int max_freq = 0, num = v[0];
    for (pair<int, int> row : freq_map)
    {
        if (row.second > max_freq)
        {
            modes = vi({row.first});
            max_freq = max(max_freq, row.second);
        }
        else if (row.second == max_freq)
        {
            modes.push_back(row.first);
        }
    }
    print_vi(modes);
}

int main()
{
    solve();
}