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
    if(m >= 2 * n){
    	cout << "No\n";
    	return ;
    }
    cout << "Yes\n";
    vector a(2 * n + 1, vector<int>(2 * n + 1));
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
    		a[i][j] = j;
    	}
		for(int j = 1; j <= n; j++){
    		a[i][j + n] = i;
    	}
    	
    }
    for(int i = n + 1; i <= 2 * n; i++){
		for(int j = 1; j <= n; j++){
    		a[i][j] = i - n;
    	}
        int now = i - n;
		for(int j = n; j >= 1; j--){
            now %= n;
    		a[i][j + n] = now;
            if(now == 0)a[i][j + n] = n;
            now++;
    	}
    }
    for(int i = 1; i <= 2 * n; i++){
    	for(int j = 1; j <= m; j++){
    		cout << a[i][j] << ' ';
    	}
    	cout << '\n';
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