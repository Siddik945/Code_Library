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
int col[N], ok;
void dfs(int u) {
    visit[u] = true;
    for (auto v : g[u]) {
        if (!visit[v]) {
            col[v] = col[u] ^ 1;
            dfs(v);
        } else {
            if (col[u] == col[v]) {
                ok = false;
            }
        }
    }
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
            g[v].push_back(u);
        }
        ok = true;
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) dfs(i);
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
