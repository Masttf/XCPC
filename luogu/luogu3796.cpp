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
struct AC{
	vector<vector<int>> tr;
	vector<int> fail;
	vector<int> cnt;
	vector<int> ans;
	int tot;
	AC(int n){
		tr = vector<vector<int>>(26, vector<int>(n + 1));
		fail.resize(n + 1, 0);
		cnt.resize(n + 1, 0);
		ans.resize(n + 1, 0);
		tot = 0;
	}
	void insert(string s, int id){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			if(!tr[ch][p])tr[ch][p] = ++tot;
			p = tr[ch][p];
		}
		cnt[p] = id;//字符串结尾标记
	}
	void get_fail(){
		queue<int>q;
		for(int i = 0; i <26; i++){
			if(tr[i][0])q.push(tr[i][0]);
		}
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int i = 0; i < 26; i++){
				if(tr[i][now]){
					fail[tr[i][now]] = tr[i][fail[now]];//连向上一层的
					q.push(tr[i][now]);
				}else{
					tr[i][now] = tr[i][fail[now]];
				}
				
			}
		}
	}
	int query(string s){
		int res = 0;
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			while(temp){
				ans[cnt[temp]]++;
				if(cnt[temp])res = max(res, ans[cnt[temp]]);
				temp = fail[temp];
			}
		}
		return res;
	}
};
constexpr int maxn = 1e6 + 5;
void solve(){
	int n; 
	while(cin >> n){
		if(!n)break;
		int mx = n * 100;
		AC ac(mx);
		vector<string>a(n + 1);
		for(int i = 1; i <=n; i++){
			cin >> a[i];
			ac.insert(a[i], i);
		}
		ac.get_fail();
		string t; cin >> t;
		int res = ac.query(t);
		cout << res << '\n';
		for(int i = 1; i <= n; i++){
			if(ac.ans[i] == res)cout << a[i] << '\n';
		}
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