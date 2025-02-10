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
	mt19937 rd(time(0));
    int n = 100;
    int x = rd() % 10 + 1;
    int y = rd() % 10 + 1;
    cout << n << ' ' << x << ' ' << y << '\n';
    for(int i = 1; i <= n; i++){
    	int d1 = rd() % 10 + 1;
    	int d2 = rd() % 10 + 1;
    	cout << d1 << ' ' << d2 << '\n';
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