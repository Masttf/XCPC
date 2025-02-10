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
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector pre(30, vector<int>(n + 1));
    vector suf(30, vector<int>(n + 5));
    for(int i = 1; i <= n; i++){
    	// dbg(i);
    	for(int j = 0; j < 26; j++){
    		pre[j][i] = pre[j][i - 1];
    	}
    	// dbg(s[i] - '')
    	pre[s[i] - 'A'][i]++;
    }
    // dbg("????");
    for(int i = n; i >= 1; i--){
    	for(int j = 0; j < 26; j++){
    		suf[j][i] = suf[j][i + 1];
    	}
    	suf[s[i] - 'A'][i]++;
    }
    // dbg("????");
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < 26; j++){
    		ans += pre[j][i - 1] * suf[j][i + 1];
    	}
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