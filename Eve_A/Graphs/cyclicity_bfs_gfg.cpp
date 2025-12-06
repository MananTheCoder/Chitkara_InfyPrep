#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, usi> umiusi;
typedef pair<int, int> pii;

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
    bool bfs_helper(umiusi &adj_list, int start, vb &visited, int parent)
    {
        queue<pii> nodes_queue;
        nodes_queue.push({start, -1});
        visited[start] = true;
        while (!nodes_queue.empty())
        {
            pii curr = nodes_queue.front();
            nodes_queue.pop();
            for (int neighbor : adj_list[curr.first])
            {
                if (visited[neighbor] && neighbor != curr.second)
                {
                    return true;
                }
                if (!visited[neighbor])
                {
                    nodes_queue.push({neighbor, curr.first});
                    visited[neighbor] = true;
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
                bfs_helper(adj_list, i, visited, -1))
            {
                return true;
            }
        }
        return false;
    }
};