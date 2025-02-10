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
struct node{
	int sum, cnt;
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
	vector<node>tr(n * 4);
	auto up = [&](int p) -> void{
		tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
		tr[p].cnt = tr[p << 1].cnt + tr[p << 1 | 1].cnt;
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			tr[p].sum = a[l];
			if(b[l] > 1)tr[p].cnt = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		up(p);
	};
	auto updata = [&](auto self, int l, int r, int x, int p) -> void{
		if(l == r){
			tr[p].sum = a[l];
			if(b[l] > 1)tr[p].cnt = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, p << 1);
		else self(self, mid + 1, r, x, p << 1 | 1);
		up(p);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> pair<int, int>{
		if(x <= l && r <= y){
			if(tr[p].cnt == 0)return {-1, tr[p].sum};
			if(l == r)return {l, tr[p].sum};
		}
		int mid = (l + r) >> 1;
		pair<int, int> res = {-1, 0};
		if(x <= mid){
			res = self(self, l, mid, x, y, p << 1);
			if(res.first != -1)return res;
		}
		if(y > mid){
			auto [t, sum] = self(self, mid + 1, r, x, y, p << 1 | 1);
			res.first = t;
			res.second += sum;
		}
		return res;
	};

	auto query_first = [&](auto self, int l, int r, int x, int y, int p) -> int{
		if(x <= l && r <= y){
			if(tr[p].sum == 0)return -1;
			if(l == r)return l;
		}
		int mid = (l + r) >> 1;
		if(x <= mid){
			int res = self(self, l, mid, x, y, p << 1);
			if(res != -1)return res;
		}
		if(y > mid)return self(self, mid + 1, r, x, y, p << 1 | 1);
		return -1;
	};
	bulid(bulid, 1, n, 1);
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int ty; cin >> ty;
		if(ty != 3){
			int x, val; cin >> x >> val;
			if(ty == 1)a[x] = val;
			else b[x] = val;
			updata(updata, 1, n, x, 1);
		}else{
			int l, r; cin >> l >> r;
			int v = 0;
			l = query_first(query_first, 1, n, l, r, 1);
			if(l == -1){
				cout << 0 << '\n';
				continue;
			}
			v += a[l];
			l++;
			while(l <= r){
				auto [ll, sum] = query(query, 1, n, l, r, 1);
				if(ll == -1){
					v += sum;
					break;
				}
				sum -= a[ll];
				v += sum;
				if(v * b[ll] >= v + a[ll]) v *= b[ll];
				else v += a[ll];
				l = ll + 1;
			}
			cout << v << '\n';
		}
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}