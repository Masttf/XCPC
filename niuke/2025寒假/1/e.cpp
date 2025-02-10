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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int pos1 = -1, pos2 = -1;
    int N = n / 2;
    if(N % 2 == 1){
    	pos1 = a[N / 2 + 1];
    	pos2 = a[N + N / 2 + 1];
    }else{
    	pos1 = a[N / 2];
    	pos2 = a[N + N / 2 + 1];
    }
    auto get = [&](int x, int y) -> int{
    	int ans = 0;
    	for(int i = 1; i <= n; i++){
    		if(i <= N){
    			ans += abs(a[i] - x);
    		}else{
    			ans += abs(a[i] - y);
    		}
    	}
    	return ans;
    };
    if(pos1 == pos2){
    	int ans = min(get(pos1 - 1, pos2), get(pos1, pos2 + 1));
    	cout << ans << '\n';
    }else{
    	cout << get(pos1, pos2) << '\n';
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
/*
选两个指标
把前一半小的选个？
后一半小的选个？

选一个指标很简单
中位数

*/