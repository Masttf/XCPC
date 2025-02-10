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
    int n, t, k; cin >> n >> t >> k;
    auto check = [&](int x) -> bool{
    	if(x - 1 > k)return false;
    	int num = x * (t + 1);
    	return n - num >= k - x;
    };
    int l = 0, r = n;
    int ans = 0;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}else r = mid - 1;
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
每隔t场小L讲一次最优

20 4 3
4*4*
*/