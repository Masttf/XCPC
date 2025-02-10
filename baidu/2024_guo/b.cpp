#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	string s; cin >> s;
	int n = s.size();
	vector<int>res;
	for(int i = n - 1; i >= 0; i--){
		res.push_back(s[i] - '0');
	}
	vector<int>t1 = {0,0,0,0};
	vector<int>t2 = {0, 0};
	for(int i = 0; i < n; i++){
		t1.push_back(res[i]);
		t2.push_back(res[i]);
	}
	// for(auto x : t1)cout << x;
	// cout << '\n';
	for(int i = 0; i < t1.size(); i++){
		if(i < res.size())t1[i] += res[i];
		if(i < t2.size())t1[i] += t2[i];
		//dbg(i, t1[i]);
		if(t1[i] / 2 > 0){
			if(i == t1.size() - 1){
				t1.push_back(t1[i] / 2);
			}else t1[i + 1] += t1[i] / 2;
		}
		t1[i] %= 2;
		//dbg(i, t1[i]);
	}
	reverse(t1.begin(), t1.end());
	for(auto x : t1)cout << x;
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}