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
    vector<set<int, greater<>>>res(n + 1);
    for(int i = 1; i <= n; i++){
    	res[i].insert(i);
    }
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i++) f[i] = i;
    auto find = [&](int x) -> int{
    	while(f[x] != x){
    		x = f[x];
    	}
    	return x;
    };
    auto merge = [&](int a, int b) -> void{
    	int fa = find(a);
    	int fb = find(b);
    	if(fa == fb)return ;
    	if(res[fa].size() > res[fb].size())swap(fa, fb);
    	f[fa] = fb;
    	res[fb].insert(res[fa].begin(), res[fa].end());
    };
    int mx = 10;
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int u, v; cin >> u >> v;
    		merge(u, v);
    	}else{
    		int v, k; cin >> v >> k;
    		int fa = find(v);
    		if(res[fa].size() < k)cout << -1 << '\n';
    		else{
    			int cnt = 0;
    			for(auto x : res[fa]){
    				cnt++;
    				if(cnt == k){
    					cout << x << '\n';
    					break;
    				}
    			}
    		}
    	}
    }
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