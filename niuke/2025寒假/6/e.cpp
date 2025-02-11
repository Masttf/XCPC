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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
    	int k; cin >> k;

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
/*
mx * mi
均匀随机生成
也就是说每个数个数应该很平均
还给3s
n^2做法
怎么在随机情况下变成nlog？
算法复杂度应该和随机有关
点对该怎么做
枚举l log算r？
或者说如何枚举 mx 和mi
每个数出现概率大概是 n / m
如果 m 很小咋做
m  < sqrt n

*/