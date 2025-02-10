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
    if(n * m % 4 != 0){
    	cout << "NO\n";
    	return ;
    }
    if(n == 2 && m == 2){
    	cout << "NO\n";
    	return ;
    }
    cout << "YES\n";
    vector ans(n + 1, vector<int>(m + 1, 0));
    int tot = 0;
    if(m == 2){
    	for(int j = 1; j <= m; j++){
			for(int i = 1; i <= n; i++){
				if(i % 4 == 1)tot++;
				ans[i][j] = tot;
			}
		}
		for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cout << ans[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	return ;
    }
    if(n == 2){
    	for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j % 4 == 1)tot++;
				ans[i][j] = tot;
			}
		}
		for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cout << ans[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	return ;
    }
    if(n % 4 == 0){
    	if(m % 4 == 0){
    		for(int j = 1; j <= m; j++){
    			for(int i = 1; i <= n; i++){
    				if(i % 4 == 1)tot++;
    				ans[i][j] = tot;
    			}
    		}
    	}else{
    		tot = 3;
    		ans[1][1] = ans[1][2] = ans[1][3] = ans[2][1] = 1;
    		ans[1][4] = ans[1][5] = ans[1][6] = ans[2][6] = 2;
    		ans[2][2] = ans[2][3] = ans[2][4] = ans[2][5] = 3;
    		for(int i = 3; i <= n; i += 2){
    			tot += 3;
    			for(int j = 1; j <= 6; j++){
    				ans[i][j] = ans[i - 2][j] + 3;
    				ans[i + 1][j] = ans[i - 1][3] + 3;
    			}
    		}
    		for(int j = 7; j <= m; j++){
    			for(int i = 1; i <= n; i++){
    				if(i % 4 == 1)tot++;
    				ans[i][j] = tot;
    			}
    		}
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cout << ans[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	return ;
    }
    if(m % 4 == 0){
    	if(n % 4 == 0){
    		for(int i = 1; i <= n; i++){
    			for(int j = 1; j <= m; j++){
    				if(j % 4 == 1)tot++;
    				ans[i][j] = tot;
    			}
    		}
    	}else{
    		tot = 3;
    		ans[1][1] = ans[2][1] = ans[3][1] = ans[1][2] = 1;
    		ans[4][1] = ans[5][1] = ans[6][1] = ans[6][2] = 2;
    		ans[2][2] = ans[3][2] = ans[4][2] = ans[5][2] = 3;
    		for(int i = 3; i <= m; i += 2){
    			tot += 3;
    			for(int j = 1; j <= 6; j++){
    				ans[j][i] = ans[j][i - 2] + 3;
    				ans[j][i + 1] = ans[j][i - 1] + 3;
    			}
    		}
    		for(int i = 7; i <= n; i++){
    			for(int j = 1; j <= m; j++){
    				if(j % 4 == 1)tot++;
    				ans[i][j] = tot;
    			}
    		}
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cout << ans[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	return ;
    }
	ans[1][1] = ans[1][2] = ans[1][3] = ans[2][1] = 1;
	ans[1][4] = ans[1][5] = ans[1][6] = ans[2][6] = 2;
	ans[2][2] = ans[2][3] = ans[2][4] = ans[2][5] = 3;
	for(int j = 7; j <= m; j += 6){
		ans[1][j] = ans[1][j - 6] + 3;
		ans[2][j] = ans[2][j - 6] + 3;
	}
	for(int i = 3; i <= n; i += 2){
		for(int j = 1; j <= m; j++){
			ans[i][j] = ans[i - 2][j] + 3;
			ans[i + 1][j] = ans[i - 1][3] + 3;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << ans[i][j] << ' ';
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