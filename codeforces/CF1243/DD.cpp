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
constexpr int maxn = 1e5 + 5;
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	if(u > v)g[u].push_back(v);
    	else g[v].push_back(u);
    }
    vector<int> f(n + 1), sz(n + 1, 1);
    for(int i = 1; i <= n; i++) f[i] = i;
    auto find = [&](auto self, int x) -> int{
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	if(fa == fb)return ;
    	f[fa] = fb;
    	sz[fb] += sz[fa];
    };
    set<int> s;
    for(int i = 1; i <= n; i++){
    	map<int, int> mp;
    	for(auto v : g[i]){
    		mp[find(find, v)]++;
    	}
    	vector<int> t;
    	for(auto x : s){
    		int y = 0;
    		if(mp.count(x)) y = mp[x];
    		if(y < sz[x]){
    			t.push_back(x);
    		}
    	}
    	for(auto x : t){
    		s.erase(x);
    		merge(i, x);
    	}
    	s.insert(find(find, i));
    }
    int ans = s.size();
    cout << ans - 1 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
/*
first 0

*/