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
    map<int, int>m;
    for(int i = 1; i <= q; i++){
    	int ty; cin >> ty;
    	if(ty == 3){
    		cout << m.size() << '\n';
    	}else if(ty == 1){
    		int x; cin >> x;
    		m[x]++;
    	}else {
    		int x; cin >> x;
    		m[x]--;
    		if(m[x] == 0)m.erase(x);
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}