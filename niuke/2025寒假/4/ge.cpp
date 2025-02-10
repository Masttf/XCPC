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
    int n = 1e5;
    int q = 1e5;
    srand(time(0));
    cout << n << ' ' << q << '\n';
    for(int i = 1; i <= n; i++){
    	cout << rand() << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= q; i++){
    	int l = rand() % n + 1;
    	int r = rand() % n + 1;
    	while(l > r){
    		r = rand() % n + 1;
    	}
    	cout << l << ' ' << r << '\n';
    }
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