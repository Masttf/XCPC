#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n, k; cin >> n >> k;
    vector<int> ans(n + 1);
    vector<int> vis(n + 1);
    int cnt = 0;
    for(int i = k; i <= n; i += k){
    	cnt++;
    	vis[cnt] = 1;
    	ans[i] = cnt;
    }
    int now = n;
    for(int i = 1; i <= n; i++){
    	if(ans[i])continue;
    	while(vis[now])now--;
    	vis[now] = 1;
    	ans[i] = now;
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << ' ';
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*

*/