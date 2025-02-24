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
    int m = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	m = max(m, (int)a[i].size());
    	a[i] = " " + a[i];
    }
    vector ans(m + 1, vector<char>(n + 1, ' '));
    for(int i = 1; i <= n; i++){
    	int sz = a[i].size() - 1;
    	for(int j = 1; j <= sz; j++){
    		ans[j][n - i + 1] = a[i][j];
    	}
    }
    for(int i = 1; i <= m; i++){
    	int flag = 0;
    	for(int j = n; j >= 1; j--){
    		if(ans[i][j] == ' '){
    			if(flag)ans[i][j] = '*';
    		}else flag = 1;
    	}
    }
    for(int i = 1; i <= m; i++){
    	for(int j = 1; j <= n; j++){
    		if(ans[i][j] == ' ')break;
    		cout << ans[i][j];
    	}
    	cout << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}