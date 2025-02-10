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
mt19937 rd(time(0));
void solve(){
    int n = 20;
    cout << n << '\n';
    int limit = 100;
    for(int i = 1; i <= n; i++){
    	cout << rd() % limit << ' ';
    }
    cout << '\n';
    int m = 20;
    cout << m << '\n';
    for(int i = 1; i <= m / 2; i++){
    	int l = rd() % n + 1;
    	int r = rd() % n + 1;
    	while(r < l){
    		r = rd() % n + 1;
    	}
    	int d = rd() % limit;
    	cout << "update " << l << ' ' << r << ' ' << d << '\n';
    	l = rd() % n + 1;
    	r = rd() % n + 1;
    	while(r < l){
    		r = rd() % n + 1;
    	}
    	cout << "check " << l << ' ' << r << '\n';
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