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
void solve(){
    int n; cin >> n;
    int x; cin >> x;
    vector<array<int, 3>>a (n +1);
    vector<int>p;
    for(int i = 1; i <= n; i++){
    	int l, r, v; cin >> l >> r >> v;
    	a[i] = {l, r, v};
    	p.push_back(v);
    }
    sort(p.begin(), p.end());
    sort(a.begin() + 1, a.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    
    vector<int>tr(n + 1);
    auto add = [&](int x, int val) -> void{
    	while(x <= n){
    		tr[x] += val;
    		x += lowbit(x);
    	}
    };
    auto ask = [&](int x) -> int{
    	int res = 0;
    	while(x){
    		res += tr[x];
    		x -= lowbit(x);
    	}
    	return res;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    int ans = x;
    for(int i = 1; i <= n; i++){
    	auto [l, r, v] = a[i];
    	q.push({r, v});
    	add(get(v), v);
    	while(!q.empty() && q.top().first <= l){
    		auto [rr, vv] = q.top();
    		add(get(vv), -vv);
    		q.pop();
    	}
    	int res = x;
    	int pos = upper_bound(p.begin(), p.end(), res) - p.begin();
    	int last = 0;
    	int d = ask(pos) - ask(last);
    	while(d){
    		last = pos;
    		res += d;
    		pos = upper_bound(p.begin(), p.end(), res) - p.begin();
    		d = ask(pos) - ask(last);
    	}
    	ans = max(ans, res);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}