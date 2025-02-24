#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int tot = 0; 
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int k; cin >> k;
    		tot++;
    		a[i] = {ty, tot, k};
    	}else if(ty == 2){
    		int id; cin >> id;
    		a[i] = {ty, id, -1};
    	}else{
    		int x; cin >> x;
    		a[i] = {ty, x, -1};
    	}
    }
    vector tr(n * 4, vector<int>());
    auto insert = [&](auto self, int l, int r, int x, int y, int id, int p) -> void{
    	if(x <= l && r <= y){
    		tr[p].push_back(id);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, y, id, p << 1);
    	if(y > mid)self(self, mid +1, r, x, y, id, p << 1 | 1);
    };

    vector<int> last(tot + 1, n + 1);
    for(int i = n; i >= 1; i--){
    	auto [ty, x, y] = a[i];
    	if(ty == 2){
    		last[x] = i;
    	}else if(ty == 1){
    		insert(insert, 1, n, i, last[x] - 1, i, 1);
    	}
    }
    vector<int> t(n + 1);
    auto add = [&](int x, int val) -> void{
    	while(x <= n){
    		t[x] += val;
    		x += lowbit(x);
    	}
    };
    auto ask = [&](int x) -> int{
    	int res = 0;
    	while(x){
    		res += t[x];
    		x -= lowbit(x);
    	}
    	return res;
    };
    auto get = [&](int x) -> int{
    	if(ask(n) < x)return 0;
    	int p = 0;
    	
    };
    vector<pair<int, int>> stk;
    auto rollback = [&](int sz) -> void{
    	while(stk.size() > sz){
    		auto [x, y] = stk.back();
    		stk.pop_back();
    		add(x, y);
    	}
    };
    vector<int> res;
    auto dfs = [&](auto self, int l, int r, int p) -> void{
    	int sz = stk.size();
    	for(auto id : tr[p]){
    		auto [ty, x, y] = a[id];
    		add(id, y);
    		stk.push_back({id, -y});
    	}
    	if(l == r){
    		if(a[l][0] == 3){
    			res.push_back(ask(a[l][1]));
    		}
    		rollback(sz);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	self(self, l, mid, p << 1);
    	self(self, mid + 1, r, p << 1 | 1);
    	rollback(sz);
    	return ;
    };
	dfs(dfs, 1, n, 1);
	for(auto x : res) cout << x << '\n';    
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}