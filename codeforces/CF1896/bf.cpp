#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x&(-x))
#define ull unsigned long long 
#define pii pair<int,int>
using namespace std;
const string yes="Yes\n",no="No\n";
const int N = 1000005,inf = 2e18,mod=1000000007;
int qpow(int x,int y=mod-2,int mo=mod,int res=1){
    for(;y;(x*=x)%=mo,y>>=1)if(y&1)(res*=x)%=mo;
    return res;
}
int jie[N],invjie[N];
int C(int n,int m){return n>=m&&m>=0?jie[n]*invjie[m]%mod*invjie[n-m]%mod:0;}
void main_init(){
    int n=N-1;jie[0]=1;for(int i=1;i<=n;i++)jie[i]=jie[i-1]*i%mod;
    invjie[n]=qpow(jie[n]);for(int i=n-1;~i;i--)invjie[i]=invjie[i+1]*(i+1)%mod;
}
int n;
int a[1000005];
int ans[1000005];
int id[1000005];
int tr[2000005];
int vis[1000005];
void add(int x,int k){
    for(;x<=n;x+=lowbit(x))tr[x]+=k;
}
int ask(int x,int res=0){
    for(;x;x-=lowbit(x))res+=tr[x];
    return res;
}
int qry(int l,int r){
    if(l<=r)return ask(r)-ask(l-1);
    else return ask(n)-qry(r,l-1);
}
void Init(){
    for(int i=1;i<=n;i++)tr[i]=0;
    for(int i=1;i<=n;i++)ans[i]=0,vis[i]=0;
}
void solve(){
    cin>>n;
    Init();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        id[a[i]]=i;
    }
    for(int i=1;i<=2*n;i++){
        int x=(i-1)%n+1;
        
        if(vis[x]){
            //cout<<id[x]+1<<" "<<i<<"???\n";
            ans[x]=qry(id[x]+1,x)+1;
            add(id[x],-1);
            vis[x]=0;
        }
        if(a[x]!=x){
            add(x,1);
            vis[a[x]]=1;
        }
        
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" \n"[i==n];
    }

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(12);main_init();
    int t=1;
    cin>>t;
    while (t--)solve();
}