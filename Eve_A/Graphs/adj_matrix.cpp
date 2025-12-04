#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, vvi> pivvi;

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

pivvi dummy_graph()
{
    int v = 7;
    vvi edges = {{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}};
    return {v, edges};
}

vvi get_adj_matrix(pivvi &dummy_graph)
{
    //
}

void solve()
{
    pivvi graph = dummy_graph();
    vvi adj_matrix = get_adj_matrix(dummy_graph);
}

int main()
{
    solve();
}