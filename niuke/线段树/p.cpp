#include<bits/stdc++.h>
// #define int long long
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
struct node{
	int ls, rs;
	int cnt;
};
void solve(){
    int n, c, m; cin >> n >> c >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> pos(c + 1);
    vector<int> last(c + 1);
    vector<node> tr(n * 32);
    vector<int> root(n + 1);
    int tot = 0;
    auto updata = [&](auto self, int &u, int v, int l, int r, int x, int val) -> void{
		u = ++tot;
		tr[u] = tr[v];
		tr[u].cnt += val;
		// dbg(l, r, tr[u].cnt, tr[v].cnt);
		if(l == r)return ;
    	int mid = (l + r) >> 1;
    	if(x <= mid) self(self, tr[u].ls, tr[v].ls, l, mid, x, val);
    	else self(self, tr[u].rs, tr[v].rs, mid + 1, r, x, val);
    };
    auto query = [&](auto self, int l, int r, int x, int y, int p) -> int{
    	if(x <= l && r <= y)return tr[p].cnt;
    	int mid = (l + r) >> 1;
    	int res = 0;
    	if(x <= mid)res += self(self, l, mid, x, y, tr[p].ls);
    	if(y > mid)res += self(self, mid + 1, r, x, y, tr[p].rs);
    	return res;
    };
    for(int i = 1; i <= n; i++){
    	int u = root[i - 1];
    	// dbg(i);
    	if(last[a[i]]){
    		// dbg(last[a[i]], -1);
    		updata(updata, u, root[i - 1], 1, n, last[a[i]], -1);
    	}
    	if(pos[a[i]]){
    		// dbg(pos[a[i]], 1);
    		updata(updata, root[i], u, 1, n, pos[a[i]], 1);
    	}
    	if(!root[i])root[i] = root[i - 1];
    	last[a[i]] = pos[a[i]];
    	pos[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
    	int l, r; cin >> l >> r;
    	cout << query(query, 1, n, l, r, root[r]) << '\n';
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