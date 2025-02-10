#include<bits/stdc++.h>
#define int long long
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
void solve(){
    int n; cin >> n;
    vector<int> val(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	cin >> val[i];
    	g[x].push_back(i);
    }
    vector<int> sum(n + 1);
    auto dfs = [&](auto self, int now) -> void{
    	if(g[now].empty())sum[now] = val[now];
    	for(auto v : g[now]){
    		self(self, v);
    		sum[now] += sum[v];
    	}
    };
    dfs(dfs, 0);
    if(sum[0] > 2200){
    	cout << "NO\n";
    	return ;
    }
    vector<int> a, b;
    for(int i = 1; i <= n; i++){
    	if(!g[i].empty()){
    		// dbg(i, val[i], sum[i]);
    		a.push_back(val[i]);
    		b.push_back(sum[i]);
    	}
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sz = a.size();
    for(int i = 0; i < sz; i++){
    	if(b[i] > a[i]){
    		cout << "NO\n";
    		return ;
    	}
    }
    cout << "YES\n";
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