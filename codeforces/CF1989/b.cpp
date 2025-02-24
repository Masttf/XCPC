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
    string a, b; cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int ans = n + m;
    for(int s = 0; s < m; s++){
    	int r = -1;
    	for(int i = s, j = 0; i < m; i++){
    		while(j < n && a[j] != b[i]){
    			j++;
    		}
    		if(j == n)break;
    		r = i - s;
    		j++;
    	}
    	// dbg(s, r);
    	ans = min(ans, n + m - r - 1);
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