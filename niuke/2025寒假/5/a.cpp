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
    int x; cin >> x;
    char ty; cin >> ty;
    if(ty == '*'){
    	cout << 1 << ' ' << x << '\n';
    }else if(ty == '+'){
    	cout << 1 << ' ' << x - 1 << '\n';
    }else{
    	cout << x + 1 << ' ' << 1 << '\n';
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