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
    int n, m; cin >> n >> m;
    int ans = n * n;
    set<pair<int, int>>s;
    for(int i = 1; i <= m; i++){
    	int x, y; cin >> x >> y;
    	s.insert({x, y});
    	s.insert({x + 2, y + 1});
    	s.insert({x + 1, y + 2});
    	s.insert({x - 1, y + 2});
    	s.insert({x - 2, y + 1});
    	s.insert({x - 2, y - 1});
    	s.insert({x - 1, y - 2});
    	s.insert({x + 1, y - 2});
    	s.insert({x + 2, y - 1});
    }
    ans -= s.size();
    for(auto [x, y] : s){
    	if(x <= 0 || y > n || y <= 0 || x > n)ans++;
    }
    cout << ans << '\n';
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