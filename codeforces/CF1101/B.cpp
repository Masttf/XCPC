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
    int l = 0, r = n - 1;
    while(l < n && s[l] != '['){
    	l++;
    }
    while(r >= 0 && s[r] != ']'){
    	r--;
    }
    if(l >= r){
    	cout << -1 << '\n';
    	return ;
    }
    
    while(l < n && s[l] != ':'){
    	l++;
    }
    while(r >= 0 && s[r] != ':'){
    	r--;
    }
    if(l >= r){
    	cout << -1 << '\n';
    	return ;
    }
    int ans = 4;
    for(int i = l; i < r; i++){
    	if(s[i] == '|')ans++;
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