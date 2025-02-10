#include<bits/stdc++.h>
//#define int long long
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
	int l, r, val;
};
void solve(){
    int n, m; cin >> n >> m;
    int N = n + 2;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
    	a[i] = min(a[i], N);
    }
    vector<node>tr(N * 32);
	vector<int> root(n + 1);
	int tot = 0;
	auto up = [&](int p) -> void{
		int ls = tr[p].l;
		int rs = tr[p].r;
		tr[p].val = min(tr[ls].val, tr[rs].val);
	};
	auto updata = [&](auto self, int &u, int v, int l, int r, int x, int val) -> void{
		u = ++tot;
		tr[u] = tr[v];
		if(l == r){
			tr[u].val = val;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, tr[u].l, tr[v].l, l, mid, x, val);
		else self(self, tr[u].r, tr[v].r, mid + 1, r, x, val);
		up(u);
	};
	auto query = [&](auto self, int l, int r, int x, int p) -> int{
		if(l == r)return l;
		int mid = (l + r) >> 1;
		int ls = tr[p].l, rs = tr[p].r;
		if(tr[ls].val >= x)return self(self, mid + 1, r, x, rs);
		else return self(self, l, mid, x, ls);
	};
	for(int i = 1; i <= n; i++){
		updata(updata, root[i], root[i - 1], 0, N, a[i], i);
	}
	for(int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		cout << query(query, 0, N, l, root[r]) << '\n';
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