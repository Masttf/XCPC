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
    vector<pair<int, int>> ans;
    int last = 0;
    map<int, int> mp;
    vector<int> c;
    for(int i = 3; i <= n - 1; i++){
    	cout << "? " << 1 << ' ' << i << endl;
    	int res; cin >> res;
    	if(res == 0)c.push_back(i);
    	if(res <= last){
    		vector<int>temp;
    		int cnt = 0;
    		for(auto &[x, y] : mp){
    			if(cnt == last - res)break;
    			int id = -x;
    			cnt++;
    			y--;
    			if(y == 0)temp.push_back(x);
    			ans.push_back({id, i});
    		}
    		for(auto x : temp) mp.erase(x);
    		
    	}else{
    		mp[-(i - 1)] = res - last;
    	}
    	last = res;
    }
    for(auto [x, y] : mp){
    	ans.push_back({-x, n});
    }
    if(ans.size() != n - 3){
    	for(auto x : c){
    		ans.push_back({1, x});
    	}
    }
    
    cout << "! ";
    for(auto [x, y] : ans){
    	cout << x << ' ' << y << ' ';
    }
    cout << endl;
    int x; cin >> x;
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

*/