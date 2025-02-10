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
    int n, m; cin >> n >> m;
    int tot = m * (m + 1) / 2;
    if(tot % 2 == 0){
    	cout << "Yes\n";
    	vector<int> ans(m + 1);
    	tot /= 2;
    	tot -= m;
    	int cnt = 1;
    	while((cnt - 1) * cnt / 2 < tot)cnt++;
    	while((cnt - 1) * cnt / 2 > tot)cnt--;
    	vector<pair<int, int>>res;
    	int now = 1;
    	int rm = m;
    	while(tot || rm){
    		tot -= (cnt - 1) * cnt / 2;
    		rm -= cnt;
    		res.push_back({cnt, now ^ 1});
    		now ^= 1;
    		while((cnt - 1) * cnt / 2 > tot || cnt > rm)cnt--;
    	}
    	int l = 1;
    	for(auto [len, val] : res){
    		while(len--){
    			ans[l++] = val;
    		}
    	}
    	for(int j = 1; j <= n; j++){
    		for(int i = 1; i <= m; i++){
	    		cout << ans[i] << ' ';
	    	}
	    	cout << '\n';
    	}
    	return ;
    }
    swap(n, m);
    tot = m * (m + 1) / 2;
    if(tot % 2 == 0){
    	cout << "Yes\n";
    	vector<int> ans(m + 1);
    	tot /= 2;
    	tot -= m;
    	int cnt = 1;
    	while((cnt - 1) * cnt / 2 < tot)cnt++;
    	while((cnt - 1) * cnt / 2 > tot)cnt--;
    	vector<pair<int, int>>res;
    	int now = 1;
    	int rm = m;
    	while(tot || rm){
    		tot -= (cnt - 1) * cnt / 2;
    		rm -= cnt;
    		res.push_back({cnt, now ^ 1});
    		now ^= 1;
    		while((cnt - 1) * cnt / 2 > tot || cnt > rm)cnt--;
    	}
    	int l = 1;
    	for(auto [len, val] : res){
    		while(len--){
    			ans[l++] = val;
    		}
    	}
    	swap(n, m);
    	vector<vector<int>> temp(n + 1, vector<int>(m + 1));
    	for(int j = 1; j <= m; j++){
    		for(int i = 1; i <= n; i++){
    			temp[i][j] = ans[i];
    		}
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cout << temp[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	return ;
    }
    cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}