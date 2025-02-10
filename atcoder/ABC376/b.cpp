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
    int n, q; cin >> n >> q;
    int l = 0, r = 1;
    int ans = 0;
    for(int i = 1; i <= q; i++){
    	char ty; cin >> ty;
    	int x; cin >> x;
    	x--;
    	if(ty == 'L'){
    		int t = l;
    		int cnt = 0;
    		while(t != x){
    			t--;
    			t = (t + n) % n;
    			if(t == r)break;
    			cnt++;
    		}
    		if(t == x)ans += cnt;
    		t = l;
    		cnt = 0;
    		while(t != x){
    			t++;
    			t = (t + n) % n;
    			if(t == r)break;
    			cnt++;
    		}
    		if(t == x)ans += cnt;
    		l = x;
    	}else{
    		int t = r;
    		int cnt = 0;
    		while(t != x){
    			t--;
    			t = (t + n) % n;
    			if(t == l)break;
    			cnt++;
    		}
    		if(t == x)ans += cnt;
    		t = r;
    		cnt = 0;
    		while(t != x){
    			t++;
    			t = (t + n) % n;
    			if(t == l)break;
    			cnt++;
    		}
    		if(t == x)ans += cnt;
    		r = x;
    	}
    	// dbg(i, ans);
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