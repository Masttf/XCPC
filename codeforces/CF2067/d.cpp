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
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cnt(n + 1);
	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
	}
	int x = -1, y = -1;
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 0) x = i;
		else y = i;
	}
	auto query = [&](int x, int y) -> int{
		cout << "? " << x << ' ' << y << endl;
		int dis; cin >> dis;
		return dis;
	};
	if(x != -1){
		int dis1 = query(x, y);
		int dis2 = query(y, x);
		if(dis1 && dis2){
			cout << "! B" << endl;
		}else{
			cout << "! A" << endl;
		}
	}else{
		for(int i = 1; i <= n; i++){
			if(a[i] == 1)x = i;
			if(a[i] == n)y = i;
		}
		int dis1 = query(x, y);
		int dis2 = query(y, x);
		if(dis1 >= n - 1 && dis2 >= n - 1 && dis1 == dis2){
			cout << "! B" << endl;
		}else{
			cout << "! A" << endl;
		}
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
A 带环图
B 两个点可以达
x,y != y,x 那么肯定是A

两个不是排列 

*/