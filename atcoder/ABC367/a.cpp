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
    int a, b, c; cin >> a >> b >> c;
    if(b <= c){
    	if(b <= a && a <= c){
    		cout << "No\n";
    	}else cout << "Yes\n";
    }else{
    	if(b <= a || a <= c){
    		cout << "No\n";
    	}else cout << "Yes\n";
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