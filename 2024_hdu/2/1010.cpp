#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	string s;cin >> s;
	vector<char>allc;
	for (int i = 0;i < 8;i+=2) {
		allc.push_back(s[i]);
	}
	vector<char>allc1;
	for (int i = 0;i < 4;i+=2) {
		allc1.push_back(allc[i]);
	}
	//cout << allc1[0] << ' ' << allc1[1] << '\n';
	if (allc1[0] == allc1[1]) {
		cout << allc1[0] << '\n';	
	}
	else {
		int cnt1 = 0,cnt2 = 0;
		for (int i = 0;i < 8;i++) {
			if (s[i] == allc1[0]) cnt1++;
			if (s[i] == allc1[1]) cnt2++;
		}
		if (cnt1 > cnt2) {
			cout << allc1[0] << '\n';
		}
		else if (cnt1 < cnt2) {
			cout << allc1[1] << '\n';
		}
		else cout << "N" << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}