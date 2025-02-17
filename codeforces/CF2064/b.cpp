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
	vector<int> b(n + 1);
	for(int i = 1; i <= n; i++){
		if(cnt[a[i]] == 1)b[i] = 1;
	}
	//区间尽可能大
	int mx = 0;
	int l = -1, r = -1;
	for(int i = 1; i <= n; i++){
		if(b[i] == 0)continue;
		int j = i;
		while(j <= n && b[j] == 1){
			j++;
		}
		if(j - i > mx){
			mx = j - i;
			l = i;
			r = j - 1;
		}
		i = j - 1;
	}
	if(l == -1)cout << 0 << '\n';
	else cout << l << ' ' << r << '\n';
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
长度 - 不同种类

值相同，长度越大越好
也就是说尽可能保留相同的数

*/