#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
const int N = 3e4 + 7, QQ = 2e5 + 7;
int arr[N];
int tree[4 * N];
void build(int node, int b, int e) {
    if (b == e) {
        tree[node] = 0;
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = tree[l] + tree[r];
}
void update(int node, int b, int e, int i, int x) {
    if (i < b or e < i) return;
    if (b == e && b == i) {
        tree[node] += x;
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    tree[node] = tree[l] + tree[r];
}
int query(int node, int b, int e, int i, int j) {
    if (j < b or e < i) return 0;
    if (i <= b && e <= j) {
        return tree[node];
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
vector<pair<int, int>> Q[N];
vector<int> v(N);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int q;
        cin >> q;

        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            Q[r].push_back({l, i});
        } 
        map<int, int> last_ind;
        vector<int> ans(q + 1);
        for (int i = 1; i <= n; i++) {
            if (last_ind.find(v[i]) != last_ind.end()) {
                update(1, 1, n, last_ind[v[i]], -1);
            }
            last_ind[v[i]] = i;
            update(1, 1, n, i, 1);
            for (auto x : Q[i]) {
                int l = x.first, id = x.second;
                ans[id] = query(1, 1, n, l, i);
            }
        }
        for (int i = 1; i <= q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
