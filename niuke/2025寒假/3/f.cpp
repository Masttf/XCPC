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
    int n, a, b, c; cin >> n >> a >> b >> c;
    if(a + b + c < n || a + b + c > 2 * n){
    	cout << "No\n";
    	return ;
    }
    cout << "Yes\n";
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
/*
A 交 B = pos3
A 交 C = pos1
B 交 C = pos5

n = 20
6 个循
20 ^20 ^ 20 ^ 20 ^ 20 ^ 20
*/