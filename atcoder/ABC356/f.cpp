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
    int n; cin >> n;
    int k; cin >> k;
    vector<pair<int, int>> a(n + 1);
    vector<int> p;
    for(int i = 1; i <= n; i++){
    	int ty, x; cin >> ty >> x;
    	a[i] = {ty, x};
    	p.push_back(x);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(int i = 1; i <= n; i++){
    	a[i].second = get(a[i].second);
    }
    vector<vector<int>> tr(n * 4);
    auto insert = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
    	if(x <= l && r <= y){
    		tr[p].push_back(val);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, y, val, p << 1);
    	if(y > mid) self(self, mid + 1, r, x, y, val, p << 1 | 1);
    };
    vector<int> last(n + 1);
    for(int i = 1; i <= n; i++){
    	auto [ty, x] = a[i];
    	if(ty == 1){
    		if(last[x]){
    			// dbg(last[x], i - 1, x);
    			insert(insert, 1, n, last[x], i - 1, x, 1);
    			last[x] = 0;
    		}else last[x] = i;
    	}
    }
    for(int i = 1; i <= n; i++){
    	if(last[i]){
    		// dbg(last[i], n, i);
    		insert(insert, 1, n, last[i], n, i, 1);
    	}
    }
    vector<int> ans(n + 1, -1);
    vector<int> f(n + 1), sz(n + 1);
    vector<int> stk;
    set<int> s;
    for(int i = 1; i <= n; i++){
    	f[i] = i;
    	sz[i] = 1;
    }
    auto find = [&](int x) -> int{
    	while(x != f[x]){
    		x = f[x];
    	}
    	return x;
    };
    auto merge = [&](int a, int b) -> void{
    	// dbg(a, b);
    	int fa = find(a);
    	int fb = find(b);
    	if(fa == fb)return ;
    	if(sz[fa] < sz[fb])swap(fa, fb);
    	f[fb] = fa;
    	sz[fa] += sz[fb];
    	stk.push_back(fb);
    };
    auto rollback = [&](int siz) -> void{
    	while(stk.size() > siz){
    		int x = stk.back();
    		stk.pop_back();
    		sz[f[x]] -= sz[x];
    		f[x] = x;
    	}
    };
    auto dfs = [&](auto self, int l, int r, int rt) -> void{
    	// dbg(l, r);
    	int siz = stk.size();
    	for(auto x : tr[rt]){
    		auto it = s.insert(x).first;
    		it++;
    		if(it != s.end()){
    			int d = p[*it - 1] - p[x - 1];
    			if(d <= k){
    				merge(x, *it);
    			}
    		}
    		it--;
    		if(it != s.begin()){
    			it--;
    			int d = p[x - 1] - p[*it - 1];
    			if(d <= k){
    				merge(x, *it);
    			}
    		}
    	}
    	if(l == r){
    		if(a[l].first == 2){
    			ans[l] = sz[find(a[l].second)];
    		}
    		for(auto x : tr[rt]){
    			s.erase(x);
    		}
    		rollback(siz);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	self(self, l, mid, rt << 1);
    	self(self, mid + 1, r, rt << 1 | 1);
    	rollback(siz);
    	for(auto x : tr[rt]){
			s.erase(x);
		}
    };
    dfs(dfs, 1, n, 1);
    for(int i = 1; i <= n; i++){
    	if(ans[i] != -1){
    		cout << ans[i] << '\n';
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