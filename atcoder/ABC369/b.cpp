#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    vector<pair<int, char>> a(n + 1 );

    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	char c; cin >> c;
    	a[i] = {x, c};
    }
    int ans = 1e18;
    for(int i = 1; i <= 100; i++){
    	for(int j = 1; j <= 100; j++){
    		int l = i, r = j;
    		int res = 0;
    		for(int k = 1; k <= n; k++){
    			auto [x, c] = a[k];
    			if(c == 'L'){
    				res += abs(x - l);
    				l = x;
    			}else{
    				res += abs(x - r);
    				r = x;
    			}
    		}
    		ans = min(ans, res);
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}