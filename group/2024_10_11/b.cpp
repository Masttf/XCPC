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
    vector<int>res;
    for(int i = 2; i <= n; i++){
    	if(n % i == 0 && i * 2 <= n){
    		res.push_back(i);
    	}
    }
   	const int sz = res.size();
   	vector<int>ans;
   	vector<int> vis(sz);
   	for(int i = sz - 1; i >= 0; i--){
   		if(vis[i])continue;
   		ans.push_back(res[i]);
   		for(int j = i; j >= 0; j--){
   			if(res[i] % res[j] == 0)vis[j] = 1;
   		}
   	}
   	if(ans.empty())ans.push_back(1);
   	cout << ans.size() << '\n';
   	for(auto x :ans){
   		cout << 1 <<' ' << x << '\n';
   	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}