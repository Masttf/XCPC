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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    vector<char> ans(n + 1, '.');
    int lg = -1, lh = -1;
    for(int i = 1; i <= n; i++){
    	if(s[i] == 'G'){
    		if(lg == -1 || i - lg > k){
    			int r = min(i + k, n);
    			while(ans[r] != '.')r--;
    			ans[r] = 'G';
    			lg = r;
    		}
    	}else{
    		if(lh == -1 || i - lh > k){
    			int r = min(i + k, n);
    			while(ans[r] != '.')r--;
    			ans[r] = 'H';
    			lh = r;
    		}
    	}
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	if(ans[i] != '.')cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++){
    	cout << ans[i];
    }
    cout << '\n';
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