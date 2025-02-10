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
	int n; cin >> n;
	string a; cin >> a;
	string c; cin >> c;
	a = ' ' + a;
	c = ' ' + c;
	int lena = a.size() - 1;
	int lenc = c.size() - 1;
	vector<int>p(lena + 1);
	vector<int>f(lena + 1);
	p[0] = f[0] = 1;
	for(int i = 1; i <= lena; i++){
		p[i] = p[i - 1] * 131;
		f[i] = f[i - 1] * 131 + a[i] - 'a'; 
	}
	auto get_hash_a = [&](int l, int r) -> int{
		return f[r] - f[l - 1] * p[r - l + 1];
	};
	vector<int>nt(lenc + 1);
	nt[1] = 0;
	for(int i = 2, j = 0; i <= n; i++){
		while(j && c[i] != c[j + 1])j = nt[j];
		if(c[i] == c[j + 1]){
			j++;
		}
		nt[i] = j;
	}
	//dbg("yes");
	auto check2 = [&](string &x) -> bool{
		int len = x.size() - 1;
		for(int i = 1, j = 0; i <= len; i++){
			while(j && x[i] != c[j + 1])j = nt[j];
			if(x[i] == c[j + 1]){
				j++;
			}
			if(j == lenc)return true;
		}
		return false;
	};
	vector<string> q1(n + 1);
	vector<string> q2(n + 1);
	vector<int>cnt(lena + 1);
	for(int i = 1; i <= n; i++){
		cin >> q1[i] >> q2[i];
		q1[i] = ' '+ q1[i];
		q2[i] = ' '+ q2[i];
		int len = q1[i].size() - 1;
		if(len <= lena){
			cnt[len]++;
		}
	}
	int tot = 0;
	vector<int>pos(lena + 1);
	for(int i = 1; i <= lena; i++){
		if(cnt[i]){
			pos[i] = ++tot;
		}
	}
	vector<unordered_map<int, int>>res(tot + 1);
	for(int i = 1; i <= lena; i++){
		if(pos[i]){
			for(int j = 1; j + i -1 <= lena; j++){
				res[pos[i]][get_hash_a(j, j + i -1)]++;
				//dbg(i, j, j + i -1, get_hash_a(j, j + i -1));
			}
		}
	}
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		int ok1 = 1;
		int ok2 = 1;
		ok2 = check2(q2[i]);
		int len = q1[i].size() - 1;
		if(len > lena)ok1 = 0;
		else{
			int hash = 0;
			for(int j = 1; j <= len; j++){
				hash = hash * 131 + q1[i][j] - 'a'; 
			}
			//dbg(i,hash);
			if(!res[pos[len]].count(hash))ok1 = 0;
		}
		//dbg(i, ok1, ok2);
		if(ok1 && ok2){
			ans.push_back(i);
		}
	}
	if(ans.empty()){
		cout<<'\n';
	}else{
		int sz = ans.size() - 1;
		for(int i = 0; i <= sz; i++){
			cout << ans[i] << " \n"[i==sz];
		}
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