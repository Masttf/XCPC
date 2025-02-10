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
constexpr int maxn = 1e6 + 5;
vector<int> prim;
bool vis[maxn];
void init(){
	vis[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!vis[i])prim.push_back(i);
		for(int j = 0; prim[j] * i < maxn; j++){
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0)break;
		}
	}
}
void solve(){
    int n; cin >> n;
    if(n <= 3){
    	cout << 0 << '\n';
    	return ;
    }
    if(n <= 5){
    	cout << 1 << '\n';
    	cout << "2 3 4\n";
    	return ;
    }
    int num = n / 3;
    cout << num << '\n';
    //这样一次生成两组
    if(num % 2 == 0){
    	for(int i = 1; i + 5 <= n; i += 6){
    		cout << i << ' ' << i + 1 << ' ' << i + 3 << '\n';
    		cout << i + 2 << ' ' << i + 4 << ' ' << i + 5 << '\n';
    	}
    }else{
    	cout << "1 2 4\n";
    	cout << "3 5 9\n";
    	cout << "6 7 8\n";
    	for(int i = 10 ; i + 5 <= n; i += 6){
    		cout << i << ' ' << i + 1 << ' ' << i + 4 << '\n';
    		cout << i + 2 << ' ' << i + 3 << ' ' << i + 5 << '\n';
    	}
    }
    
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
如果有一个质数

先筛质数？？？
恰有两对 要刚刚好

最多是 n / 3
相邻一定互质
1 2 4
第二个， 第三个一定偶所以不互质
3 5 6 //要么是3的倍数， 要么是偶数
每六个一组

7 8 10
8 11 12

13 14 16
15 17 18

那如果是奇数对呢？
也就是说要先搞掉一队
9个搞掉3对
1 2 3 4 5 6 7 8 9

1 2 4
3 5 9
6 7 8
然后再两对两对
10 11 12 13 14 15
10 11 14
12 13 15 // no 我应该凑出偶数对偶数，

这样第一行是偶数， 下面是3的倍数
16 17 20
18 19 21 
*/