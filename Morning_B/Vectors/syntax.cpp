#include <bits/stdc++.h>
using namespace std;

void vectors()
{
    int n = 5, sum = 0;
    cin >> n;
    vector<int> v(n); // 1st constructor
    for (int i = 0; i < n; i++)
    {
        // cin >> v[i];
        v[i] = i + 1;
        sum += v[i];
    }
    v.push_back(6);
    cout << sum;

    vector<int> v2(10, 1);
    vector<int> v3;
}

void arrays()
{
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum << '\n';
}

int main()
{
    arrays();
    vectors();
}