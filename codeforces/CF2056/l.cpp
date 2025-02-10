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
    int ans = n;
    int l = 1;
    map<char, int> m;
    for(int i = 1; i <= n; i++){
    	m[s[i]]++;
    	while(m.size() == 26){
    		m[s[l]]--;
    		if(m[s[l]] == 0)m.erase(s[l]);
    		l++;
    		if(m.size() == 25){
    			l--;
    			m[s[l]]++;
    			break;
    		}
    	}
    	if(m.size() == 26){
    		ans = min(ans, i - l + 1);
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