#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
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

void print_vvi(vvi &v)
{
    for (vi &x : v)
    {
        print_vi(x);
    }
}

void print_neighbors(vi &v) // O(V)
{
    forn(i, v.size())
    {
        if (v[i])
        {
            cout << i << "\t";
        }
    }
    cout << "\n";
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}};
    return {v, edges};
}

vvi get_adj_matrix(pivvi &graph) // O(E)
{
    int v = graph.first;
    vvi edges = graph.second;
    vvi adj_matrix(v, vi(v, 0));
    for (vi edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = 1;
        adj_matrix[end][start] = 1;
    }
    return adj_matrix;
}

void dfs_helper(int s, vvi &adj_matrix, vb &visited) // O(V+E)
{
    visited[s] = true;
    cout << s << "\t";
    forn(neighbor, adj_matrix.size())
    {
        // cout << s << " : ";
        // print_neighbors(adj_matrix[s]);
        if (adj_matrix[s][neighbor] == 1 && !visited[neighbor])
        {
            dfs_helper(neighbor, adj_matrix, visited);
        }
    }
}

void dfs(vvi &adj_matrix) // O(V+E)
{
    int v = adj_matrix.size();
    vb visited(v, false);
    forn(i, v) // V *
    {
        if (visited[i] == false)
        {
            dfs_helper(i, adj_matrix, visited);
        }
    }
    cout << "\n";
}

void solve()
{
    pivvi graph = dummy_graph();
    vvi adj_matrix = get_adj_matrix(graph);
    // print_vvi(adj_matrix);
    // cout << "\n\n";
    dfs(adj_matrix);
}

int main()
{
    solve();
}