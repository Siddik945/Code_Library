#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
double e(int x, int n) {
    static double f = 1, p = 1;
    double r;
    if (n == 0) {
        return 1;
    } else {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        int x, n;
        cin >> x >> n;
        cout << e(x, n) << endl;
    }
    return 0;
}
