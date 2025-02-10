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
    vector ans(n + 1, vector<int>(m + 1));
    if(m % 4 == 0){
    	int tot = 0;
		for(int j = 1; j <= m; j++){
			if(j % 4 == 1)tot++;
			ans[1][j] = tot;
		}
    	for(int i = 2; i <= n; i++){
    		for(int j = 1; j <= m; j++){
				ans[i][j] = ans[i - 1][j] + tot;
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
    	int tot = 0;
		for(int j = 1; j <= 1; j++){
    		for(int i = 1; i <= n; i++){
				if(i % 4 == 1)tot++;
				ans[i][j] = tot;
			}
    	}
    	for(int j = 2; j <= m; j++){
    		for(int i = 1; i <= n; i++){
				ans[i][j] = ans[i][j - 1] + tot;
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
    if(n % 4 == 2 && n >= 6){
    	int tot = 3;
		ans[1][1] = ans[2][1] = ans[3][1] = ans[1][2] = 1;
		ans[4][1] = ans[5][1] = ans[6][1] = ans[6][2] = 2;
		ans[2][2] = ans[3][2] = ans[4][2] = ans[5][2] = 3;
		for(int j = 1; j <= 2; j++){
			for(int i = 7; i <= n; i++){
				if(i % 4 == 3)tot++;
				ans[i][j] = tot;
			}
		}
		
		for(int j = 3; j <= m; j += 2){
			for(int i = 1; i <= n; i++){
				ans[i][j] = ans[i][j - 2] + tot;
				ans[i][j + 1] = ans[i][j - 1] + tot;
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
    if(m % 4 == 2 && m >= 6){
    	int tot = 3;
    	ans[1][1] = ans[1][2] = ans[1][3] = ans[2][1] = 1;
		ans[1][4] = ans[1][5] = ans[1][6] = ans[2][6] = 2;
		ans[2][2] = ans[2][3] = ans[2][4] = ans[2][5] = 3;
		for(int i = 1; i <= 2; i++){
			for(int j = 7; j <= m; j++){
				if(j % 4 == 3)tot++;
				ans[i][j] = tot;
			}
		}
		for(int i = 3; i <= n; i += 2){
			for(int j = 1; j <= m; j++){
				ans[i][j] = ans[i - 2][j] + tot;
				ans[i + 1][j] = ans[i - 1][j] + tot;
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
    int tot = 0;
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
    // assert(0);
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