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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> ans;
	vector<int> vis(n + 1);
	if(n > 4){
		ans.push_back({4, n});
		for(int i = 4; i <= n; i++){
			vis[a[i]] = 1;
		}
		int i = 0;
		while(1){
			if(!vis[i]){
				a[4] = i;
				break;
			}
			i++;
		}
	}
    int ok1 = 1, ok2 = 1;
    for(int i = 1; i <= 4; i++){
    	if(a[i] != 0)ok1 = 0;
    	if(a[i] == 0)ok2 = 0;
    }
    if(ok1){
    	ans.push_back({1, 2});
    	ans.push_back({2, 3});
    	ans.push_back({1, 2});
    }else if(ok2){
    	ans.push_back({1, 4});
    }else if(a[4] != 0){
		ans.push_back({1, 3});
        ans.push_back({1, 2});
    }else if(a[1] != 0){
    	ans.push_back({2, 4});
    	ans.push_back({1, 2});
    }else{
    	ans.push_back({1, 2});
    	ans.push_back({2, 3});
    	ans.push_back({1, 2});
    }
    cout << ans.size() << '\n';
    for(auto [x, y] : ans){
    	cout << x << ' ' << y << '\n';
    }
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