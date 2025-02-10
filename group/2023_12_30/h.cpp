#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>ans(n+1);
    vector g(k+1,vector<int>());
    vector g2(k+1,vector<int>());
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        g[y].push_back(x);
        g2[y].push_back(i);
    }
    for(int i=1;i<=k;i++){
        sort(g[i].begin(),g[i].end());
    }
    for(int i=1;i<=k;i++){
        int len=g[i].size();
        for(int j=0;j<len;j++){
            ans[g2[i][j]]=g[i][j];
        }
    }
    for(int i=1;i<n;i++){
        if(ans[i+1]<ans[i]){
            cout<<"N\n";
            return ;
        }
    }
    cout<<"Y\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
} 