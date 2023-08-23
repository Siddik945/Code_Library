#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
const int N = 1e5 + 7;
vector<int> g[N];
bool visit[N];
int dp[N];
int fun(int u) {
    int &ans = dp[u];
    if (ans != -1) return dp[u];
    ans = 0;
    for (auto v : g[u]) {
        ans = max(ans, 1 + fun(v));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        int n, e;
        cin >> n >> e;
        while (e--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            // g[v].push_back(u);
        }
        int ans = 0;
        memset(dp,-1,sizeof dp);
        for (int i = 1; i <= n; i++) {
            ans = max(ans, fun(i));
        }
        cout << ans << endl;
    }
    return 0;
}
