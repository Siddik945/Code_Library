#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        ll n, sum = 0;
        cin >> n;
        ll ans = INT_MIN;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if (sum < v[i]) sum = v[i];
            // sum=max(sum,v[i]);
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}
