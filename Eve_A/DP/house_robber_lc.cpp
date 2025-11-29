#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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

int max_rob(vi &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int n = nums.size();
    int prev2 = nums[0], prev = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(prev, nums[i] + prev2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    vi nums = input_vi();
    cout << max_rob(nums) << '\n';
}

int main()
{
    solve();
}