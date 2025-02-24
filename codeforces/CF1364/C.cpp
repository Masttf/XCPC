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
    vector<int> b(n + 1, -1);
	set<int> s;
	for(int i = 0; i <= 2 * n; i++){
		s.insert(i);
	}
	for(int i = 1; i <= n; i++){
		if(s.count(a[i]))s.erase(a[i]);
	}
	for(int i = 1; i <= n; i++){
		b[i] = *s.begin();
		s.erase(s.begin());
		if(i == n || a[i] != a[i + 1]){
			s.insert(a[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << b[i] << " \n"[i == n];
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
a 单调不减
最大情况
1 2 3 4 5 6 
0 1 2 3 4 5


*/