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
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int N = 2e6;
constexpr int Max = 1e9;
struct node{
	int val, lval, rval, sum;
}tr[N * 4];
node up(node x, node y){
	node res = {-Max, -Max, -Max, -Max};
	res.val = max({x.val, y.val, x.rval + y.lval});
	res.lval = max(x.lval, x.sum + y.lval);
	res.rval = max(y.rval, x.rval + y.sum);
	res.sum = x.sum + y.sum;
	return res;
}
void cg(node &x, int val){
	x.val = x.lval = x.rval = x.sum = val;
}
void bulid(int l, int r, int p){
	tr[p].lval = tr[p].rval = tr[p].val = tr[p].sum = r - l + 1;
	if(l == r)return ;
	int mid = (l + r) >> 1;
	bulid(l, mid, p << 1);
	bulid(mid + 1, r, p << 1 | 1);
}
void updata(int l, int r, int x, int val, int p){
	if(l == r){
		cg(tr[p], val);
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)updata(l, mid, x, val, p << 1);
	else updata(mid + 1, r, x, val, p << 1 | 1);
	tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
}
int query(int l, int r, int x, int p){
	
}
void solve(){
	int n; cin >> n;
	vector<int>a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	set<int> s{0, N + 1};
	auto add = [&](int x) -> void{
		auto it = s.insert(x).first;
		auto l = prev(it);
		auto r = next(it);

	};
	auto del = [&](int x) -> void{
		auto it = s.insert(x).first;
		auto l = prev(it);
		auto r = next(it);

		s.erase(it);
	};

	for(int i = 1; i <= n; i++){
		add(a[i]);
	}
	int m; cin >> m;
	for(int i = 1; i <= m; i++){
		char t; cin >> t;
		int x; cin >> x;
		if(t == '+'){
			add(x);
		}else if(t == '-'){
			del(x);
		}else{
			
		}
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	bulid(1, N, 1);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}