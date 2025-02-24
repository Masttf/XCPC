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
void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n + 1);
	vector<pair<int, int>>b(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> b[i].first;
		b[i].second = i - 1;
	}
	sort(b.begin() + 1, b.end());
	vector<int>tr(n * 4);
	auto updata = [&](auto self, int l, int r, int x, int val, int p) -> void{
		if(l == r){
			tr[p] = val;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, p << 1);
		else self(self, mid + 1, r, x, val, p << 1 | 1);
		tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int val, int p) ->int{
		if(x <= l && r <= y){
			if(tr[p] >= val)return -1;
			if(l == r)return l;
		}
		int mid = (l + r) >> 1;
		if(x <= mid){
			int res = self(self, l, mid, x, y, val, p << 1);
			if(res != -1)return res;
		}
		if(y > mid)return self(self, mid + 1, r, x, y, val, p << 1 | 1);
		return -1;
	};
	for(int i = 1; i <= n; i++){
		updata(updata, 1, n, i, a[i], 1);
	}

	vector<int>start(n + 1);
	for(int i = 1; i <= q; i++){
		int x; cin >> x;
		if(!start[x])start[x] = i;
	}
	vector<int>ans(q + 5);
	vector<vector<pair<int, int>>>res(n + 1);
	for(int i = 1; i <= n; i++){
		res[i].push_back({0, a[i]});
	}
	for(int i = 1; i <= n; i++){
		auto [val, id] = b[i];
		int l = 1, r = n;
		int d = query(query, 1, n, l, r, val, 1);
		while(d != -1){
			int o = d - 1;
			int t = (id - o + n) % n;
			if(start[t]){
				while(!res[d].empty() && start[t] <= res[d].back().first){
					res[d].pop_back();
				}
				res[d].push_back({start[t], val});
			}
			updata(updata, 1, n, d, val, 1);
			l = d + 1;
			if(l > r)break;
			d = query(query, 1, n, l, r, val, 1);
		}
	}
	for(int i = 1; i <= n; i++){
		int r = n;
		while(!res[i].empty()){
			auto [l, val] = res[i].back();
			res[i].pop_back();
			ans[l] += val;
			ans[r + 1] -=val;
			r = l - 1;
		}
	}
	for(int i = 1; i <= q; i++)ans[i] += ans[i - 1];
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}