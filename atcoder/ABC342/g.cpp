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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int q; cin >> q;
    vector<array<int, 4>> Q(q + 1);
    vector<int> st(q + 1), ed(q + 1, q);
    vector<vector<array<int, 3>>> op(n + 1);
    vector<vector<int>> opp(n + 1);
    for(int i = 1; i <= q; i++){
    	st[i] = i;
    	int ty; cin >> ty;
    	if(ty == 1){
    		int l, r, x;
    		cin >> l >> r >> x;
    		Q[i] = {ty, l, r, x};
    	}else if(ty == 2){
    		int x; cin >> x;
    		Q[i] = {ty, x, -1, -1};
    		ed[x] = i - 1;
    	}else{
    		int x; cin >> x;
    		Q[i] = {ty, x};
    		opp[x].push_back(i);
    	}
    }
    for(int i = 1; i <= q; i++){
    	auto [ty, l, r, x] = Q[i];
    	if(ty == 1){
    		op[l].push_back({st[i], ed[i], x});
    		if(r < n)op[r + 1].push_back({st[i], ed[i], -x});
    	}
    }
    vector<multiset<int, greater<>>> tr(q * 4);
    auto update = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
    	if(x <= l && r <= y){
    		if(val > 0){
    			tr[p].insert(val);
    		}else{
    			tr[p].erase(tr[p].find(-val));
    		}
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, y, val, p << 1);
    	if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
    };
    auto query = [&](auto self, int l, int r, int x, int &res, int p) -> void{
    	if(!tr[p].empty()){
    		res = max(res, *tr[p].begin());
    	}
    	if(l == r)return ;
    	int mid = (l + r) >> 1;
    	if(x <= mid) self(self, l, mid, x, res, p << 1);
    	else self(self, mid + 1, r, x, res, p << 1 | 1);
    };
    vector<int> ans(q + 1, -1);
    for(int i = 1; i <= n; i++){
    	for(auto [l, r, val] : op[i]){
    		update(update, 1, q, l, r, val, 1);
    	}
    	for(auto x : opp[i]){
    		ans[x] = a[i];
    		query(query, 1, q, x, ans[x], 1);
    	}
    }
    for(int i = 1; i <= q; i++){
    	if(ans[i] == -1)continue;
    	cout << ans[i] << '\n';
    }
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