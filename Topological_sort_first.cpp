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
int indg[N];

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
            indg[v]++;
            g[u].push_back(v);
        }
        vector<int> ans,tem;
        for(int i=1;i<=n;i++){
            if(indg[i]==0){
                tem.push_back(i);
                visit[i]=true;
            }
        }
        while (ans.size() < n) {
            if(tem.empty()) {
                cout<<"Imposible"<<endl;
                return 0;
            }
            int cur = tem.back();
            tem.pop_back();
            ans.push_back(cur);
            for (auto v : g[cur]) {
                indg[v]--;
                if(!visit[v] && indg[v]==0){
                    tem.push_back(v);
                    visit[v]=true;
                }
            }
        }
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}
