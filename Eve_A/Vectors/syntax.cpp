#include <bits/stdc++.h>
using namespace std;

void vectors()
{
    int n = 5, sum = 0;
    cin >> n;
    vector<int> v(n, 1);
    for (int i = 0; i < n; i++)
    {
        // int temp;
        // cin >> temp;
        // v.push_back(temp);
        cin >> v[i];
        sum += v[i];
    }
    cout << sum << "\n";
}

void arrays()
{
    int n = 5, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum << "\n";
}

int main()
{
    arrays();
    vectors();
}