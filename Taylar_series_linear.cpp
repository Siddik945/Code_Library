#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a, int b) { return a > b; }
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
double e(double x, double n) {
    static double s = 1;
    if (n == 0) return s;
    s = 1 + (x / n) * s;
    return e(x, n - 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        double x, n;
        cin >> x >> n;
        cout << e(x, n) << endl;
    }
    return 0;
}
