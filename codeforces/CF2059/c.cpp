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
    vector a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cin >> a[i][j];
    	}
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++){
    	int cnt = 0;
    	for(int j = n; j >= 1; j--){
    		if(a[i][j] == 1)cnt++;
    		else break;
    	}
    	q.push(cnt);
    }
    int ans = 0;
    int now = 0;
    while(!q.empty()){
    	while(!q.empty() && q.top() < now){
    		q.pop();
    	}
    	if(q.empty())break;
    	ans++;
    	now++;
    	q.pop();
    }
    cout << ans << '\n';
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
mex 尽可能大
n^2 log 可以过
每一时候先增加人再清除
一定会清空一个队列

那么 mex 最大就是 n + 1， 最小是1（因为最后一次清空）

可以二分这个mex
也就是说倒着来
...
是只会保留倒数一个数
倒数两个数
倒数三个数
但是aij >= 1
也就是说保留一个数的 一定要是1
也就是
后缀要都是1才行


*/