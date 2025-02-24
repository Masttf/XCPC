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
	std::string s;
	std::cin >> s;
	std::vector<std::string> ans = {""};
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '/' or s[i] == ':') ans.push_back("");
		else ans.back() += s[i];
	}
	int f = 0;
	for(auto &i:ans) {
		if(!i.empty() and f < 2) std::cout << i << '\n', ++f;
		int num = std::count(i.begin(), i.end(), '=');
		int num1 = std::count(i.begin(), i.end(), '-');
		if(!i.empty() and num == 1 and i.front() != '=' and i.back() != '=' and num1 == 0) std::cout << i << '\n';
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