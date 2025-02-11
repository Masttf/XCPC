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
struct node{
	int l, r;
	int cnt = 0;
};
void solve(){
    int n, m; cin >> n >> m;
    vector<int> ans(n + 1);
    vector<array<int, 3>> limit(m + 1);
    for(int i = 1; i <= m; i++){
    	int l, r, c; cin >> l >> r >> c;
    	limit[i] = {l, r, c};
    }
    for(int i = 1; i <= n; i++){
		ans[i] = n - i + 1;
	}
    int d = limit[1][1] - limit[1][0] + 1;
    if(d % 2 == 1){
		
		for(int i = 1; i <= n; i += 2){
			if(i + 1 <= n){
				swap(ans[i], ans[i + 1]);
			}
		}
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << ' ';
    }
    cout << '\n';
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
保证 l 和 r 同奇偶说明区间长度是奇数
那么如果是 n .... 1这样的填法
会有中间的数不改变位置
那么该如何调整？

4 3 2 1
4 2 3 1

3 2 1
2 3 1

假设每次询问， 我都swap如果有mid， 我就swap中间两个然后跑check？

可以吗
应该没有无解情况

5 4 3 2 1
4 5 2 3 1
2 4 5
  2 3 5
    1 2 3
1 2 3 4 5
交换两个两个是否可行
7 6 5 4 3 2 1
6 7 4 5 2 3 1
4 6 7
  4 5 7
    2 4 5
      2 3 5
        1 2 3

6 5 4 3 2 1
5 6 3 4 1 2
3 5 6
  3 4 6
    1 3 4
      1 2 4
1 3 4 5 6
  1 2 3 4 6
*/