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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	for(int j = 0; j < m; j++){
    		if(s[j] == 'o') a[i] |= (1 << j);
    	}
    }
    int ans = n;
  	vector<int> p(n + 1);
  	for(int i = 1; i <= n; i++)p[i] = i;
  	do{
  		int res = 0;
  		for(int i = 1; i <= n; i++){
  			res |= a[p[i]];
  			if(res == (1 << m) - 1){
  				ans = min(ans, i);
  				break;
  			}
  		}
  	}while(next_permutation(p.begin() + 1, p.end()));
    cout << ans << '\n';
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