#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=5e5+10;
const int mod=998244353;
#define int long long
int qmi(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)res=res*a%mod;
    return res;
}
void solve() {
//    int d[40][40];
//    d[1][1]++,d[1][3]--,d[3][1]--,d[3][3]++;
//    rep(i,1,4)rep(j,1,4){
//        d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
//        cout<<i<<" "<<j<<" "<<d[i][j]<<"\n";
//    }
    int n,m,k;cin>>n>>m>>k;
    int L=0,R=0,U=0,D=0;
    string s;cin>>s;
    int a=0,b=0;
    for(auto ch:s){
        if(ch=='L')a--;
        else if(ch=='R')a++;
        else if(ch=='U')b--;
        else b++;
        L=max(L,-a),R=max(R,a);
        U=max(U,-b),D=max(D,b);
    }
    int l=L+1,r=m-R,u=U+1,d=n-D;
    if(l>r or u>d){
        if(k==0)cout<<n*m<<"\n";
        else cout<<0<<"\n";
    }else{
        vector<vector<int>>vis(n+5,vector<int>(m+5));
        auto c=vis,pre=c;
        int nx=u,ny=l;
        //cout<<nx+(d-u)<<" "<<ny+(r-l)<<"\n";
        c[nx][ny]++,c[nx][ny+(r-l)+1]--,c[nx+(d-u)+1][ny]--,c[nx+(d-u)+1][ny+(r-l)+1]++;
        vis[nx][ny]++;
        for(auto ch:s){
            if(ch=='L')ny--;
            else if(ch=='R')ny++;
            else if(ch=='U')nx--;
            else nx++;
            if(vis[nx][ny])continue;
            vis[nx][ny]++;
            //cout<<nx<<" "<<ny<<"\n";
            c[nx][ny]++,c[nx][ny+(r-l)+1]--,c[nx+(d-u)+1][ny]--,c[nx+(d-u)+1][ny+(r-l)+1]++;
        }
        int sum=(r-l+1)*(d-u+1),ans=0;
        rep(i,1,n)rep(j,1,m){
            c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
            if(sum-c[i][j]==k)ans++;
            //cout<<i<<" "<<j<<" "<<c[i][j]<<"\n";
        }
        cout<<ans<<"\n";
    }
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}
//3
//4 5 3
//ULDDRR
//4 5 0
//UUUUUUU
//4 5 10
//UUUUUUU
