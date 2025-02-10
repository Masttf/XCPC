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
    int lx, ly; cin >> lx >> ly;
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> x[i];
    }
    for(int i = 1; i <= n; i++){
    	cin >> y[i];
    }
    sort(x.begin() + 1, x.end(), greater<int>());
    sort(y.begin() + 1, y.end(), greater<int>());
    int ans = n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	sum += x[i];
    	if(sum > lx){
    		ans = min(ans, i);
    		break;
    	}
    }
    sum = 0;
    for(int i = 1; i <= n; i++){
    	sum += y[i];
    	if(sum > ly){
    		ans = min(ans, i);
    		break;
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