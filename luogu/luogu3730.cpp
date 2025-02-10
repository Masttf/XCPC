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
	int l, r, id, k;
};
void solve(){
    int n, m; cin >> n >> m;
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
    vector<node> Q(m + 1);
	int block = sqrt(n);
	for(int i = 1; i <= m; i++){
		int l, r, k; cin >> l >> r >> k;
		Q[i] = {l, r, i, k};
	}
	sort(Q.begin() + 1, Q.end(), [&](node x, node y) -> bool{
		if(x.l / block != y.l / block)return x.l < y.l;
		if((x.l / block) & 1)return x.r > y.r;
		return x.r < y.r;
	});
	vector<int>sum(block + 1);
	vector<int>cnt(n + 1), sum2(n + 1);
	auto add = [&](int x) -> void{
		if(cnt[a[x]]){
			sum[cnt[a[x]] / block]--;
			sum2[cnt[a[x]]]--;
		}
		cnt[a[x]]++;
		sum[cnt[a[x]] / block]++;
		sum2[cnt[a[x]]]++;
	};
	auto del = [&](int x) -> void{
		sum[cnt[a[x]] / block]--;
		sum2[cnt[a[x]]]--;
		cnt[a[x]]--;
		if(cnt[a[x]]){
			sum[cnt[a[x]] / block]++;
			sum2[cnt[a[x]]]++;
		}
	};
	auto query = [&](int k) -> int{
		for(int i = 0; i <= block; i++){
			if(sum[i] < k)k -= sum[i];
			else{
				int l = max(1ll, i * block);
				while(k){
					if(k > sum2[l])k -= sum2[l];
					else return l;
					l++;
				}
			}
		}
		return -1;
	};
	int l = 1, r = 0;
	vector<int> ans(m + 1);
	for(int i = 1; i <= m; i++){
		auto [ll, rr, id, k] = Q[i];
		while(l > ll)add(--l);
		while(r < rr)add(++r);
		while(l < ll)del(l++);
		while(r > rr)del(r--);
		ans[id] = query(k);
	}
	for(int i = 1; i <= m; i++){
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