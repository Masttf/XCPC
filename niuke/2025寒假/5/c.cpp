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
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    string t; cin >> t;
    t = ' ' + t;
    for(int i = 1; i <= n; i++){
    	a[i] = t[i] - '0';
    }
    cin >> t;
    t = ' ' + t;
    for(int i = 1; i <= n; i++){
    	b[i] = t[i] - '0';
    }
    cin >> t;
    t = ' ' + t;
    for(int i = 1; i <= n; i++){
    	c[i] = t[i] - '0';
    }
    vector<int> cnt(4);
    // 00, 01, 10, 11
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	int d = a[i] ^ b[i];
    	if(d != c[i]){
    		int val = a[i] * 2 + b[i];
    		cnt[val]++;
    		sum++;
    	}
    }
    if(y >= 2 * x){
    	int ans = sum * x;
    	cout << ans << '\n';
    }else{
    	int mx = 0;
    	int ans = 0;
    	for(int i = 0; i < 4; i++){
    		mx = max(mx, cnt[i]);
    	}
    	if(mx > sum - mx){
    		ans = (sum - mx) * y + (2 * mx - sum) * x;
    	}else{
    		ans = (sum / 2 * y) + (sum % 2) * x;
    	}
    	//否则考虑交换 
    	// 00 01 10 11, 任意两个都可以交换
    	
    	cout << ans << '\n';
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
x的代价置反两个
y的代价交换两个， 交换一定是01交换
如果y的代价 >= 2 * x
还不如直接用操作1
如果c这位是

0说明
10 01 要变成11 或者00 如果已经是就不要动
为什么呢？ 因为上面换两次不优，要么是上下都换，最少代价是2 * y，
而正常消掉代价是2 * x
所以其实是三个区间
y >= 2 * x不如直接都用x

y >= x
y < x 的时候才考虑动已经对好的位

10 5 6
1010101010
0111010100
1010010110
01011
11100
01000
答案是17 也就是说
2次y 1次x

*/