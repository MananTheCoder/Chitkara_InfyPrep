#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

void print_vvi(vvi &medals)
{
    for (vi &row : medals)
    {
        print_vi(row);
    }
}

bool my_olympic_comparator(vi &first, vi &sec)
{
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != sec[i])
        {
            return (first[i] > sec[i]);
        }
    }
    return true;
}

void olympic_rankings(vvi &medals)
{
    sort(medals.begin(), medals.end(), my_olympic_comparator);
}

void solve()
{
    vvi medals = {
        {12, 5, 7},
        {3, 8, 2},
        {15, 4, 9},
        {9, 11, 1},
        {14, 7, 3},
        {9, 2, 10},
        {4, 13, 6},
        {9, 11, 8},
        {7, 9, 5},
        {10, 6, 12}};
    olympic_rankings(medals);
    print_vvi(medals);
}

int main()
{
    solve();
}