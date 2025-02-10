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
    int q; cin >> q;
    deque<int> Q;
    int tag = 0;
    for(int i = 1; i <= q; i++){
    	int ty; cin >> ty;
    	if(ty == 1){
    		Q.push_front(-tag);
    	}else if(ty == 2){
    		int x; cin >> x;
    		tag += x;
    	}else{
    		int h; cin >> h;
    		int ans = 0;
    		while(!Q.empty() && Q.back() + tag >= h){
    			ans++;
    			Q.pop_back();
    		}
    		cout << ans << '\n';
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