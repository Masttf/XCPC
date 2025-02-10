#include<bits/stdc++.h>
#define int long long
using namespace std;
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
struct node{
	int mi, cnt, tag;
};
void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n + 1);
	vector<int>p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	for(int i = 1; i <= n; i++)a[i] = get(a[i]);
	vector<vector<int>>pos(n + 1);
	for(int i = 1; i <= n; i++){
		pos[a[i]].push_back(i);
	}
	vector op(n + 5, vector<array<int, 3>>());
	for(int i = 1; i <= n; i++){
		int sz = pos[i].size();
		for(int j = 0; j < sz; j++){
			int last = j == 0 ? 0 : pos[i][j - 1];
			int now = pos[i][j];
			op[now].push_back({0, now - 1, 1});
			op[now - 1].push_back({0, now - 1, -1});
			if(j + k <= sz - 1){
				//dbg(now, pos[i][j + k], n);
				op[now].push_back({pos[i][j + k], n, 1});
				op[last].push_back({pos[i][j + k], n, -1});
			}
			int r = n;
			if(j + k - 1 <= sz - 1)r = pos[i][j + k - 1] - 1;
			//dbg(now, i, r);
			if(now <= r)op[now].push_back({now, r, 1});
			if(now <= r)op[last].push_back({now, r, -1});
		}
	}
	vector<node>tr(n * 4);
	auto cg = [&](node &x, int val) -> void{
		x.mi += val;
		x.tag += val;
	};
	auto down = [&](int p) -> void{
		if(tr[p].tag){
			cg(tr[p << 1], tr[p].tag);
			cg(tr[p << 1 | 1], tr[p].tag);
			tr[p].tag = 0;
		}
		return ;
	};
	auto up = [&](node x, node y) -> node{
		node res = {0, 0, 0};
		res.mi = min(x.mi, y.mi);
		if(x.mi == res.mi)res.cnt += x.cnt;
		if(y.mi == res.mi)res.cnt += y.cnt;
		return res;
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			tr[p].mi = 0;
			tr[p].cnt = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 |1]);
	};
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			cg(tr[p], val);
			return ;
		}
		down(p);
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
		//dbg(l, r, tr[p].mi, tr[p].cnt);
	};
	int ans = 0;
	bulid(bulid, 0, n ,1);
	for(int i = n; i >= 1; i--){
		for(auto [l, r, val] : op[i]){
			//dbg(i, l, r, val);
			updata(updata, 0, n, l, r, val, 1);
		}
		
		if(tr[1].mi == 0)ans += tr[1].cnt;
		//dbg(i, ans);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}