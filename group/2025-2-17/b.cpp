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
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n + 1, -1);
    for(int i = y; i <= x; i++){
    	a[i] = 1;
    }
    for(int i = y - 1; i >= 1; i--){
    	a[i] = -a[i + 1];
    }
    for(int i = x + 1; i <= n; i++){
    	a[i] = -a[i - 1];
    }
    for(int i = 1; i <= n; i++){
    	cout << a[i] << " \n"[i == n];
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
/*
    x
-111111-1-1-1
y
-1-1-1 1 1 1 -1 -1 -1 -1
如果总和< 0 不行
11111  -1
*/