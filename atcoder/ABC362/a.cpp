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
    int r, g, b; cin >> r >> g >> b;
    string  s; cin >> s;
    if(s[0] == 'B'){
    	cout << min(r, g) << '\n';
    }else if(s[0] == 'R'){
    	cout << min(g, b) << '\n';
    }else{
    	cout << min(r, b) << '\n';
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