#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a,int b){return a>b;}
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n,ans=0,ans1=0,gcd=0;cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        for(int i=1;i<n;i++){
            gcd=__gcd(ar[i-1],ar[i]);
            ans=max(ans,gcd);
        }
        for(int i=0;i<n;i++){
            int tem=ar[i];
            int sum=ar[i];
            int j=i+1;
            while(j<n){
                tem=__gcd(ar[j],tem);
                if(ans==tem){
                    sum+=ar[j];
                    ans1=max(ans1,sum);
                }
                if(tem<ans){
                    break;
                }
                j++;
            }
        }
        cout<<ans1<<endl;
    }
    return 0;
}