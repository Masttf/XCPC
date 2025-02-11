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
    int x, y; cin >> x >> y;
    if(y == 0){
    	cout << "YES\n";
    	return ;
    }
    int sum = 2 * x + 1;
    if(abs(y - sum) % 4 != 0){
    	cout << "NO\n";
    }else cout << "YES\n";
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