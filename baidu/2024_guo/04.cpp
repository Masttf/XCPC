#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int val;
	int len;
	pair<int ,int>s[30];
	node(){
		val = len = 0;
	}
};
void solve(){
	int n, q; cin >> n >> q;
	vector<int>ty(2 * n + 1);
	for(int i = 1; i <= n; i++){
		char c; cin >> c;
		ty[i] = c - 'A';
	}
	vector<int>a(2 * n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = n + 1; i <= 2 * n; i++){
		a[i] = a[i - n];
		ty[i] = ty[i - 1];
	}
	int N = 2 * n;
	vector<node>tr(N * 4);
	auto up = [&](node x, node y) -> node{
		node res;
		vector<pair<int, int>>stk;
		vector<int>last(30);

	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){

			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 |1]);
	};
	for(int i = 1; i <= q; i++){
		int op, x, y; cin >> op >> x >> y;
		if(op == 1){
			a[x] = a[x + n] = y;
		}else{
			if(y < x)y += n;
			
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; cin >> t;
	while(t--)solve();
	return 0;
}