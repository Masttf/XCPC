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
    vector<char> ans(n + 1, '#');
    for(int l = 0; l < 26; l++){
    	for(int r = 0; r < 26; r++){
    		if(l + r > n)continue;
    		int temp = 0;
    		if(n - l - r >= 2){
    			temp = max(l, r) + (n - l - r) - 1;
    		}else{
    			temp = min(l, r);
    		}
    		if(temp == m){
    			cout << "YES\n";
    			string ans = "";
	    		for(char c = 'a'; c < 'a' + l; c++){
	    			ans += c;
	    		}
	    		for(int i = 1; i <= n - l - r; i++){
	    			ans += 'z';
	    		}
	    		for(char c = 'a' + r - 1; c >= 'a'; c--){
	    			ans += c;
	    		}
	    		cout << ans << '\n';
	    		return ;
    		}
    	}
    }
    cout << "NO\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}