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
struct AC{
	vector<vector<int>> tr;
	vector<int> fail;
	vector<int> cnt;
	vector<int> du;
	vector<int> lazy;
	int tot;
	AC(int n){
		tr = vector<vector<int>>(26, vector<int>(n + 1));
		fail.assign(n + 1, 0);
		cnt.assign(n + 1, 0);
		du.assign(n + 1, 0);
		lazy.assign(n + 1, 0);
		tot = 0;
	}
	void insert(string s){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			if(!tr[ch][p])tr[ch][p] = ++tot;
			p = tr[ch][p];
		}
		//注意模式串是否重复
		cnt[p] = 1;//字符串结尾标记
	}
	int get(string s){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
		}
		return p;
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
		for(int i = 1; i <= tot; i++){
			du[fail[i]]++;
		}
	}
	int query(string s){//相当于每次枚举了r然后去匹配这个后缀
		int ans = 0;
		int p = 0;
		for(auto x : s){
			// dbg(x);
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			lazy[temp]++;
		}
		queue<int> q;
		for(int i = 1; i <= tot; i++){
			if(!du[i])q.push(i);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			int v = fail[u];
			du[v]--;
			lazy[v] += lazy[u];
			if(!du[v])q.push(v);
		}
		return ans;
	}
};
void solve(){
    string s; cin >> s;
    int q; cin >> q;
    vector<string> a(q + 1);
    int tot = 0;
    for(int i = 1; i <= q; i++){
    	cin >> a[i];
    	tot += a[i].size();
    }
    AC ac(tot);
    for(int i = 1; i <= q; i++){
    	ac.insert(a[i]);
    }
    ac.get_fail();
    ac.query(s);
    for(int i = 1; i <= q; i++){
    	int id = ac.get(a[i]);
    	cout << ac.lazy[id] << '\n';
    }
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