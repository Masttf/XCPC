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
constexpr int maxn = 6e6 + 5;
struct node{
	int lson, rson;
	int val;
}tr[maxn];
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> root(m + 1);
    int tot = 0;
    int id = 1;
    auto up = [&](auto p) -> void{
    	int ls = tr[p].lson;
    	int rs = tr[p].rson;
    	tr[p].val = tr[ls].val + tr[rs].val;
    };
    auto bulid = [&](auto self, int l, int r, int &p) -> void{
    	p = ++tot;
    	if(l == r){
    		tr[p].val = a[l];
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	self(self, l, mid, tr[p].lson);
    	self(self, mid + 1, r, tr[p].rson);
    	up(p);
    };
    bulid(bulid, 1, n, root[1]);
    auto update = [&](auto self, int l, int r, int x, int val, int &p) -> void{
    	if(!p) p = ++tot;
    	if(l == r){
    		tr[p].val += val;
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, val, tr[p].lson);
    	else self(self, mid + 1, r, x, val, tr[p].rson);
    	up(p);
    };
    auto split = [&](auto self, int l, int r, int x, int y, int &u, int &v) -> void{
    	if(x <= l && r <= y){
    		v = u;
    		u = 0;
    		return ;
    	}
    	v = ++tot;
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, y, tr[u].lson, tr[v].lson);
    	if(y > mid)self(self, mid + 1, r, x, y, tr[u].rson, tr[v].rson);
    	up(u);
    	up(v);
    };
    auto merge = [&](auto self, int l, int r, int &x, int y) -> void{
    	if(!x || !y){
    		x = x | y;
    		return ;
    	}
    	tr[x].val += tr[y].val;
    	if(l == r)return ;
    	int mid = (l + r) >> 1;
    	self(self, l, mid, tr[x].lson, tr[y].lson);
    	self(self, mid + 1, r, tr[x].rson, tr[y].rson);
    };
    auto querySum = [&](auto self, int l, int r, int x, int y, int p) -> int{
    	if(!p)return 0;
    	if(x <= l && r <= y){
    		return tr[p].val;
    	}
    	int res = 0;
    	int mid = (l + r) >> 1;
    	if(x <= mid) res += self(self, l, mid, x, y, tr[p].lson);
    	if(y > mid) res += self(self, mid + 1, r, x, y, tr[p].rson);
    	return res;
    };
    auto findKth = [&](auto self, int l, int r, int k, int p) -> int{
    	if(l == r) return l;
    	int mid = (l + r) >> 1;
    	int v = tr[tr[p].lson].val;
    	if(k <= v)return self(self, l, mid, k, tr[p].lson);
    	else return self(self, mid + 1, r, k - v, tr[p].rson);
    };
    for(int i = 1; i <= m; i++){
    	int ty; cin >> ty;
    	if(ty == 0){
    		int p, x, y; cin >> p >> x >> y;
    		split(split, 1, n, x, y, root[p], root[++id]);
    	}else if(ty == 1){
    		int x, y; cin >> x >> y;
    		merge(merge, 1, n, root[x], root[y]);
    	}else if(ty == 2){
    		int p, x, y; cin >> p >> x >> y;
    		update(update, 1, n, y, x, root[p]);
    	}else if(ty == 3){
    		int p, x, y; cin >> p >> x >> y;
    		cout << querySum(querySum, 1, n, x, y, root[p]) << '\n';
    	}else{
    		int p, k; cin >> p >> k;
    		if(tr[root[p]].val < k){
    			cout << -1 << '\n';
    		}else{
    			cout << findKth(findKth, 1, n, k, root[p]) << '\n';
    		}
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}