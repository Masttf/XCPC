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
    vector<int> ans(n + 1);
    vector<int> root(n + 1);
    ans[0] = 1;
    int tot = n - 1;
    int l = 1;
    int sum = 0;
    while(tot >= 2 * k){
    	ans[l] = k;
    	tot -= k;
    	sum += l * ans[l];
    	l++;
    }
    ans[l] = tot;
    sum += l * tot;
    // dbg(l, sum);
    if(sum < d){
    	cout << "NO\n";
    	return ;
    }else{
    	int flag = 0;
    	for(int i = l; i >= 1; i--){
    		int ret = ans[i] - k;
    		if(sum - ret > d){
    			if(flag || sum - ans[i] < d){
    				sum -= ret;
    				ans[i - 1] += ret;
    				ans[i] = k;
    			}else{
    				flag = 1;
    				ans[i - 1] += ans[i];
	    			sum -= ans[i];
	    			ans[i] = 0;
    			}
    		}else{
    			for(int j = 1; j <= ret; j++){
    				if(sum - 1 >= d){
    					sum--;
    					ans[i - 1]++;
    					ans[i]--;
    				}
    			}
    			cout << "YES\n";
    			root[0] = 1;
    			int r = 1;
    			root[1] = 2;
    			for(int j = 2; j <= n; j++){
    				// dbg(ans[r], r, j);
    				if(ans[r] == 0)r++, root[r] = j;
    				cout << root[r - 1] << ' ';
    				ans[r]--;
    			}
    			cout << '\n';
    			return ;
    		}
    	}
    }
    cout << "NO\n";
    for(int j = 0; j <= n; j++){
		cout << ans[j] << ' ';
	}
	cout << endl;
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