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
    int x, y; cin >> x >> y;
    int xx = -1, yy = -1;
    vector<char>ans;
    if(x - 1 + y - 1 <= n - 1){
    	xx = 1;
    	yy = 1;
    }
    if(x - 1 + n - y <= n - 1){
    	xx = 1;
    	yy = n;
    }
    if(n - x + y - 1 <= n - 1){
    	xx = n;
    	yy = 1;
    }
    if(n - x + n - y <= n - 1){
    	xx = n;
    	yy = n;
    }
    assert(xx != -1);
    if(xx == 1){
    	for(int i = 1; i <= n - 1; i++){
    		ans.push_back('U');
    	}
    }else{
    	for(int i = 1; i <= n - 1; i++){
    		ans.push_back('D');
    	}
    }
    if(yy == 1){
    	for(int i = 1; i <= n - 1; i++){
    		ans.push_back('L');
    	}
    }else{
    	for(int i = 1; i <= n - 1; i++){
    		ans.push_back('R');
    	}
    }
    if(xx < x){
    	for(int i = 1; i <= x - xx; i++){
    		ans.push_back('D');
    	}
    }else{
    	for(int i = 1; i <= xx - x; i++){
    		ans.push_back('U');
    	}
    }
    if(yy < y){
    	for(int i = 1; i <= y - yy; i++){
    		ans.push_back('R');
    	}
    }else{
    	for(int i = 1; i <= yy - y; i++){
    		ans.push_back('L');
    	}
    }
   	for(auto x : ans){
   		cout << x;
   	}
   	cout << '\n';
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