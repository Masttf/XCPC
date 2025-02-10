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
	int mi, pos, tag1;
	int sum, tag3;
};
void solve(){
    int n, k, q; cin >> n >> k >> q;
    int N = 2 * n;
    int m = n - k + 1;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] -= i - n;
    }
    {
    	vector<int> tr(N * 4);
    	auto updata = [&](auto self, int l, int r, int x, int val, int p) -> void{
    		if(l == r){
    			tr[p] += val;
    			return ;
    		}
    		int mid = (l + r) >> 1;
    		if(x <= mid)self(self, l, mid, x, val, p << 1);
    		else self(self, mid + 1, r, x, val, p << 1 | 1);
    		tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
    	};
    	for(int i = 1; i <= k; i++){
    		updata(updata, 1, N, a[i], 1, 1);
    	}
    	for(int i = 1; i <= m; i++){
    		b[i] = k - tr[1];
    		if(i != m)updata(updata, 1, N, a[i + k], 1, 1);
    		updata(updata, 1, N, a[i], -1, 1);
    	}
    }
    // for(int i = 1; i <= m; i++){
    // 	cout << b[i] << " \n"[i == m];
    // }
    vector Q(m + 1, vector<pair<int, int>>());
    vector<int> ans(q + 1);
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	r = r - k + 1;
    	Q[r].push_back({l, i});
    }
    vector<int> stk;
    vector<int> nex(m + 1);
    for(int i = m; i >= 1; i--){
    	while(!stk.empty() && b[stk.back()] >= b[i]){
    		stk.pop_back();
    	}
    	if(stk.empty())nex[i] = m + 1;
    	else nex[i] = stk.back();
    	stk.push_back(i);
    }
    
    vector<node>tr(m * 4);
    auto bulid = [&](auto self, int l, int r, int p) -> void{
    	tr[p].mi = k;
    	tr[p].tag1 = -1;
    	if(l == r)return ;
    	int mid = (l + r) >> 1;
    	self(self, l, mid, p << 1);
    	self(self, mid + 1, r, p << 1 | 1);
    };
    bulid(bulid, 1, m, 1);

    auto cg = [&](node &x, int val1, int val3) -> void{
    	if(val1 != -1){
    		x.mi = b[val1];
	    	x.pos = val1;
	    	x.tag1 = val1;
    	}
    	x.sum += val3;
    	x.tag3 += val3;
    };
    auto down = [&](int p) -> void{
		cg(tr[p << 1], tr[p].tag1, tr[p].tag3);
		cg(tr[p << 1 | 1], tr[p].tag1, tr[p].tag3);
		tr[p].tag1 = -1;
    	tr[p].tag3 = 0;
    };
    auto updata = [&](auto self, int l, int r, int x, int y, int val1, int val3, int p) -> void{
    	if(x <= l && r <= y){
    		cg(tr[p], val1, val3);
    		return ;
    	}
    	down(p);
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, y, val1, val3, p << 1);
    	if(y > mid)self(self, mid + 1, r, x, y, val1, val3, p << 1 | 1);
    	tr[p].mi = max(tr[p << 1].mi, tr[p << 1 | 1].mi);
    };
    auto query_mi = [&](auto self, int l, int r, int val, int p) -> int{
    	if(l == r)return l;
    	down(p);
    	int mid = (l + r) >> 1;
    	if(tr[p << 1].mi <= val)return self(self, mid + 1, r, val, p << 1 | 1);
    	else return self(self, l, mid, val, p << 1);
    };
    auto query = [&](auto self, int l, int r, int x, int p) -> pair<int, int>{
    	if(l == r){
    		return {tr[p].sum, tr[p].pos};
    	}
    	down(p);
    	int mid = (l + r) >> 1;
    	if(x <= mid)return self(self, l, mid, x, p << 1);
    	else return self(self, mid + 1, r, x, p << 1 | 1);
    };
    for(int i = 1; i <= m; i++){
    	int pos = query_mi(query_mi, 1, m, b[i], 1);
    	//dbg(pos, i, b[i], nex[i]);
    	updata(updata, 1, m, pos, i, i, (nex[i] - i) * b[i], 1);
    	for(auto [l, id] : Q[i]){
    		//dbg(l, i, id);
    		auto [sum, lim] = query(query, 1, m, l, 1);
    		ans[id] = sum - b[lim] * (nex[lim] - i - 1); 
    	}
    }
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