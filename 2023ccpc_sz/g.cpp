#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
    cout<<#x<<" -> "; \
    err(x); \
}while(0)
void err(){
    cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
    cout<<fixed<<setprecision(10)<<arg<<' ';
    err(args...);
}
const int mod=1e9+7;
void solve(){
    int n,q,m,k;cin>>n>>q>>m>>k;
    vector<string>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=' '+a[i];
    }
    vector f(n+1,vector<int>(m+1));
    vector<int>p(m+1);
    p[0]=1;
    for(int i=1;i<=m;i++)p[i]=p[i-1]*131;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=f[i][j-1]*131+(a[i][j]-'a'+1);
        }
    }

    auto ask=[&](int l,int r,vector<int>&t)->int{
        return t[r]-t[l-1]*p[r-l+1];
    };

    for(int _=1;_<=q;_++){
        string s;cin>>s;
        s=' '+s;
        vector<int>ff(m+1);
        for(int i=1;i<=m;i++)ff[i]=(ff[i-1]*131+(s[i]-'a'+1))%mod;
        int ans=0;
        auto check = [&](int x)->bool{
            int cnt=0;
            int now=1;
            for(int i=1;i<=k+1;i++){
                int l=now,r=m;
                int res=now-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    
                    if(ask(now,mid,ff)!=ask(now,mid,f[x]))r=mid-1;
                    else res=mid,l=mid+1;
                }
                if(res<m)cnt++;
                else if(res==m)break;
                now=res+2;
            }
            return cnt<=k;
        };
        for(int i=1;i<=n;i++){
            if(check(i)){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}

