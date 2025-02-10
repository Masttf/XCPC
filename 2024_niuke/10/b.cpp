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
	int n, q;cin >> n >> q;
	map<string, int>m;
	vector<string> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = ' ' + a[i];
		string x; cin >> x;
		if(x.back() == ';')x.pop_back();
		m[x] = i;
	}
	vector<string>res;
	auto get = [&]() -> void{
		string s = res[0];
		int t = m[res[0]];
		//dbg(t);
		int sz = res.size();
		if(sz == 1){
			for(int i = 1; i < a[t].size(); i++){
				cout << a[t][i];
			}
			cout << '\n';
			return ;
		}
		vector<int>stk;
		stk.push_back(4);
		int siz = a[t].size();
		int tot = 0;
		vector tr(2, vector<int>(siz + 1));
		vector<int>r(siz + 1);
		for(int i = 1; i < siz; i++){
			if(a[t][i] == '<'){
				stk.push_back(i);
			}
			if(a[t][i] == '>'){
				int top = stk.back();
				stk.pop_back();
				//dbg(top);
				top -= 4;
				r[top] = i;
				int fa = stk.back();
				fa -= 4;
				if(tr[0][fa] == 0){
					tr[0][fa] = top;
					//dbg("l",fa, top);
				}else{
					tr[1][fa] = top;
					//dbg("r",fa, top);
				}
			}
			if(a[t][i] == 'd'){
				r[i] = i + 5;
				int fa = stk.back();
				fa -= 4;
				if(tr[0][fa] == 0){
					tr[0][fa] = i;
				}else{
					tr[1][fa] = i;
				}
			}
			if(a[t][i] == 'i' && a[t][i + 1] == 'n'){
				r[i] = i + 2;
				int fa = stk.back();
				fa -= 4;
				if(tr[0][fa] == 0){
					tr[0][fa] = i;
				}else{
					tr[1][fa] = i;
				}
			}
		}
		int p = 1;
		for(int i = 1; i < sz; i++){
			if(res[i][0] == 'f'){
				p = tr[0][p];
			}else{
				p = tr[1][p];
			}
		}
		for(int i = p; i <= r[p]; i++){
			cout << a[t][i];
		}
		cout << '\n';
	};
	for(int i = 1; i <= q; i++){
		string s; cin >> s;
		string temp = "";
		res.clear();
		for(auto x : s){
			if(x == '.'){
				res.push_back(temp);
				temp = "";
			}else temp += x;
		}
		res.push_back(temp);
		get();
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}