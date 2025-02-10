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
    int n = 2e4;
    cout << n << '\n';
    int mx = (1 << 15) - 1 << '\n';
    // int tot = 0;
    for(int i = 1; i <= n - 14; i++){
    	cout << (1 << 15) - 1 << ' ';
        // tot++;
    }
    for(int i = 14; i >= 1; i--){
    	cout << (1 << i) - 1 << ' ';
        // tot++;
    }
    cout << '\n';
    for(int i = 1; i <= n - 14; i++){
        cout << (1 << 15) - 1 << ' ';
        // tot++;
    }
    for(int i = 14; i >= 1; i--){
        cout << (1 << i) - 1 << ' ';
        // tot++;
    }
    cout << '\n';
    // dbg(tot);
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