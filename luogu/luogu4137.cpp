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
    int n, q; cin >> n >> q;
    int N = 2e5 + 5;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector<int> ans(q + 1);
    vector<node> Q;
    int mx = 0;
    int block = sqrt(n);
    vector<array<int, 2>> stk;
    vector<int> cnt(N);
    auto del = [&](int x, int tp) -> void{
    	if(tp)stk.push_back({a[x], mx});
    	cnt[a[x]]--;
    	if(!cnt[a[x]]) mx = min(mx, a[x]);
    };
    auto rollback = [&]() -> void{
    	while(stk.size()){
    		auto [x, v] = stk.back();
    		stk.pop_back();
    		cnt[x]++;
    		mx = v;
    	}
    };
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	if(l / block == r / block){
    		mx = 0;
    		for(int j = l; j <= r; j++){
    			cnt[a[j]]++;
    		}
    		while(cnt[mx])mx++;
    		ans[i] = mx;
    		for(int j = l; j <= r; j++){
    			cnt[a[j]]--;
    		}
    	}else Q.push_back({l, r, i, l / block});
    }
    sort(Q.begin(), Q.end(), [&](node x, node y) -> bool{
    	if(x.blk != y.blk)return x.l < y.l;
    	return x.r > y.r;
    });
    int sz = Q.size();
    for(int i = 0, l, r; i < sz; i++){
    	auto [ll, rr, id, blk] = Q[i];
    	if(!i || blk != Q[i - 1].blk){
    		l = max(1ll, blk * block);
    		r = n;
    		cnt.assign(n + 1, 0);
    		mx = 0;
    		for(int j = l; j <= r; j++){
    			cnt[a[j]]++;
    		}
    		while(cnt[mx])mx++;
    	}
    	while(r > rr)del(r--, 0);
    	while(l < ll)del(l++, 1);
    	ans[id] = mx;
    	rollback();
    	l = max(1ll, blk * block);
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