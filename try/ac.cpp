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
	vector<int> lazy;
	int tot;
	AC(int n){
		tr = vector<vector<int>>(26, vector<int>(n + 1));
		fail.assign(n + 1, 0);
		cnt.assign(n + 1, 0);
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
	//返回字符串s匹配了几次
	int get_cnt(string s){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
		}
		return lazy[p];
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
	/*
	int query(string s){//相当于每次枚举了r然后去匹配这个后缀
		get_fail()
		int ans = 0;
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			while(temp && cnt[temp] != -1){
			//注意是否需要重复跑,重复跑复杂度最坏nm,传递tag,拓扑建图优化
			//注意cnt为0只是说明没有以这个为后缀的字符串还需要往上跑
				ans += cnt[temp];//匹配上
				cnt[temp] = -1;//匹配过不再走
				temp = fail[temp];
			}
		}
		return ans;
	}
	*/
	void run(string s){
		get_fail();
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			lazy[temp]++;//打上lazy tag
		}
		for(int i = tot; i >= 1; i--){
			lazy[fail[i]] += lazy[i];
		}
		return ;
	}
};
void solve(){
    
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