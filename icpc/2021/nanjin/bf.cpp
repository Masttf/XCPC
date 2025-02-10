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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> ans(n + 1);
    for(int k = 1; k <= n; k++){
        // dbg(k);
    	auto b = a;
    	int cnt = 0;
    	for(int i = 1; i <= k; i++){
    		for(int j = 1; j <= k; j++){
    			if(b[i] < b[j]){
    				cnt++;
    				swap(b[i], b[j]);
    			}
    		}
	    	// for(int j = 1; j <= i; j++){
	    	// 	cout << b[j] << " \n"[j == i];
	    	// }
    	}
    	ans[k] = cnt;
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] <<  " \n"[i == n];
    }
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