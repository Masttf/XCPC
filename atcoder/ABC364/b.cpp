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
    int nx, ny; cin >> nx >> ny;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    string s; cin >> s;
    for(auto c : s){
    	int tx = nx, ty = ny;;
    	if(c == 'L'){
    		ty--;
    	}else if(c == 'R'){
    		ty++;
    	}else if(c == 'U'){
    		tx--;
    	}else{
    		tx++;
    	}
    	if(tx >= 1 && tx <= n && ty >= 1 && ty <= m){
    		if(a[tx][ty] == '.'){
    			nx = tx, ny = ty;
    		}
    	}
    }
    cout << nx << ' ' << ny << '\n';
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