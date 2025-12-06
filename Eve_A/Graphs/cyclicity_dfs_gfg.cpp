#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, usi> umiusi;

class Solution
{
private:
    void populate_adj_list(umiusi &adj_list, vvi &edges)
    {
        for (vi &edge : edges)
        {
            adj_list[edge[0]].insert(edge[1]);
            adj_list[edge[1]].insert(edge[0]);
        }
    }
    void initialise_adj_list(umiusi &adj_list, int V)
    {
        forn(i, V) { adj_list[i] = usi(); }
    }
    bool detectCyclicityDFS(int s, umiusi &adj_list, vb &visited, int parent)
    {
        visited[s] = true;
        for (int neighbor : adj_list[s])
        {
            if (visited[neighbor] && neighbor != parent)
            {
                return true;
            }
            if (!visited[neighbor])
            {
                if (detectCyclicityDFS(neighbor, adj_list, visited, s))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vvi &edges)
    {
        umiusi adj_list;
        initialise_adj_list(adj_list, V);
        populate_adj_list(adj_list, edges);
        vb visited(V, false);

        forn(i, V)
        {
            if (!visited[i] &&
                detectCyclicityDFS(i, adj_list, visited, -1))
            {
                return true;
            }
        }
        return false;
    }
};