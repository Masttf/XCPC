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
    int n, m; cin >> n >> m;
    if(n == 0){
    	if(m == 0)cout << "Yes\n";
    	else cout << "No\n";
    	return ;
    }
    if(m == 0){
    	cout << "No\n";
    	return ;
    }
    cout << "Yes\n";
    // map<int, int> mp;
    // mp[1]++;
    // int p = 1;
    // while(p <= m){
    // 	p *= 2;
    // 	mp[p]++;
    // }
    // int ok = 0;
    // map<int, int> vis;
    // auto dfs = [&](auto self, int N) -> void{
    // 	if(vis[N])return ;
    // 	vis[N] = 1;
    // 	if(ok)return ;
    // 	dbg(N);
    // 	if(N == m)ok = 1;
    // 	if(N != 1)self(self, sqrt(N));
    // 	self(self, N * 2);
    // };
    // dfs(dfs, n);
    // if(ok)cout << "Yes\n";
    // else cout << "No\n";
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
*2
开平方

先开平方
再考虑*2

n, n * 2, n * 4, n * 8

*/