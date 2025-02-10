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
    s = ' ' + s;
    int ans = 0;
    int now;
    for(int i = 1; i <= 26; i++){
    	if(s[i] == 'A')now = i;
    }
    for(int i = 1; i <= 26; i++){
    	char res = 'A' + i;
    	for(int j = 1; j <= 26; j++){
    		if(s[j] == res){
    			ans += abs(now - j);
    			now = j;
    			break;
    		}
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