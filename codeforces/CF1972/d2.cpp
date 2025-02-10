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
void solve(){
    int n,m;cin>>n>>m;
    int ans=0;
    for(int i=1;i*i<=n;i++){
        for(int j=1;j*j<=m;j++){
            if(__gcd(i,j)==1){
                ans+=min(n/i,m/j)/(i+j);
            }
        }
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}