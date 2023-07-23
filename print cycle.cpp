#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
const int N = 2e5 + 7;
vector<int> g[N], vv;
bool cycle;
int col[N], par[N];
int x = 0;
void dfs(int u) {
    par[u] = x;
    x = u;
    col[u] = 1;
    for (auto v : g[u]) {
        if (col[v] == 0) {
            dfs(v);
        } else if (col[v] == 1) {
            cycle = true;
            int a = u;
            while (a != v) {
                if (col[a] == 1) vv.push_back(a);
                a = par[a];
            }
            vv.push_back(v);
            return;
        }
        col[v] = 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;
            g[i].push_back(v);
        }
        cycle = false;
        for (int i = 1; i <= n; i++) {
            if (col[i] == 0) dfs(i);
            if(cycle) break;
        }
        // cout << cycle << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << par[i] << " ";
        // }
        cout << vv.size() << endl;
        reverse(vv.begin(),vv.end());
        for (auto x : vv) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
