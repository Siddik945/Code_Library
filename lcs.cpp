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
const int N = 105;
string a, b;
int dp[N][N];
vector<char> v;
int lcs(int i, int j) {
    if (i >= a.size() or j >= b.size()) return 0;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = lcs(i + 1, j);
    ans = max(ans, lcs(i, j + 1));
    if (a[i] == b[j]) {
        ans = max(ans, lcs(i + 1, j + 1) + 1);
    }
    return ans;
}
void print(int i, int j) {
    if (i >= a.size() or j >= b.size()) return;
    if (a[i] == b[j]) {
        cout<<a[i];
        print(i + 1, j + 1);
        return;
    }
    int x = lcs(i + 1, j);
    int y = lcs(i, j + 1);
    if (x >= y) {
        print(i + 1, j);
    } else {
        print(i, j + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1, cs = 0;
    cin >> test;
    while (test--) {
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        cout << lcs(0, 0) << endl;
        print(0, 0);
        cout<<endl;
    }
    return 0;
}
