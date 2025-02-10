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
    vector<int>vis(n + 1);
    for(int i = 1; i <= m; i++){
    	int x; cin >> x;
    	char ty; cin >> ty;
    	if(ty == 'M'){
    		if(vis[x])cout << "No\n";
    		else cout << "Yes\n";
    		vis[x] = 1;
    	}else cout << "No\n";
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