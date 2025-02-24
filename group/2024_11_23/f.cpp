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

int p[26];
set<int> num;
vector<string> ans;
string s;
int n;
void get(int r) {
	num.clear();
	memset(p, -1, sizeof(p));

	for(int i = r; i >= 1; --i) {
		if(p[s[i] - 'a'] == -1) p[s[i] - 'a'] = num.size();
		num.insert(s[i] - 'a');
		if(num.size() == 26) break;
	}

	string tmp;
	for(int i = 1; i <= r; ++i) {
		tmp += 'a' + p[s[i] - 'a'];
	}
	ans.push_back(tmp);
}
void solve(){
	
	cin >> n;

	cin >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; ++i) get(i);
	cout << *max_element(ans.begin(), ans.end()) << '\n';

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