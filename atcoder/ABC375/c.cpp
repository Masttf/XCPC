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
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    auto Z = [&](int x) -> void{
    	swap(a[x][x], a[x][n - x + 1]);
    	swap(a[x][x], a[n - x + 1][n - x + 1]);
    	swap(a[x][x], a[n - x + 1][x]);
    	for(int i = x + 1; i <= n - x; i++){
    		swap(a[x][i], a[i][n - x + 1]);
    		swap(a[x][i], a[n - x + 1][n - i + 1]);
    		swap(a[x][i], a[n - i + 1][x]);
    	}
    };
    int now = 1;
    for(int i = 1; i <= n / 2; i++){
    	for(int j = 1; j <= now; j++){
    		Z(i);
    	}
    	now++;
    	now %= 4;
    	// dbg(i);
    	// for(int k = 1; k <= n; k++){
	    // 	for(int j = 1; j <= n; j++){
	    // 		cout << a[k][j];
	    // 	}
	    // 	cout << '\n';
	    // }
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cout << a[i][j];
    	}
    	cout << '\n';
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