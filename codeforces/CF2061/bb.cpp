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
    sort(a.begin() + 1, a.end());
	int pos = -1;
	for(int i = n - 1; i >= 1; i--){
		if(a[i] == a[i + 1]){
			pos = i;
			break;
		}
	}
	if(pos == -1){
		cout << -1 << '\n';
		return ;
	}
	vector<int> b;
	for(int i = 1; i <= n; i++){
		if(i == pos || i == pos + 1)continue;
		b.push_back(a[i]);
	}
	int len = b.size();
	for(int i = 0; i < len - 1; i++){
		if(b[i] + a[pos] * 2 > b[i + 1]){
			cout << b[i] << ' ' << a[pos] << ' ' << a[pos] << ' ' << b[i + 1] << '\n';
			return ;
		}
	}
	cout << -1 << '\n';
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