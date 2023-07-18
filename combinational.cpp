#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
int ncr(int n, int r) {
    if (n == r || r == 0) return 1;
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    return 0;
}
