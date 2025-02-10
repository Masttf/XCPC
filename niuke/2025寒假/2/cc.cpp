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
    vector<char> ans(n + 1, '#');
    auto get = [&]() -> int{
    	int res = 0;
	    vector<int> last(26);
	    for(int i = 1; i <= n; i++){
	    	int x = ans[i] - 'a';
	    	if(last[x]){
	    		if(n - i + 1 > 1) res = max(res, n - i + 1);
	    	}
	    	last[x] = i;
	    }
	    last.assign(26, 0);
	    for(int i = n; i >= 1; i--){
	    	int x = ans[i] - 'a';
	    	if(last[x]){
	    		if(i > 1) res = max(res, i);
	    	}
	    	last[x] = i;
	    }
	    return res;
    };
    auto pf = [&]() -> void{
    	for(int i = 1; i <= n; i++){
    		cout << ans[i];
    	}
    	cout << '\n';
    };
    for(int i = 0; i <= 25; i++){
    	for(int j = 0; j <= 25; j++){
    		if(i + j > n)continue;
    		char w = 'a';
    		for(int x = 1; x <= i; x++){
    			ans[x] = w;
    			w++;
    		}
    		for(int x = i + 1; x <= n - j; x++){
    			ans[x] = 'z';
    		}
    		w = 'a';
    		for(int x = n; x > n - j; x--){
    			ans[x] = w;
    			w++;
    		}
    		// pf();
    		// dbg(get());
    		if(get() == m){
    			cout << "YES\n";
    			pf();
    			return ;
    		}
    	}
    }
    cout << "NO\n";
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

aaaaaaa(m + 1)个

m = 3
aaaabbbb
aaababbb
m个长度
首字母和尾字母后面不再出现
一个字母出现两次就注定了
假设第一次出现位置是x 第二次出现位置是 y
aaaaa m个    后m个a
先从前往后考虑
x >= m + 1 y不存在
x <= m, m >= n - y + 1 ---> y >= n - m + 1

会不会出现 》= 3次？
x y z
y到开始要 <= m
y到结束也 <= m
x <= m 一定满足
z 到结束 <= m 也一定满足

*/