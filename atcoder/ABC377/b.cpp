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
    vector<string> a(8);
    for(int i = 0; i < 8; i++){
    	cin >> a[i];
    }
    int ans = 0;
    vector<int> col(8), row(8);
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
    		if(a[i][j] == '#'){
    			col[i] = 1;
    			row[j] = 1;
    		}
    	}
    }
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
    		if(a[i][j] == '.'){
    			if(!col[i] && !row[j])ans++;
    		}
    	}
    }
    cout << ans << '\n';
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