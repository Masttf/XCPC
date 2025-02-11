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
    int n, x, y; cin >> n >> x >> y;
    int ans = 0;
    for(int i = 0; i <= y; i++){
    	if(i > n)break;
    	int len = n - i;
    	int an = x + i;
    	int a1 = an - len + 1;
    	int rm = y - i;
    	int tot = 0;
    	if(rm >= len){
    		tot += (an + 1) * len;
    	}else{
    		tot += (an + 1) * rm;
    		len -= rm;
    		a1 = an - len + 1;
    		if(a1 <= 0){
    			len = an;
    			a1 = 1;
    		}
    		tot += (a1 + an) * len / 2;
    	}
    	ans = max(ans, tot);
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
如何回合数够的话，肯定是先磨刀到最高再砍人，伤害是等差数列求和
直接枚举只磨刀不砍人的回合然后算出伤害即可
*/