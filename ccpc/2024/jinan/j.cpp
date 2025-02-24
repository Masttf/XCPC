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
    map<int, int>x;
    map<int, int>y;
    map<int, int>z;
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int xx, yy, zz; cin >> xx >> yy >> zz;
    	x[xx]++;
    	y[yy]++;
    	z[zz]++;
    	a[i] = {xx, yy, zz};
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
    	int mx = max({x[a[i][0]], y[a[i][1]], z[a[i][2]]}) - 1;
    	ans[mx + 1]++;
    }
    for(int i = 1; i < n; i++)ans[i] += ans[i - 1];
    for(int i = 0; i < n; i++){
    	cout << ans[i] << ' ';
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