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
struct Fenwick{
	int n;
	vector<int> tr;
	Fenwick(int n) : n(n), tr(n){}
	void add(int x, int val){
		while(x <= n){
			tr[x] += val;
			x += lowbit(x);
		}
	}
	int ask(int x){
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
};
void solve(){
    int n, K, q; cin >> n >> K >> q;
    int m = n - K + 1;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = a[i] - i;
    	a[i] += n;
    }
    
	vector<int> cnt(2 * n + 1);
    vector<int> ccnt(n + 1);
    int mx = 0;
    auto add = [&](int x) -> void{
    	x = a[x];
    	cnt[x]++;
    	ccnt[cnt[x]]++;
    	mx = max(mx, cnt[x]);
    };
    auto del = [&](int x) -> void{
    	x = a[x];
    	ccnt[cnt[x]]--;
    	cnt[x]--;
    	if(ccnt[mx] == 0)mx--;
    };
    for(int i = 1; i < K; i++) add(i);
    for(int i = 1; i <= m; i++){
    	add(i + K - 1);
    	if(i > 1)del(i - 1);
    	b[i] = K - mx;
    }
    
    vector st(21, vector<pair<int, int>>(m + 1));
    for(int i = 1; i <= m; i++){
    	st[0][i] = {b[i], i};
    }
    for(int k = 1; k <= 20; k++){
    	for(int i = 1; i + (1 << k) <= m + 1; i++){
    		st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    	}
    }
    auto get = [&](int l, int r) -> pair<int, int>{
    	int d = __lg(r - l + 1);
    	return min(st[d][l], st[d][r - (1 << d) + 1]);
    };

    vector<int>stk;
    vector<int> last(m + 1), nex(m + 1, m + 1);
    for(int i = 1; i <= m; i++){
    	while(!stk.empty() && b[i] < b[stk.back()]){
    		stk.pop_back();
    	}
    	if(!stk.empty())last[i] = stk.back();
    	stk.push_back(i);
    }
    stk.clear();
    for(int i = m; i >= 1; i--){
    	while(!stk.empty() && b[i] <= b[stk.back()]){
    		stk.pop_back();
    	}
    	if(!stk.empty())nex[i] = stk.back();
    	stk.push_back(i);
    }
    for(int i = 1; i <= m; i++){
    	cout << b[i] << " \n"[i == m];
    }
    for(int i = 1; i <= m; i++){
    	dbg(i, last[i], nex[i]);
    }
    vector<int> ans(q + 1);
    vector<vector<pair<int, int>>>op(m + 1);
    for(int i = 1; i <= m; i++){
    	op[nex[i] - 1].push_back({last[i] + 1, b[i] * (i - last[i]) * (nex[i] - i)});
    	
    }
    vector<vector<pair<int, int>>> Q1(m + 1), Q2(m + 1);
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	r = r - K + 1;
        dbg(l, r);
    	auto [mi, x] = get(l, r);
        // dbg(l, r, mi, x);
    	if(last[x] < l && r < nex[x]){
            dbg(x, i);
    		ans[i] = (x - l + 1) * (r - x + 1) * mi;
    		ans[i] -= (x - l + 1) * (nex[x] - i) * mi;
    		ans[i] -= (i - last[x]) * (r - x + 1) * mi;
    	}
    	Q1[r].push_back({l, i});
    	Q2[l].push_back({r, i});
    }
    for(int i = 1; i <= q; i++){
        dbg(i, ans[i]);
    }
    Fenwick t1(m + 1);
    for(int i = 1; i <= m; i++){
    	for(auto [l, val] : op[i]){
    		t1.add(l, val);
    	}
    	for(auto [l, id] : Q1[i]){
    		ans[id] += t1.ask(i) - t1.ask(l - 1);
    	}
    }
    for(int i = 1; i <= q; i++){
        dbg(i, ans[i]);
    }
    Fenwick t2(m + 1);
    Fenwick k2(m + 1);
    for(int i = 1; i <= m; i++){
        dbg(last[i] + 1, i, (nex[i] - i) * b[i]);
    	t2.add(last[i] + 1, (nex[i] - i) * b[i] * (i + 1));
    	t2.add(i + 1, (i - nex[i]) * b[i] * (i + 1));
    	k2.add(last[i] + 1, (nex[i] - i) * b[i]);
    	k2.add(i + 1, (i - nex[i]) * b[i]);
        dbg(t2.ask(2));
    	for(auto [l, id] : Q1[i]){
            dbg(t2.ask(l), k2.ask(l), id);
    		ans[id] += t2.ask(l) - k2.ask(l) * l;
    	}
    }
    for(int i = 1; i <= q; i++){
        dbg(i, ans[i]);
    }
    Fenwick t3(m + 1);
    Fenwick k3(m + 1);
    for(int i = m; i >= 1; i--){
    	t3.add(i, (i - last[i]) * b[i] * (1 - i));
    	t3.add(nex[i], -(i - last[i]) * b[i] * (1 - i));
    	k3.add(i, (i - last[i]) * b[i]);
    	k3.add(nex[i], -(i - last[i]) * b[i]);
    	for(auto [r, id] : Q2[i]){
    		ans[id] += k3.ask(r) * r + t3.ask(r);
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
