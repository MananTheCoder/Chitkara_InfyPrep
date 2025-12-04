#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

typedef pair<double, int> pdi;

class Solution
{
private:
    double myRound(double a, int p)
    {
        double mult = pow(10, p);
        return round(a * mult) / mult;
    }
    void print_vpdi(vector<pdi> &ratios)
    {
        for (pdi row : ratios)
        {
            cout << row.first << "\t" << row.second << "\n";
        }
    }

public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    { // O(nlgn)
        int n = val.size();
        double ans = 0;
        vector<pair<double, int>> ratios;
        forn(i, n)
        { // O(n)
            double ratio = (double)val[i] / wt[i];
            ratios.push_back(make_pair(ratio, i));
        }
        sort(ratios.begin(), ratios.end(), greater<pdi>()); // O(nlgn)
        // print_vpdi(ratios);
        for (int i = 0; i < n && capacity > 0; i++)
        { // n * 1
            int ind = ratios[i].second;
            double ratio = ratios[i].first;
            // cout<<capacity<<"\t"<<ans<<"\t"<<ind<<"\n";
            if (wt[ind] <= capacity)
            {
                ans += val[ind];
                capacity -= wt[ind];
            }
            else
            {
                ans += ratio * capacity;
                capacity = 0;
            }
        }
        return myRound(ans, 6);
    }
};
