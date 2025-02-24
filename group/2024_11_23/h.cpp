#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

int tt;

void solve(){
	int n;cin >> n;
	string s;cin >> s;
	//tt++;
	//if (tt == 92) cout << s << '\n';
	vector <char> a(n + 1);
	for (int i = 1;i <= n;i++) a[i] = s[i - 1];
	if (a[n - 1] == '0' && a[n] == '0') {
		cout << "Yes" << '\n';
		return ;
	}
	int cnt1 = 0,cnt0 = 0,lst = -1;
	for (int i = 1;i <= n - 2;i++) {
		//dbg(i,a[i]);
		if (a[i] == '0') {
			if (cnt1 >= cnt0 + 1) {
				cnt0++;
				if (cnt1 == cnt0) continue;
				lst = i;
			}
			else cnt1 = 0,cnt0 = 0;
		}
		else {
			lst = i;
			cnt1++;
		}
		//dbg(i,cnt1);
		if (lst == n - 2 && cnt1 >= 2) {
			cout << "Yes" << '\n';
			return ;
		} 
		if (lst == n - 3) {
			if (a[n] == '1' && a[n - 1] == '0') continue;
			else cout << "Yes" << '\n';
			return ;
		}
	}
	cout << "No" << '\n';
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