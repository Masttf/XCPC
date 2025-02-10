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
    int n, m; cin >> m >> n;
    int ans = 0;
    deque<int> q;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	int ok = 0;
    	for(auto y : q){
    		if(y == x)ok = 1;
    	}
    	if(ok)continue;
    	ans++;
    	q.push_back(x);
    	if(q.size() > m)q.pop_front();
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