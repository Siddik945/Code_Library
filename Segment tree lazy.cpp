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
int lazy[4*N];
void push(int at,int b,int e){
    if(lazy[at]==0) return ;
    tree[at]+=lazy[at]*(e-b+1);
    if(b!=e){
        lazy[2*at]+=lazy[at];
        lazy[2*at+1]+=lazy[at];
    }
    lazy[at]=0;
}
void build(int at,int b,int e){
    lazy[at]=0;
    if(b==e){
        tree[at]=arr[b];
        return ;
    }
    int mid=(b+e)>>1,l=at<<1,r=l|1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[at]=tree[l]+tree[r];
}
void update(int at,int b,int e,int i,int j,int val){
    push(at,b,e);
    if(j<b || e<i) return; 
    if(i<=b && e<=j){
        lazy[at]=val;
        push(at,b,e);
        return;
    }
    int mid=(b+e)>>1,l=at<<1,r=l|1;
    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);
    tree[at]=tree[l]+tree[r];
}
int query(int at,int b,int e,int i,int j){
    push(at,b,e);
    if(j<b || e<i) return 0;
    if(i<=b && e<=j) {
        return tree[at];
    }
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
        update(1,1,n,2,2,2);
        cout<<query(1,1,n,2,3)<<'\n';
        cout<<tree[1]<<endl;
    }
    return 0;
}
