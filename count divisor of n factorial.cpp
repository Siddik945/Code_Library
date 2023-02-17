#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a,int b){return a>b;}
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
const int N=1e3;
bool f[N];
vector<int>v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i*i<=N;i++){
        if(!f[i]){
            for(int j=i*i;j<N;j+=i){
                f[j]=true;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(!f[i]) v.push_back(i);
    }
    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n,tem,res=0,i=0,ans=1;cin>>n;
        while(v[i]<=n){
            tem=n,res=0;
            while(tem){
                res+=tem/v[i];
                tem/=v[i];
            }
            ans*=(res+1);
            i++;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}
