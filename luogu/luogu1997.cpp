#include<bits/stdc++.h>
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
// constexpr int N = 2e5 + 5;
struct node{
	int l, r, id;
};
void solve(){
    int n, q; cin >> n >> q;
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
    for(int i = 1; i <= n; i++){
    	a[i] = get(a[i]);
    }
    vector<node>Q(q + 1);
    vector<int> ans(q + 1);
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	Q[i] = {l, r, i};
    }
    int block = sqrt(n);
    while(block * block < n)block++;
    while(block * block > n)block--;
    sort(Q.begin() + 1, Q.end(), [&](node a, node b) -> bool{
    	if(a.l / block != b.l / block){
    		return a.l < b.l;
    	}
    	return a.r < b. r;
	});
    vector<int> cnt(n + 1);
    vector<int> ccnt(n + 1);
    int mx = 0;
    auto add = [&](int x) -> void{
    	cnt[a[x]]++;
    	ccnt[cnt[a[x]]]++;
    	mx = max(mx, cnt[a[x]]);
    };
    auto del = [&](int x) -> void{
    	ccnt[cnt[a[x]]]--;
    	cnt[a[x]]--;
    	if(ccnt[mx] == 0)mx--;
    };
    int L = 1, R = 0;
    for(int i = 1; i <= q; i++){
    	auto [l, r, id] = Q[i];
        while(L > l)add(--L);
        while(R < r)add(++R);
        while(L < l)del(L++);
        while(R > r)del(R--);
    	ans[id] = mx;
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