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
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    	a[i][i] = '1';
    }
    vector<int> ans;
    vector<int> vis(n + 1);
    for(int j = 1; j <= n; j++){
    	if(vis[j])continue;
    	for(int i = n; i >= j; i--){
	    	if(a[j][i] == '1'){
	    		if(vis[i])continue;
	    		vis[i] = i;
	    		ans.push_back(i);
	    	}
	    }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
    	cout << x << " ";
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