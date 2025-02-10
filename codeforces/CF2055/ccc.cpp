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
    string s; cin >> s;
    s = ' ' + s;
    int len = n + m - 1;
    vector a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    	}
    }
    vector s1(n + 1, vector<int>(2)), s2(m + 1,vector<int>(2));
    vector pre(n + 1, vector<int>(m + 1));
    int nx = 1, ny = 1;
    pre[1][1]++;
    for(int i = 1; i < len; i++){
    	if(s[i] == 'D'){
    		nx++;
    	}else ny++;
    	pre[nx][ny]++;
    }
    for(int i = 1; i <= n; i++){
    	for(int j =1 ; j <= m; j++){
    		pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    	}
    }
    auto get = [&](int x1, int y1, int x2, int y2) -> int{
    	return pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
    };
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		s1[i][0] += a[i][j];
    		s2[j][0] += a[i][j];
    	}
    }
    nx = 1, ny = 1;
    vector<int> sum(2);
    if(s[1] == 'D'){
    	for(int i = 1; i <= m; i++){
    		sum[0] += a[1][i];
    	}
    }else{
    	for(int i = 1; i <= n; i++){
    		sum[0] += a[i][1];
    	}
    }
    sum[1] = 1;
    vector val(len + 1, vector<int>(2));
    for(int i = 1; i < len; i++){
    	if(s[i] == 'D'){
    		nx++;
    	}else ny++;
    	if(get(nx, ny, n, ny) == 1){
    		for(int k = 0; k < 2; k++){
    			val[i + 1][k] = sum[k] - s2[ny][k];
    		}
    	}else{
    		for(int k = 0; k < 2; k++){
    			val[i + 1][k] = sum[k] - s1[nx][k];
    		}
    	}
    	for(int k = 0; k < 2; k++){
    		s1[nx][k] += val[i + 1][k];
    		s2[ny][k] += val[i + 1][k];
		}
    }
    int dx = s2[m][1] - s1[n][1];
    int d2 = s2[m][0] - s1[n][0];
    // dbg(dx, d2);
    if(d2 == 0){
    	a[1][1] = 0;
    }else{
    	a[1][1] = d2 / dx;
    }
    vector<int> S1(n + 1), S2(m + 1);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
            // cout << a[i][j] << ' ';
    		S1[i] += a[i][j];
    		S2[j] += a[i][j];
    	}
        // cout << '\n';
    }
    // cout << endl;
    nx = 1, ny = 1;
    int SUM = 0;

    if(s[1] == 'D'){
    	for(int i = 1; i <= m; i++){
    		SUM += a[1][i];
    	}
    }else{
    	for(int i = 1; i <= n; i++){
    		SUM += a[i][1];
    	}
    }
    for(int i = 1; i < len; i++){
    	if(s[i] == 'D'){
    		nx++;
    	}else ny++;
        // dbg(S1[nx], S2[ny]);
    	if(get(nx, ny, n, ny) == 1){
            // dbg(nx, ny, S2[ny]);
    		a[nx][ny] = SUM - S2[ny];
    	}else{
    		a[nx][ny] = SUM - S1[nx];
    	}
    	S1[nx] += a[nx][ny];
    	S2[ny] += a[nx][ny];
        // dbg(nx, ny);
        // dbg(S1[nx], S2[ny]);
    }
    for(int i = 1; i <= n; i++){
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