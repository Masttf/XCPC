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
    string s; cin >> s;
    s = ' ' + s;
    string res = "uwawauwa";
    int pos = 0;
    vector<int> pre(n + 5);
    while(pos != -1){
    	pos = s.find(res, pos);
    	// dbg(pos);
    	if(pos == -1)break;
    	pre[pos]++;
    	pos++;
    }
    for(int i = n; i >= 1; i--){
    	pre[i] += pre[i + 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(s[i] == 'u'){
    		ans += pre[i + 2];
    	}
    }
    cout << ans << '\n';
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