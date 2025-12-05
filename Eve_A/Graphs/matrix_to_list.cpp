#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<int, vvi> pivvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, usi> umiusi;
typedef unordered_map<int, umii> umiumii;

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

void print_umiusi(umiusi &adj_list)
{
    for (pair<const int, usi> &row : adj_list)
    {
        int start = row.first;
        usi &neighbors = row.second;
        cout << start << " :\t";
        for (int neighbor : neighbors)
        {
            cout << neighbor << ", ";
        }
        cout << "\n";
    }
}

void print_umiumii(umiumii &adj_list)
{
    forn(i, adj_list.size())
    {
        cout << i << " :\n";
        for (auto [neighbor, dist] : adj_list[i])
        {
            cout << "\t" << neighbor << " -> " << dist << "\n";
        }
    }
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}};
    vvi edges_w = {{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5, 4}, {2, 6, 5}, {3, 6, 6}, {4, 5, 7}, {0, 0, 8}};
    pivvi graph = {v, edges}, graph_weighted = {v, edges_w};
    return graph_weighted;
}

void initialize_adj_list(umiusi &adj_list, int v)
{
    forn(i, v)
    {
        adj_list[i] = usi();
    }
}

void initialize_adj_list(umiumii &adj_list, int v)
{
    forn(i, v)
    {
        adj_list[i] = umii();
    }
}

vvi get_adj_matrix_ud_uw(pivvi &graph)
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

vvi get_adj_matrix_d_w(pivvi &graph)
{
    int v = graph.first;
    vvi edges = graph.second;
    vvi adj_matrix(v, vi(v, 0));
    for (vi edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = edge[2];
    }
    return adj_matrix;
}

void convert_matrix_to_list(vvi &adj_matrix, umiusi &adj_list)
{ // ud & uw
    int n = adj_matrix.size();
    initialize_adj_list(adj_list, n);
    forn(start, n)
    {
        forn(end, n)
        {
            if (adj_matrix[start][end] == 1)
            {
                adj_list[start].insert(end);
            }
        }
    }
}

void convert_matrix_to_list(vvi &adj_matrix, umiumii &adj_list)
{
    // d & w
    int v = adj_matrix.size();
    initialize_adj_list(adj_list, v);
    forn(start, v)
    {
        forn(end, v)
        {
            if (adj_matrix[start][end] != 0)
            {
                adj_list[start][end] = adj_matrix[start][end];
            }
        }
    }
}

void solve()
{
    pivvi graph_w = dummy_graph();
    vvi adj_matrix_w = get_adj_matrix_d_w(graph_w);
    umiumii adj_list;
    convert_matrix_to_list(adj_matrix_w, adj_list);
    print_umiumii(adj_list);
}

int main()
{
    solve();
}