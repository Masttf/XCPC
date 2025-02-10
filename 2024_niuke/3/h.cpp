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
constexpr int Max = 1e18;
struct node{
	int x1, y1, x2, y2;
};
bool cmp1(node x, node y){
	return x.x1 < y.x1; 
}
bool cmp2(node x, node y){
	return x.y1 < y.y1;
}
bool cmp3(node x, node y){
	return x.x2 < y.x2; 
}
bool cmp4(node x, node y){
	return x.y2 < y.y2;
}
void solve(){
	int n, m; cin >> n >> m;
	int k; cin >> k;
	vector<node>a(k + 1);
	for(int i = 1; i <= k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i] = {x1, y1, x2, y2};
	}
	a[0] = {1, 1, n, m};
	vector res(n + 1, vector<array<int, 4>>(m + 1));
	vector tr(2,vector<int>(max(n, m) * 4));
	auto cg0 = [&](int &x, int val) -> void{
		x = min(x, val);
	};
	auto cg1 = [&](int &x, int val) -> void{
		x = max(x, val);
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		tr[0][p] = Max;
		tr[1][p] = 0;
		if(l == r){
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);

	};
	auto updata = [&](auto self, int l, int r, int x, int y, int val,int p) -> void{
		if(x <= l && r <= y){
			cg0(tr[0][p], val);
			cg1(tr[1][p], val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	int mi = Max, mx = 0;
	auto query = [&](auto self ,int l, int r, int x, int p) -> void{
		mi = min(mi, tr[0][p]);
		mx = max(mx, tr[1][p]);
		if(l == r){
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, p << 1);
		else self(self, mid + 1, r, x, p << 1 | 1);
	};
	sort(a.begin(), a.end(), cmp1);
	bulid(bulid, 1, m, 1);
	int last = 1;
	for(int i = 0; i <= k; i++){
		auto [x1, y1, x2, y2] = a[i];
		int p = i;
		while(p <= k && a[p].x1 == x1){
			updata(updata, 1, m, a[p].y1, a[p].y2, x1, 1);
			p++;
		}
		i = p - 1;
		for(int j = last; j <= x1; j++){
			for(int k = 1; k <= m; k++){
				mx = 0;
				query(query, 1, m, k, 1);
				res[j][k][0] = mx;
			}
		}
		last = x1 + 1;
	}
	for(int j = last; j <= n; j++){
		for(int k = 1; k <= m; k++){
			mx = 0;
			query(query, 1, m, k, 1);
			res[j][k][0] = mx;
		}
	}
	
	sort(a.begin(), a.end(), cmp3);
	bulid(bulid, 1, m, 1);
	last = n;
	for(int i = k; i >= 0; i--){
		auto [x1, y1, x2, y2] = a[i];
		int p = i;
		while(p >= 0 && a[p].x2 == x2){
			updata(updata, 1, m, a[p].y1, a[p].y2, x2, 1);
			p--;
		}
		i = p + 1;
		for(int j = last; j >= x2; j--){
			for(int k = 1; k <= m; k++){
				mi = Max;
				query(query, 1, m, k, 1);
				res[j][k][2] = mi;
			}
		}
		last = x2 - 1;
	}
	for(int j = last; j >= 1; j--){
		for(int k = 1; k <= m; k++){
			mi = Max;
			query(query, 1, m, k, 1);
			res[j][k][2] = mi;
		}
	}
	sort(a.begin(), a.end(), cmp2);
	bulid(bulid, 1, n, 1);
	last = 1;
	for(int i = 0; i <= k; i++){
		auto [x1, y1, x2, y2] = a[i];
		int p = i;
		while(p <= k && a[p].y1 == y1){
			updata(updata, 1, n, a[p].x1, a[p].x2, y1, 1);
			p++;
		}
		i = p - 1;
		for(int j = last; j <= y1; j++){
			for(int k = 1; k <= n; k++){
				mx = 0;
				query(query, 1, n, k, 1);
				res[k][j][1] = mx;
			}
		}
		last = y1 + 1;
	}
	for(int j = last; j <= m; j++){
		for(int k = 1; k <= n; k++){
			mx = 0;
			query(query, 1, n, k, 1);
			res[k][j][1] = mx;
		}
	}
	
	sort(a.begin(), a.end(), cmp4);
	bulid(bulid, 1, n, 1);
	last = m;
	for(int i = k; i >= 0; i--){
		auto [x1, y1, x2, y2] = a[i];
		int p = i;
		while(p >= 0 && a[p].y2 == y2){
			updata(updata, 1, n, a[p].x1, a[p].x2, y2, 1);
			p--;
		}
		i = p + 1;
		for(int j = last; j >= y2; j--){
			for(int k = 1; k <= n; k++){
				mi = Max;
				query(query, 1, n, k, 1);
				res[k][j][3] = mi;
			}
		}
		last = y2 - 1;
	}
	for(int j = last; j >= 1; j--){
		for(int k = 1; k <= n; k++){
			mi = Max;
			query(query, 1, n, k, 1);
			res[k][j][3] = mi;
		}
	}


	int ans = n * m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			auto [x1, y1, x2, y2] = res[i][j];
			//dbg(i, j, x1, y1, x2, y2);
			if(x1 == i && y1 == j)
				ans = min(ans, (x2 - x1 + 1)*(y2 - y1 + 1));
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}