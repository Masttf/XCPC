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
int a[] = {0, 9226, 4690, 4873, 1285, 4624, 1596, 6982, 590, 8806, 121, 8399, 8526, 5426, 64, 9655, 7705, 3929, 3588, 7397, 8020, 1311, 5676, 3469, 2325, 1226, 8203, 9524, 3648, 5278, 8647};
void solve(){
    int n = 30;
    int ans = 1e18;
    for(int i = 1; i <= 1e3; i++){
    	int sum = 0;
    	for(int j = 1; j <= n; j++){
    		sum += (i ^ a[j]) * (i ^ a[j]);
    	}
    	ans = min(ans, sum);
    }
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