#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
bool cmp(int a,int b){return a>b;}
#define mxv(v) *max_element(v.begin(), v.end())
#define mnv(v) *min_element(v.begin(), v.end())
const int N=1e5+7;
int arr[N];
int tree[4*N];
void build(int at,int b,int e){
    if(b==e) {
        tree[at]=arr[b];
        return;
    }
    int mid=(b+e)>>1,l=at<<1,r=l|1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[at]=tree[l]+tree[r];
}
void update(int at,int b,int e,int ind,int val){
    if(ind<b || e<ind) return ;
    if(b==e && b==ind){
        tree[at]=val;
        return;
    }
    int mid=(b+e)>>1,l=at<<1,r=l|1;
    update(l,b,mid,ind,val);
    update(r,mid+1,e,ind,val);
    tree[at]=tree[l]+tree[r];
}
int query(int at,int b,int e,int i,int j){
    if(j<b || e<i) return 0;
    if(b<=i && j<=e) return tree[at];
    int mid=(b+e)>>1,l=at<<1,r=l|1;
    int x=query(l,b,mid,i,j);
    int y=query(r,mid+1,e,i,j);
    return x+y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>arr[i];
        build(1,1,n);
        for(int i=0;i<n;i++){
            int op;cin>>op;
            if(op==1){
                int ind,val;cin>>ind>>val;
                update(1,1,n,ind,val);
            }
            else {
                int l,r;cin>>l>>r;
                cout<<query(1,1,n,l,r)<<'\n';
            }
        }
        cout<<tree[1]<<endl;
    }
    return 0;
}
