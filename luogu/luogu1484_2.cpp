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
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>last(n + 5), nex(n + 5);
	vector<int>val(n + 5);
	set<pair<int, int>, greater<>>q;
	for(int i = 1; i <= n; i++){
		q.insert({a[i], i});
		val[i] = a[i];
		last[i] = i - 1;
		nex[i] = i + 1;
	}
	int ans = 0;
	while(k--){
		if(q.begin() -> first < 0)break;
		ans += q.begin() -> first;
		int x = q.begin() -> second;
		q.erase(q.begin());
		int u = last[x];
		int v = nex[x];
		q.erase({val[u], u});
		q.erase({val[v], v});
		val[x] = val[u] + val[v] - val[x];
		last[x] = last[u];
		nex[x] = nex[v];
		nex[last[x]] = x;
		last[nex[x]] = x;
		q.insert({val[x], x});
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}