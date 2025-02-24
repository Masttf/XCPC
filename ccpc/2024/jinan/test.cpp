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
    map<string, int>mp;
    vector a(n + 1, vector<string>(m + 1));
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	for(int j = 1; j <= m; j++){
    		string temp = "";
    		for(int p = (j - 1) * k; p < j * k; p++){
    			temp = temp + s[p];
    		}
    		a[i][j] = temp;
    		mp[temp]++;
    	}
    }
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(mp[a[i][j]] == 1){
    			cout << i << ' ' << j << '\n';
    			return ; 
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