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
    int k; cin >> k;
    int ans = 2 * k;
    int cnt = k;
    int t = 4;
    while(t <= ans){
    	t *= 2;
    	cnt--;
    }
    while(cnt < k){
    	ans += 2;
    	cnt++;
    	if(ans == t){
    		cnt--;
    		t *= 2;
    	}
    }
    cout << ans << '\n';
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
注意长度大于 1 
且去重
2 6 6 10 12 12 14 18 18 20 20 22 24 26 28 30 30 30 30 34 36 36 40 42 42 42 44 48 50 52 54 56 56 60 60 66 70 70 72 72 78 84 88 90 90

4，8, 16，32, 64, 128
2 的指数次没了
*/