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
		cnt[p]++;//字符串结尾标记
	}
	int getIdx(string s){
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
	}
	void topu(string s){
		for(int i = 1; i <= tot; i++){
			du[fail[i]]++;
		}
		int p = 0;
		for(auto x : s){
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
		return ;
	}
};
void solve(){
    int n; cin >> n;
    if(n == 0)exit(0);
    vector<string> a(n + 1);
    int tot = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	tot += a[i].size();
    }
    string s; cin >> s;
    AC ac(tot);
    for(int i = 1; i <= n; i++){
    	ac.insert(a[i]);
    }
    ac.get_fail();
    ac.topu(s);
    int mx = 0;
    for(int i = 1; i <= n; i++){
    	int id = ac.getIdx(a[i]);
    	mx = max(mx, ac.lazy[id]);
    }
    cout << mx << '\n';
    for(int i = 1; i <= n; i++){
    	int id = ac.getIdx(a[i]);
    	if(ac.lazy[id] == mx){
    		cout << a[i] << '\n';
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(1)solve();
    return 0;
}