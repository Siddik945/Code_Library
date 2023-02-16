#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> v(n), count(k);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum = 0;
        for (auto x : v)
        {
            sum += ((x % k) + k) % k;
            count[sum % k]++;
        }
        ans = count[0];
        for (auto x : count)
        {
            ans += (x * (x - 1)) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}