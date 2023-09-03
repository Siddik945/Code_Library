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
const int N = 1e5 + 7, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int pw1[N], pw2[N];
void pre() {
    pw1[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    }
    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
}
pair<int, int> get_hasing(string s) {
    int n = s.size();
    int hs1 = 0;
    for (int i = 0; i < n; i++) {
        hs1 += 1LL * s[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }
    int hs2 = 0;
    for (int i = 0; i < n; i++) {
        hs2 += 1LL * s[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }
    return {hs1, hs2};
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        pre();
        string a, b;
        cin >> a >> b;
        cout << (get_hasing(a) == get_hasing(b)) << endl;
    }
    return 0;
}
