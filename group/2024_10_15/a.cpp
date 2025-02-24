#include<bits/stdc++.h>
// #define int long long
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
constexpr int maxn = 3e7 + 5;
int vis[maxn];
int tr[26][maxn];
int fail[maxn];
int cnt[maxn];
struct AC{
	int tot;
	AC(int n){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 26; j++){
				tr[j][i] = 0;
			}
		}
		for(int i = 0; i <= n; i++){
			fail[i] = 0;
			cnt[i] = 0;
		}
		tot = 0;
	}
	void init(int n){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 26; j++){
				tr[j][i] = 0;
			}
		}
		for(int i = 0; i <= n; i++){
			fail[i] = 0;
			cnt[i] = 0;
		}
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
		cnt[p] = s.size();//字符串结尾标记
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
		int ans = s.size();
		int p = 0;
		int now = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			while(temp){
			//注意是否需要重复跑,重复跑复杂度最坏nm,传递tag,拓扑建图优化
			//注意cnt为0只是说明没有以这个为后缀的字符串还需要往上跑
				// ans += cnt[temp];//匹配上
				// cnt[temp] = -1;//匹配过不再走
				if(cnt[temp]){
					vis[now + 1]--;
					vis[now - cnt[temp] + 1]++;
					break;
				}
				temp = fail[temp];
			}
			now++;
		}
		return ans;
	}
};
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    int len = 0;
    int mx = 3e7;
    AC ac(mx);
    for(int i = 1; i <= m; i++){
    	string S; cin >> S;
    	ac.insert(S);
    }
    ac.get_fail();
    ac.query(s);
    int ans = s.size();
    for(int i = 0; i < s.size(); i++){
		if(i)vis[i] += vis[i - 1];
		if(vis[i])ans--;
	}
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}