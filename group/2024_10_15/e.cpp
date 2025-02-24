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
    int n, p, q; cin >> n >> p >> q;
    int ans = 0;
    vector<vector<int>> good(n + 1), bad(n + 1);
    for(int i = 1; i <= p; i++){
    	int u, v; cin >> u >> v;
    	good[u].push_back(v);
    	good[v].push_back(u);
    }
    for(int i = 1; i <= q; i++){
    	int u, v; cin >> u >> v;
    	bad[u].push_back(v);
    	bad[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        int tot = n - 1;
        if(!good[i].empty() || !bad[i].empty()){
            map<int, int> use;
            for(auto x : bad[i]) use[x] = 1;
            for(auto x : bad[i]){
                for(auto v : good[x]){
                    use[v] = 1;
                }
            }
            for(auto x : good[i]){
                for(auto v : bad[x]){
                    use[v] = 1;
                }
            }
            for(auto x : good[i]){
                use.erase(x);
            }
            tot -= use.size();
        }
        ans += tot;
    }
    ans = ans / 2;
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}