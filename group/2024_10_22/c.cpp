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
constexpr int maxn = 1e7 + 5;
struct node{
	int lson, rson;
	int val;
};
node tr[maxn]; //
// vector<node> tr(maxn);
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> b[i];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    int tot = 0;
    auto update = [&](auto self, int l, int r, int x, int &p) -> void{
    	if(!p)p = ++tot;
    	tr[p].val++;
    	if(l == r)return ;
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, tr[p].lson);
    	else self(self, mid + 1, r, x, tr[p].rson);
    };
    int target;
    auto query = [&](auto self, int l, int r, int x, int y, int p) -> int{
    	// dbg(l, r);
    	if(!p)return max(l, x);
    	if(x <= l && r <= y){
    		if(tr[p].val == r - l + 1) return -1;
    		if(l == r)return l;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid){
    		int res = self(self, l, mid, x, y, tr[p].lson);
    		if(res != -1)return res;
    	}
    	if(y > mid) return self(self, mid + 1, r, x, y, tr[p].rson);
    	return -1;
    };
    int root = 0;
    int L = 1, R = a[n] + n;
    vector<int> ret(1);
    for(int i = n; i >= 1; i--){
    	int d = query(query, L, R, a[i], R, root);
    	// dbg(i, d);
    	update(update, L, R, d, root);
    	ret.push_back(d - a[i]);
    }
    unsigned long long ans = 0;
    sort(ret.begin() + 1, ret.end(), greater<int>());
    for(int i = 1; i <= n; i++){
    	ans += 1ull * ret[i] * b[i];
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}