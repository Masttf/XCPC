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
    int R = 1e5;
    vector<vector<int>> has(n + 1);
    vector<int> bl(R + 1);
    int id = 0;
    for(int i = 1; i <= n; i++){
    	int ty, x; cin >> ty >> x;
    	if(ty == 1){
    		id++;
            int flag = 1;
            // dbg(id);
    		for(int j = 1; j <= R; j++){
    			if(!x){
                    // dbg("R", j - 1);
                    break;
                }
    			if(bl[j]){
                    if(!flag){
                        // dbg("R", j - 1);
                        flag = 1;
                    }
                    continue;
                }
                if(flag){
                    // dbg("L", j);
                    flag = 0;
                }
    			x--;
    			bl[j] = id;
    			has[id].push_back(j);
    		}
    	}else if(ty == 2){
    		for(auto x : has[x]){
    			bl[x] = 0;
    		}
    	}else{
    		// dbg(i);
    		cout << bl[x] << '\n';
    	}
    }
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