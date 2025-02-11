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
void solve(int n){
    vector<array<int, 3>> a;
    for(int i = 1; i <= n; i++){
    	for(int j = i + 2; j <= n; j += 2){
    		for(int k = i; k <= j; k++){
    			a.push_back({i, j, k});
    		}
    	}
    }
    cout << n << ' ' << a.size() << '\n';
    for(auto [l, r, c] : a){
    	cout << l << ' ' << r << ' ' << c << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    // while(t--)solve();
    int test = 1;
    cout << test << '\n';
    for(int i = 150; i <= 150; i++){
    	solve(i);
    }
    return 0;
}