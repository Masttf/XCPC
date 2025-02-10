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
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int ans = 0;
    auto dfs = [&](auto self, int now) -> void{
    	if(now == n + 1){
    		int cnt1 = 0, cnt2 = 0;
    		auto add = [&](int x, int y) -> void{
    			if(s[x] == '1' && s[y] == '0'){
    				cnt1++;
    			}else if(s[x] == '0' && s[y] == '1'){
    				cnt2++;
    			}
    		};
    		auto del = [&](int x, int y) -> void{
    			if(s[x] == '1' && s[y] == '0'){
    				cnt1--;
    			}else if(s[x] == '0' && s[y] == '1'){
    				cnt2--;
    			}
    		};
    		for(int i = 1; i < n; i++){
    			add(i, i + 1);
    		}
    		for(int i = 1; i <= n; i++){

    			if(s[i] == '0'){ // 0 -> 1
    				del(i - 1, i);
    				del(i, i + 1);
    				s[i] = '1';
    				add(i - 1, i);
    				add(i, i + 1);
    				if(cnt1 == cnt2)ans++;
    				del(i - 1, i);
    				del(i, i + 1);
    				s[i] = '0';
    				add(i - 1, i);
    				add(i, i + 1);
    			}else{
    				del(i - 1, i);
    				del(i, i + 1);
    				s[i] = '0';
    				add(i - 1, i);
    				add(i, i + 1);
    				if(cnt1 == cnt2)ans++;
    				del(i - 1, i);
    				del(i, i + 1);
    				s[i] = '1';
    				add(i - 1, i);
    				add(i, i + 1);
    			}
    		}
    		int d = cnt1 - cnt2;
    		if(d == -1){
    			dbg(d);
    			dbg(s);
    		}else if(d == 0){
    			dbg(d);
    			dbg(s);
    		}else if(d == 1){
    			dbg(d);
    			dbg(s);
    		}
    		
    		return ;
    	}
    	if(s[now] != '?'){
    		self(self, now + 1);
    	}else{
    		s[now] = '0';
    		self(self, now + 1);
    		s[now] = '1';
    		self(self, now + 1);
    		s[now] = '?';
    	}
    };
    dfs(dfs, 1);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}