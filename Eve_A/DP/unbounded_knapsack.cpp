#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int W)
    {
        // this is for 0-1. change it for unbounded
        int n = wt.size();
        vi prev(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            prev[i] = i / wt[0] * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            vi curr(W + 1, 0);
            forn(j, W + 1)
            {
                int take = (wt[i] > j) ? INT_MIN : curr[j - wt[i]] + val[i];
                int notTake = prev[j];
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};