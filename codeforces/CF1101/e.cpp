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
    int mx = 0, my = 0;
    for(int i = 1; i <= n; i++){
    	char op; cin >> op;
    	if(op == '+'){
    		int x, y; cin >> x >> y;
    		if(x < y)swap(x, y);
    		mx = max(mx, x);
    		my = max(my, y);
    	}else{
    		int h, w; cin >> h >> w;
    		if(h < w)swap(h, w);
    		if(mx > h || my > w)cout << "NO\n";
    		else cout << "YES\n";
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