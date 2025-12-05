#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
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
        // for (pair<const int, int> &row : adj_list[i])
        // {
        //     int neighbor = row.first, dist = row.second;
        //     cout << "\t" << neighbor << " -> " << dist << "\n";
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

umiusi get_adj_list(pivvi &graph)
{
    int v = graph.first;
    vvi edges = graph.second;
    umiusi adj_list;
    initialize_adj_list(adj_list, v);
    for (vi edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_list[start].insert(end);
        adj_list[end].insert(start);
    }
    return adj_list;
}

umiumii get_adj_list_w_ud(pivvi &graph)
{
    int v = graph.first;
    vvi edges = graph.second;
    umiumii adj_list;
    initialize_adj_list(adj_list, v);
    for (vi edge : edges)
    {
        int start = edge[0], end = edge[1], w = edge[2];
        adj_list[start][end] = w;
        adj_list[end][start] = w;
    }
    return adj_list;
}

void solve()
{
    // pivvi graph = dummy_graph();
    pivvi graph_w = dummy_graph();
    // umiusi adj_list = get_adj_list(graph);
    // print_umiusi(adj_list);
    umiumii adj_list = get_adj_list_w_ud(graph_w);
    print_umiumii(adj_list);
}

int main()
{
    solve();
}