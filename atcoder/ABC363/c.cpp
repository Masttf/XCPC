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
struct Manacher{
	string res;
	vector<int> p;
	Manacher(string s){
		res = "^";
		for(auto x : s){
			res += '#';
			res += x;
		}
		res += "#&";
		p.resize(res.size() + 1);
		run();
		// s = abc idx 0 1 2
		// res = ^#a#b#c#& idx 2 4 6
		// s_idx -> res_idx * 2 + 2
	}
	void run(){
		int len = res.size();
		int c = 0, r = 0;
		for(int i = 1; i < len; i++){
			if(i <= r){
				p[i] = min(p[2 * c - i], r - i);
			}
			while(res[i - p[i] - 1] == res[i + p[i] + 1])p[i]++;
			if(i + p[i] > r){
				c = i;
				r = i + p[i];
			}
		}
		return ;
	}
	pair<int, int> get(){
		int start = max_element(p.begin(), p.end()) - p.begin();
		int max_len = p[start];
		return {start, max_len};
		// (i - p[i]) / 2是回文起始点,字符串下标从0开始
		// s_li = (i - p[i] + 1) / 2 - 1
		// s_ri = (i + p[i]) / 2 - 1
	}
	bool check(int l, int r){
		int len = (r - l + 1);
		int center = (l + r) / 2;
		center = center * 2 + 2;
		if(len % 2 == 0)center++;
		return p[center] >= len;
	}
};
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) a[i] = i;
   	unordered_set<string> ans;
    do{
    	int ok = 1;
    	for(int i = 1; i + k <= n + 1; i++){
    		int flag = 1;
    		for(int j = 1; j <= k; j++){
    			if(s[a[i + j - 1]] != s[a[i + k - j]])flag = 0;
    		}
    		if(flag){
    			ok = 0;
    		}
    	}
    	if(ok){
    		string t = "";
    		for(int i = 1; i <= n; i++){
    			t += s[a[i]];
    		}
    		ans.insert(t);
    	}
    	// for(int i = 1; i <= n; i++){
    	// 	cout << s[a[i]];
    	// }
    	// cout << '\n';
    	// dbg(ans);
    }while(next_permutation(a.begin() + 1, a.end()));
    cout << ans.size() << '\n';
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