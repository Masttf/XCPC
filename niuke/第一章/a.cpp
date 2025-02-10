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
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    string s; cin >> s;
    string res = "";
    int n = s.size();
    auto get = [&](char x) -> int{
    	if('a' <= x && x <= 'z') return 1;
    	else if('0' <= x && x <= '9')return 2;
    	return 0;
    };
    for(int i = 0; i < n; i++){
    	if(s[i] == '-'){
    		if(i && i + 1 < n && get(s[i - 1]) && (get(s[i - 1]) == get(s[i + 1]))){
    			if(s[i - 1] >= s[i + 1]){
    				res += s[i];
    				continue;
    			}
    			string t = "";
    			char st = s[i - 1] + 1;
    			char ed = s[i + 1] - 1;
    			if(p1 == 2 && (get(s[i - 1]) == 1)){
    				st = st - 'a' + 'A';
    				ed = ed - 'a' + 'A';
    			}
    			for(char j = st; j <= ed; j++){
    				for(int k = 1; k <= p2; k++){
    					t += j;
    				}
    			}
    			if(p3 == 2)reverse(t.begin(), t.end());
    			if(p1 == 3){
    				for(auto &x : t) x = '*';
    			}
    			res += t;
    		}else{
    			res += s[i];
    		}
    	}else{
    		res += s[i];
    	}
    }
    cout << res << '\n';
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