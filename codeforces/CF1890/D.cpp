#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
    std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
    std::cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n,c;cin>>n>>c;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];

    vector<int>res(n+1);
    res[1]=pre[1];
    int ok=0;
    for(int i=2;i<=n;i++){
        if(res[1]+a[i]>=i*c){
            res[1]=pre[i];
            if(i==n)ok=1;
        }
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}