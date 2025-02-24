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
constexpr int N = 1e5 + 5;

struct AC{
		vector<vector<int>> tr;
		vector<int> fail;
		vector<int> cnt;
		vector<int> vis;
		vector<int> tag;
		int tot;
		AC(int n){
			tr = vector<vector<int>>(26, vector<int>(n + 1));
			fail.resize(n + 1, 0);
			cnt.resize(n + 1, 0);
			vis.resize(n + 1, 0);
			tag.resize(n + 1, 0);
			tot = 0;
		}
		void insert(string s, int id){
			int p = 0;
			for(auto x : s){
				int ch = x - 'a';
				if(!tr[ch][p])tr[ch][p] = ++tot;
				p = tr[ch][p];
			}
			if(cnt[p]){
					tag[id] = cnt[p];
			}else cnt[p] = id;//字符串结尾标记
			
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
		int query(string s){//相当于每次枚举了r然后去匹配这个后缀
			int ans = 0;
			int p = 0;
			for(auto x : s){
				int ch = x - 'a';
				p = tr[ch][p];
				int temp = p;
				while(temp && cnt[temp] != -1){
				//注意cnt为0只是说明没有以这个为后缀的字符串还需要往上跑
					//ans += cnt[temp];//匹配上
					vis[cnt[temp]] = 1;
					cnt[temp] = -1;//匹配过不再走
					temp = fail[temp];
				}
			}
			return ans;
		}
};
void solve(){
		int n; cin >> n;
		string a; cin >> a;
		string c; cin >> c;
		c = ' ' + c;
		int lenc = c.size() - 1;
		vector<int>nt(lenc + 1);
		nt[1] = 0;
		for(int i = 2, j = 0; i <= lenc; i++){
			while(j && c[i] != c[j + 1])j = nt[j];
			if(c[i] == c[j + 1]){
				j++;
			}
			nt[i] = j;
		}
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
		vector<int>Ans(n + 1, 1);
		AC ac(N);
		for(int i = 1; i <= n; i++){
			string s;
			string x;
			cin >> x >> s;
			s = ' ' + s;
			Ans[i] = check2(s);
			if(Ans[i]){
				ac.insert(x, i);
			}
		}
		ac.get_fail();
		ac.query(a);
		vector<int> ans;
		for(int i = 1; i <= n; i++){
			if(Ans[i]&&(ac.vis[i] || (ac.tag[i] && ac.vis[ac.tag[i]])))ans.push_back(i);
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