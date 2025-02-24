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
    int n, d, k; cin >> n >> d >> k;
    vector<int> root(n + 1);
    vector<int> ans(n + 1);
    root[0] = 1;
    root[1] = 2;
    
    int l = 1;
    int res = n - 1 - k;
    int sum = k;
    ans[1] = k;
    while(res >= 0 && l <= n){
    	if(sum + res <= d && d <= sum + res * l){
    		cout << "YES\n";
    		sum += res;
    		ans[1] += res;
    		int need = d - sum;
    		for(int i = 1; i <= res; i++){
    			// dbg(i, need);
    			if(need >= l){
    				ans[l]++;
    				ans[1]--;
    				need -= l - 1;
    			}else{
    				ans[need + 1]++;
    				ans[1]--;
    				need = 0;
    			}
    		}
    		int r = 1;
    		for(int i = 2; i <=n; i++){
    			if(!ans[r])r++, root[r] = i;
    			cout << root[r - 1] << ' ';
    			ans[r]--;
    		}
    		cout << '\n';
    		return ;
    	}
    	res -= k;
    	sum += (l + 1) * k;
    	l++;
    	ans[l] = k;
    }
    cout << "NO\n";
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