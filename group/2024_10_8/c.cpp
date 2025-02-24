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
    int n, m, k; cin >> n >> m >> k;
    vector<int>a(m + 1);
    for(int i = 1; i <= m; i++) cin >> a[i];
    vector<int>vis(n + 1);
	vector<int> pos(n + 1);
    for(int i = 1; i <= k; i++){
    	int x; cin >> x;
    	int y; cin >> y;
    	vis[x] = y;
    	pos[y] = x;
    }
    if(vis[1]){
    	cout << vis[1] << '\n';
    }else{
    	int ok = 0;
    	for(int i = 1; i <= m; i++){
    		if(a[i] == 1)ok = 1;
    	}
    	if(ok){
    		int l = 1;
    		for(int i = 1; i <= m; i++){
    			if(vis[a[i]])l = vis[a[i]] + 1;
    			else{
    				while(pos[l])l++;
    				pos[l] = a[i];
    				vis[a[i]] = l++;
    			}
    		}
    		cout << vis[1] << '\n';
    	}else{
    		int r = n;
    		for(int i = m; i >= 1; i--){
    			if(vis[a[i]]) r = vis[a[i]] - 1;
    			else{
    				while(pos[r])r--;
    				pos[r--] = a[i];
    			}
    		}
    		for(int i = 1; i <= n; i++){
    			if(!pos[i]){
    				cout << i << '\n';
    				return ;
    			}
    		}
    	}
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