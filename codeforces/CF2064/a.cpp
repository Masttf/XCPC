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
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(s[i] == '0')continue;
    	int j = i;
    	while(j <= n && s[j] == s[i]){
    		j++;
    	}
    	if(j <= n){
    		ans += 2;
    	}else ans++;
    	i = j - 1;
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