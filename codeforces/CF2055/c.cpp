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
    vector<int> s1(n + 1), s2(m + 1);
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
    		s1[i] += a[i][j];
    		s2[j] += a[i][j];
    	}
    }
    nx = 1, ny = 1;
    int sum = 0;
    if(s[1] == 'D'){
    	for(int i = 1; i <= m; i++){
    		sum += a[1][i];
    	}
    }else{
    	for(int i = 1; i <= n; i++){
    		sum += a[i][1];
    	}
    }
    a[1][1] = -sum;
    s1[1] += a[1][1];
    s2[1] += a[1][1];
    sum = 0;
    for(int i = 1; i < len; i++){
    	if(s[i] == 'D'){
    		nx++;
    	}else ny++;
    	if(get(nx, ny, n, ny) == 1){
    		a[nx][ny] = sum - s2[ny];
    	}else{
    		a[nx][ny] = sum - s1[nx];
    	}
    	s1[nx] += a[nx][ny];
    	s2[ny] += a[nx][ny];
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