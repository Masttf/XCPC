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
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
struct node{
	int d[32];
	void init(){
		for(int i = 31; i >= 0; i--){
			d[i] = 0;
		}
	}
};
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a (n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n + 1);
	for(int i = 2; i <= n; i++){
		b[i] = a[i - 1] ^ a[i];
	}
	vector<node>tr(n * 4);
	auto insert = [&](node &x, int val) -> void{
		for(int i = 31; i >= 0; i--){
			if(val >> i & 1){
				if(x.d[i]){
					val ^= x.d[i];
				}else{
					x.d[i] = val;
					break;
				}
			}
		}
	};
	auto get_max = [&](node &x, int v) -> int{
		for(int i = 31; i >= 0; i--){
			if((v ^ x.d[i]) > v){
				v ^= x.d[i];
			}
		}
		return v;
	};
	auto up = [&](node x, node y) -> node{
		node res;
		for(int i = 31; i >= 0; i--){
			res.d[i] = x.d[i];
		}
		for(int i = 31; i >= 0; i--){
			if(y.d[i]){
				insert(res, y.d[i]);
			}
		}
		return res;
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			insert(tr[p], b[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
	};
	auto updata = [&](auto self, int l, int r, int x, int p) -> void{
		if(l == r){
			tr[p].init();
			insert(tr[p], b[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, p << 1);
		else self(self, mid + 1, r, x, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> node{
		if(x <= l && r <= y)return tr[p];
		node res;
		res.init();
		int mid = (l + r) >> 1;
		if(x <= mid)res = up(res, self(self, l, mid, x, y, p << 1));
		if(y > mid)res = up(res, self(self, mid + 1, r, x, y, p << 1 | 1));
		return res;
	};
	int block = sqrt(n);
	vector<int> tag(block + 1);
	auto add = [&](int l, int r, int v) -> void{
		if(l / block == r / block){
			for(int i = l; i <= r; i++){
				a[i] ^= v;
			}
			return ;
		}
		int L = l / block + 1;
		int R = r / block - 1;
		for(int i = L; i <= R; i++)tag[i] ^= v;
		for(int i = l; i < L * block; i++){
			a[i] ^= v;
		}
		R++;
		for(int i = R * block; i <= r; i++){
			a[i] ^= v;
		}
	};
	auto ask = [&](int x) -> int{
		return a[x] ^ tag[x / block];
	};

	bulid(bulid, 1, n, 1);
	for(int i = 1; i <= m; i++){
		int op, l, r, v;
		cin >> op >> l >> r >> v;
		if(op == 1){
			add(l, r, v);
			if(l >= 2){
				b[l] = ask(l - 1) ^ ask(l);
				updata(updata, 1, n, l, 1);
			}
			if(r + 1 <= n){
				b[r + 1] = ask(r) ^ ask(r + 1);
				updata(updata, 1, n, r + 1, 1);
			}
		}else{
			if(l == r){
				int ans = v;
				ans = max(ans, ans ^ ask(l));
				cout << ans << '\n';
			}else{
				node res = query(query, 1, n, l + 1, r, 1);
				insert(res, ask(l));
				int ans = get_max(res, v);
				cout << ans << '\n';
			}
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