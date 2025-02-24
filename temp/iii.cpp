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
    int n, v; cin >> n >> v;
    vector<int> a(n + 1);
    double sum = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	sum += sqrt(a[i]);
    }
    double k = v / sum;
    double ans = sum / k;
   	cout << fixed << setprecision(10) << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case " << i << ": ";
    	solve();
    }
    return 0;
}