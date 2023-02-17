#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a,int b){return a>b;}
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
int expon(int tem,int p,int q){
    int res=0;
    while(tem){
        res+=tem/p;
        tem/=p;
    }
    return res/q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n,k,cnt;cin>>n>>k;
        int ans=INT_MAX;
        for(int i=2;i*i<=k;i++){
            cnt=0;
            if(k%i==0){
                while(k%i==0){
                    cnt++;k/=i;
                }
                ans=min(ans,expon(n,i,cnt));
            }
        }
        if(k>1) ans=min(ans,expon(n,k,1));
        cout<<ans<<'\n';
    }
    return 0;
}
