#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max=1e18;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),b(n+5);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n+1;i++)cin>>b[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-b[i]);
    }
    int res=Max;
    for(int i=1;i<=n;i++){
        int mi=min(a[i],b[i]);
        int mx=max(a[i],b[i]);
        if(mi<=b[n+1]&&b[n+1]<=mx){
            res=min(res,0ll);
        }
        res=min({abs(mi-b[n+1]),abs(mx-b[n+1]),res});
    }
    cout<<ans+res+1<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}