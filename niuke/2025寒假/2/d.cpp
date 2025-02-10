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
    vector<int> last(26);
    for(int i = 1; i <= n; i++){
    	int x = s[i] - 'a';
    	if(last[x]){
    		if(n - i + 1 > 1) ans = max(ans, n - i + 1);
    	}
    	last[x] = i;
    }
    last.assign(26, 0);
    for(int i = n; i >= 1; i--){
    	int x = s[i] - 'a';
    	if(last[x]){
    		if(i > 1) ans = max(ans, i);
    	}
    	last[x] = i;
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
/*
但是 k = 1 不可能
k也不可能 = n

check 最后一个字母 或者第一个字母
前缀有没有
或者后缀有没有
*/