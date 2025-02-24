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
    int n, q; cin >> n >> q;
    vector<int> f(n + 1), c(n + 1);
    vector<int> l(n + 1), r(n + 1);
    vector<int> sz(n + 1), cnt(n + 1);
    for(int i = 1; i <= n; i++){
    	f[i] = i;
    	l[i] = r[i] = i;
    	sz[i] = 1;
    	cnt[i] = 1;
    	c[i] = i;
    }
    auto find = [&](auto self, int x) -> int {
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	// dbg(fa, fb);
    	f[fa] = fb;
    	l[fb] = min(l[fb], l[fa]);
    	r[fb] = max(r[fb], r[fa]);
    	sz[fb] += sz[fa];
    };
    for(int i = 1; i <= q; i++){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int x, col; cin >> x >> col;
    		int u = find(find, x);
    		cnt[c[u]] -= sz[u];
    		cnt[col] += sz[u];
    		c[u] = col;
    		// dbg(u, l[u], r[u]);
    		// if(l[u] - 1 >= 1)dbg(c[find(find, l[u] - 1)]);
    		// if(r[u] + 1 <= n)dbg(c[find(find, r[u] + 1)]);
    		if(l[u] - 1 >= 1 && c[find(find, l[u] - 1)] == c[u]){
    			merge(u, l[u] - 1);
    		}
    		if(r[u] + 1 <= n && c[find(find, r[u] + 1)] == c[u]){
    			merge(u, r[u] + 1);
    		}
    	}else{
    		int x; cin >> x;
    		cout << cnt[x] << '\n';
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}