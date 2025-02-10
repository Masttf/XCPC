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
    int n, m; cin >> n >> m;
    vector<array<int, 3>>e(m + 1);
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	e[i] = {w, u, v};
    }
    sort(e.begin() + 1, e.end());
    vector<int> f(n + 1), sz(n + 1);
    vector<int> d1(n + 1, -1), d2(n + 1, -1), ans(n + 1, -1);
    vector<array<int, 3>>stk;
    for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 1;
    auto find = [&](int x) -> int{
    	while(f[x] != x){
    		x = f[x];
    	}
    	return x;
    };
    auto merge1 = [&](int x) -> void{
    	auto [w, a, b] = e[x];
    	int fa = find(a);
    	int fb = find(b);
    	if(fa == fb)return ;
    	if(sz[fa] > sz[fb])swap(fa, fb);
    	f[fa] = fb;
    	sz[fb] += sz[fa];
    	stk.push_back({fa, ans[fa], ans[fb]});
    	if(find(1) == fb)ans[fb] = w;
    };
    auto merge2 = [&](int x) -> void{
    	auto [w, a, b] = e[x];
    	int fa = find(a);
    	int fb = find(b);
    	if(fa == fb)return ;
    	if(sz[fa] > sz[fb])swap(fa, fb);
    	f[fa] = fb;
    	sz[fb] += sz[fa];
    	stk.push_back({fa, ans[fa], ans[fb]});
    	if(find(n) == fb)ans[fb] = w;
    };
    auto rollback = [&](int x) -> void{
    	while(stk.size() > x){
    		auto [fa, a, b] = stk.back();
    		int fb = f[fa];
    		int temp = ans[fb];
    		stk.pop_back();
    		f[fa] = fa;
    		sz[fb] -= sz[fa];
    		ans[fa] = a;
    		ans[fb] = b;
    		if(ans[fa] == -1)ans[fa] = temp;
    		if(ans[fb] == -1)ans[fb] = temp;
    	}
    };
    for(int i = 1; i <= m; i++){
    	merge1(i);
    }
    rollback(0);
    d1[1] = d2[n] = 0;
    for(int i = 2; i <= n; i++){
    	d1[i] = ans[i];
    }
    for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 1, ans[i] = -1;
    for(int i = 1; i <= m; i++){
    	merge2(i);
    }
    rollback(0);
    for(int i = 1; i < n; i++){
    	d2[i] = ans[i];
    }
    int res = 1e18;
    for(int i = 1; i <= m; i++){
    	auto [w, u, v] = e[i];
    	if(max(d1[u], d2[v]) <= w){
    		res = min(res, max(d1[u], d2[v]) + w);
    	}
    	if(max(d1[v], d2[u]) <= w){
    		res = min(res, max(d1[v], d2[u]) + w);
    	}
    }
    cout << res << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}