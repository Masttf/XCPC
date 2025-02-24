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
    int n = 2024;
    int ans = 0;
    for(int i = 2; i * i <= n; i++){
    	if(n % i == 0){
    		ans++;
    		while(n % i == 0){
    			dbg(i);
    			n /= i;
    		}
    	}
    }
    if(n > 1)ans++;
    dbg(n);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}