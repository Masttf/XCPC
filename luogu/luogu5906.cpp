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
	int l, r, id, blk;
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> p;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	p.push_back(a[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(int i = 1; i <= n; i++) a[i] = get(a[i]);
    int q; cin >> q;
	
	
	vector<int>pre(n + 1), suf(n + 1), cnt(n + 1);
	vector<int> ans(q + 1);
	vector<node> Q;
	int mx = 0;
	int block = sqrt(n);
	vector<array<int, 4>> stk;
	auto add = [&](int x, int tp) -> void{
		if(tp)stk.push_back({pre[a[x]], suf[a[x]], a[x], mx});
		cnt[a[x]]++;
		if(cnt[a[x]] == 1){
			pre[a[x]] = suf[a[x]] = x;
		}else{
			mx = max({mx, abs(x - suf[a[x]]), abs(pre[a[x]] - x)});
			if(tp) pre[a[x]] = x;
			else suf[a[x]] = x;
		}
	};
	auto rollback = [&]() -> void{
		while(stk.size()){
			auto [last, nex, x, v] = stk.back();
			stk.pop_back();
			pre[x] = last;
			suf[x] = nex;
			cnt[x]--;
			mx = v;
		}
	};
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		if(l / block == r / block){
			for(int j = l; j <= r; j++){
				add(j, 1);
			}
			ans[i] = mx;
			rollback();
		}else Q.push_back({l, r, i, l / block});
	}
	sort(Q.begin(), Q.end(), [&](node x, node y) -> bool{
		if(x.blk != y.blk)return x.l < y.l;
		return x.r < y.r;
	});
	int sz = Q.size();
	for(int i = 0, l, r; i < sz; i++){
		auto [ll, rr, id, blk] = Q[i];
		if(!i || blk != Q[i - 1].blk){
			l = min(n + 1, blk * block + block);
			r = l - 1;
			mx = 0;
			cnt.assign(n + 1, 0);
		}
		while(r < rr)add(++r, 0);
		while(l > ll)add(--l, 1);
		ans[id] = mx;
		rollback();
		l = min(n + 1, blk * block + block);
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
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