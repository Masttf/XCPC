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
    int n = 100000;
    int m = 100000;
    cout << n << ' ' << m << '\n';
    mt19937 rd(time(0));
    for(int i = 1; i <= m / 2; i++){
    	int l = rd() % n + 1;
    	int r = rd() % n + 1;
    	while(r < l){
    		r = rd() % n + 1;
    	}
    	int v = rd();
    	v %= 61;
    	cout << 1 << ' ' << l << ' ' << r << ' ' << v << '\n';
    }
    for(int i = 1; i <= m / 2; i++){
    	int l = rd() % n + 1;
    	int r = rd() % n + 1;
    	while(r < l){
    		r = rd() % n + 1;
    	}
    	cout << 2 << ' ' << l << ' ' << r << '\n';
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