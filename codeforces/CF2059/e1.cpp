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
    vector a(n + 1, vector<int>(m + 1));
    vector b(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> b[i][j];
    	}
    }
    int ans = n * m;

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
/*
2e5 
可以展开成一维
也就是说每次可以在
1， m + 1， 2 * m + 1，...这些位置插入一个数
然后把其他的整体后移
也就说对于同一行应该倒着考虑

显然应该先把第一行对准
否则改变会影响下面

dp ？
dp i 表示前i行排好的最小代价
*/